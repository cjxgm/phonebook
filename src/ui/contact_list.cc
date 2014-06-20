#include "contact_list.hh"
#include <iostream>
using namespace std;

ContactList::ContactList()
{
	set_placeholder(label_empty);
	label_empty.show();
}

