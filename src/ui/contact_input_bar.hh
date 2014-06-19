#pragma once
#include "gtkmm.hh"
#include "info_entry.hh"
#include <string>
using namespace std;

class ContactInputBar : public Gtk::InfoBar
{
	Gtk::Box hbox{Gtk::ORIENTATION_HORIZONTAL, 0};

	Gtk::Label label_name{"name:"};
	Gtk::Label label_phone{"phone:"};

	InfoEntry entry_name{};
	InfoEntry entry_phone{};

public:
	ContactInputBar();
};

