// vim: noet ts=4 sw=4 sts=0 fenc=utf8
// Licensed under the MIT License. See COPYING for more details.
// (C) 2014. eXerigumo Clanjor (哆啦比猫/兰威举) <cjxgm@126.com>

#pragma once
#include "gtkmm.hh"
#include <string>
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

