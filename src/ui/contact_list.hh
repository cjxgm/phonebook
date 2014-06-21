#pragma once
#include "gtkmm.hh"
#include "contact.hh"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class ContactList : public Gtk::ListBox
{
	Gtk::Label label_empty{"click \"+\" to add a contact."};
	Gtk::ListBoxRow* last_row{nullptr};

public:
	ContactList();

	using ListBox::add;	// suppress warnings of hiding virtual function
	void add(const string& name, const string& phone);
};

