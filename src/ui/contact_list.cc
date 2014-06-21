#include "contact_list.hh"
#include <iostream>
using namespace std;

ContactList::ContactList()
{
	set_selection_mode(Gtk::SELECTION_SINGLE);
	set_placeholder(label_empty);
	label_empty.show();

	signal_row_activated().connect([&](Gtk::ListBoxRow* row) {
		if (row == last_row) {
			unselect_row();
			last_row = nullptr;
		}
		else last_row = row;
	});
}

void ContactList::add(const string& name, const string& phone)
{
	Contact* con = new Contact{name, phone};
	con->show();
	append(*con);
}

