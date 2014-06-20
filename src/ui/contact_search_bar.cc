#include "contact_search_bar.hh"
#include <iostream>
using namespace std;

ContactSearchBar::ContactSearchBar()
{
	hbox.set_halign(Gtk::ALIGN_CENTER);
	hbox.show();

	hbox.pack_start(entry, false, false, 0);
	entry.show();

	set_show_close_button(true);
	connect_entry(entry);
	add(hbox);
}

