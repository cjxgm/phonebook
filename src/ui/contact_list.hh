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
	vector<Contact> contacts;

public:
	ContactList();

	using ListBox::add;	// suppress warnings of hiding virtual function
	void add(const string& name, const string& phone);
};

