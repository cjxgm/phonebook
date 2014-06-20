#pragma once
#include "gtkmm.hh"
#include <string>
#include <iostream>
using namespace std;

class ContactSearchBar : public Gtk::SearchBar
{
	Gtk::Box hbox{Gtk::ORIENTATION_HORIZONTAL, 10};
	Gtk::SearchEntry entry{};

public:
	ContactSearchBar();
};

