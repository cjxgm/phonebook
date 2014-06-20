#pragma once
#include "gtkmm.hh"
#include <string>
#include <iostream>
using namespace std;

class ContactSearchBar : public Gtk::SearchBar
{
	Gtk::SearchEntry entry{};

public:
	ContactSearchBar();
	inline string get() { return entry.get_text(); }
	//decltype(entry.signal_search_changed()) signal_search_changed() { return entry.signal_search_changed(); }
};

