#include "contact_search_bar.hh"
#include <iostream>
using namespace std;

ContactSearchBar::ContactSearchBar()
{
	add(entry);
	entry.show();
	entry.set_size_request(400, -1);
}

