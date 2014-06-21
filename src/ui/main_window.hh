#pragma once
#include "gtkmm.hh"
#include "contact_input_bar.hh"
#include "contact_list.hh"
#include "contact_search_bar.hh"
#include <string>
using namespace std;

class MainWindow : public Gtk::Window
{
	Gtk::HeaderBar bar{};
	Gtk::Button btn_add{" + "};

	Gtk::Box vbox{Gtk::ORIENTATION_VERTICAL, 0};
	Gtk::ScrolledWindow scrolled{};

	ContactInputBar ibar{};
	ContactSearchBar sbar{};
	ContactList clist{};

public:
	MainWindow();

	bool on_key_press_event(GdkEventKey* ev);
};

