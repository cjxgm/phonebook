#include "contact_list.hh"
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
	set_placeholder(label_empty);
	label_empty.show();

	sgroup = Gtk::SizeGroup::create(Gtk::SIZE_GROUP_HORIZONTAL);

	signal_row_activated().connect([&](Gtk::ListBoxRow* row) {
		if (row == last_row) {
			unselect_row();
			last_row = nullptr;
		}
		else last_row = row;
	});

	set_filter_func(mem_fun(*this, &ContactList::filter_func));
}

void ContactList::add(const string& name, const string& phone)
{
	Contact* con = new Contact{name, phone, sgroup};
	con->show();
	append(*con);

	con->signal_delete().connect([=]() {
		delete con;
	});
}

void ContactList::search(const string& key)
{
	this->key = key;
	invalidate_filter();
}

