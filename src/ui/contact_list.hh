#pragma once
#include "gtkmm.hh"
#include <string>
#include <iostream>
using namespace std;

class ContactList : public Gtk::ListBox
{
	Gtk::Label label_empty{"click \"+\" to add a contact."};

public:
	ContactList();
};

