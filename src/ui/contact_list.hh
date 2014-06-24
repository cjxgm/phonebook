// vim: noet ts=4 sw=4 sts=0 fenc=utf8
// Licensed under the MIT License. See COPYING for more details.
// (C) 2014. eXerigumo Clanjor (哆啦比猫/兰威举) <cjxgm@126.com>

#pragma once
#include "gtkmm.hh"
#include "contact.hh"
#include <string>
#include <vector>
using namespace std;

class ContactList : public Gtk::ListBox
{
	Gtk::Label label_empty{};
	Gtk::ListBoxRow* last_row{nullptr};
	Glib::RefPtr<Gtk::SizeGroup> sgroup{};

	string key{};
	bool filter_func(Gtk::ListBoxRow* row);

	Contact* create_contact(const string& name, const string& phone);

	using SignalUpdate = sigc::signal<void>;
	SignalUpdate _signal_update;

public:
	// accessors
	inline SignalUpdate& signal_update() { return _signal_update; }

	ContactList();

	using ListBox::add;	// suppress warnings of hiding virtual function
	void add(const string& name, const string& phone);
	void search(const string& key);	// set search key
};

