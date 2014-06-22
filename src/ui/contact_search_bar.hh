#pragma once
#include "gtkmm.hh"
#include <string>
#include <iostream>
using namespace std;

class ContactSearchBar : public Gtk::SearchBar
{
	Gtk::SearchEntry entry{};

	using SignalSearch = sigc::signal<void, const string&>;
	// void signal_search_callback(const string& key);
	SignalSearch _signal_search;

public:
	// accessors
	inline SignalSearch& signal_search() { return _signal_search; }

	ContactSearchBar();
	inline string get() { return entry.get_text(); }
};

