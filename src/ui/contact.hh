#pragma once
#include "gtkmm.hh"
#include <string>
#include <iostream>
using namespace std;

class Contact: public Gtk::ListBoxRow
{
	Gtk::Box box{Gtk::ORIENTATION_HORIZONTAL, 10};

	Gtk::Label label_name;
	Gtk::Label label_phone;
	Gtk::Button btn_del{"delete"};

public:
	Contact(const string& name, const string& phone);
};

