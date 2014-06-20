#include "contact_list.hh"
#include <iostream>
using namespace std;

ContactList::ContactList()
{
	set_placeholder(label_empty);
	label_empty.show();
}

void ContactList::add(const string& name, const string& phone)
{
	Contact* con = new Contact{name, phone};
	con->show();
	append(*con);
}

