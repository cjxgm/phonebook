#include "contact_list.hh"
#include "../nde.hh"
#include <iostream>
using namespace std;

bool ContactList::filter_func(Gtk::ListBoxRow* row)
{
	auto contact = dynamic_cast<Contact*>(row);
	return contact->find(key);
}

ContactList::ContactList()
{
	set_selection_mode(Gtk::SELECTION_SINGLE);
	set_filter_func(mem_fun(*this, &ContactList::filter_func));

	set_placeholder(label_empty);
	label_empty.set_markup("<span color='#aaa'>click </span><big><b><span color='#fff'>+</span></b></big><span color='#aaa'> to add a contact.</span>");
	label_empty.show();

	sgroup = Gtk::SizeGroup::create(Gtk::SIZE_GROUP_HORIZONTAL);

	signal_row_activated().connect([&](Gtk::ListBoxRow* row) {
		if (row == last_row) {
			unselect_row();
			last_row = nullptr;
		}
		else last_row = row;
	});

	signal_map().connect([&]() {
		nde::init();
	});

	// register nde callbacks
	{
		using namespace nde::action;

		Create::undo_cb = [&]() {
		};

		Create::invoke_cb = [&](const string& name, const string& phone) {
			cout << "invoked create: " << name << "    " << phone << endl;
		};

		Remove::undo_cb = [&](size_t pos, const string& name, const string& phone) {
		};

		Remove::invoke_cb = [&](size_t pos) {
			cout << "invoked remove: " << pos << endl;
		};
	}
}

void ContactList::add(const string& name, const string& phone)
{
	nde::action::create(name, phone);
	Contact* con = new Contact{name, phone, sgroup};
	con->show();
	append(*con);

	con->signal_remove().connect([=]() {
		nde::action::remove(size_t(con->get_index()));
		delete con;
	});
}

void ContactList::search(const string& key)
{
	this->key = key;
	invalidate_filter();
}

