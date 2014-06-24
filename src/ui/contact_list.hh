#pragma once
#include "gtkmm.hh"
#include "contact.hh"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class ContactList : public Gtk::ListBox
{
	Gtk::Label label_empty{};
	Gtk::ListBoxRow* last_row{nullptr};
	Glib::RefPtr<Gtk::SizeGroup> sgroup{};

	string key{};
	bool filter_func(Gtk::ListBoxRow* row);

	Contact* create_contact(const string& name, const string& phone);

public:
	ContactList();

	using ListBox::add;	// suppress warnings of hiding virtual function
	void add(const string& name, const string& phone);
	void search(const string& key);	// set search key
};

