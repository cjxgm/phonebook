#pragma once
#include "gtkmm.hh"
#include "contact_input_bar.hh"
#include "contact_view.hh"
#include "contact_search_bar.hh"
#include <string>
using namespace std;

class MainWindow : public Gtk::Window
{
	Gtk::HeaderBar bar{};
	Gtk::Button btn_add{" + "};

	Gtk::Box vbox{Gtk::ORIENTATION_VERTICAL, 0};
	ContactInputBar ibar{};
	ContactSearchBar sbar{};
	ContactView view{};

public:
	MainWindow();

	bool on_window_key_press(GdkEventKey* ev);
};

