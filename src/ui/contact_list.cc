#include "contact_list.hh"
#include "../nde.hh"

bool ContactList::filter_func(Gtk::ListBoxRow* row)
{
	auto contact = dynamic_cast<Contact*>(row);
	return contact->find(key);
}

Contact* ContactList::create_contact(const string& name, const string& phone)
{
	auto con = new Contact{name, phone, sgroup};
	con->show();

	con->signal_remove().connect([=]() {
		nde::action::remove(size_t(con->get_index()));
		_signal_update.emit();
	});

	con->signal_update().connect(_signal_update);

	return con;
}

ContactList::ContactList()
{
	set_selection_mode(Gtk::SELECTION_NONE);
	set_filter_func(mem_fun(*this, &ContactList::filter_func));

	set_placeholder(label_empty);
	label_empty.set_markup("<span color='#aaa'>click </span><big><b><span color='#fff'>+</span></b></big><span color='#aaa'> to add a contact.</span>");
	label_empty.show();

	sgroup = Gtk::SizeGroup::create(Gtk::SIZE_GROUP_HORIZONTAL);

	signal_row_activated().connect([&](Gtk::ListBoxRow* row) {
		set_selection_mode(Gtk::SELECTION_SINGLE);

		if (row == last_row) {
			unselect_row();
			last_row = nullptr;
		}
		else {
			select_row(*row);
			last_row = row;
		}
	});

	signal_realize().connect([&]() {
		nde::init();
		_signal_update.emit();
	});

	// register nde callbacks
	{
		using namespace nde::action;

		Create::undo_cb = [&]() {
			size_t pos = get_children().size() - 1;
			delete get_row_at_index(pos);
		};

		Create::invoke_cb = [&](const string& name, const string& phone) {
			auto con = create_contact(name, phone);
			append(*con);
		};


		Remove::undo_cb = [&](size_t pos, const string& name, const string& phone) {
			auto con = create_contact(name, phone);
			insert(*con, pos);
		};

		Remove::invoke_cb = [&](size_t pos) {
			delete get_row_at_index(pos);
		};


		Edit::undo_cb = [&](size_t pos, const string& name, const string& phone) {
			auto row = get_row_at_index(pos);
			auto con = dynamic_cast<Contact*>(row);
			con->set(name, phone);
		};

		Edit::invoke_cb = Edit::undo_cb;


		nde::project::snapshot::load_cb = Create::invoke_cb;
	}
}

void ContactList::add(const string& name, const string& phone)
{
	nde::action::create(name, phone);
	_signal_update.emit();
}

void ContactList::search(const string& key)
{
	this->key = key;
	invalidate_filter();
}

