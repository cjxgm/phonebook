#pragma once
#include "gtkmm.hh"
#include "contact_input_bar.hh"
#include <string>
using namespace std;

class MainWindow : public Gtk::Window
{
	Gtk::HeaderBar bar{};
	Gtk::Button btn_add{" + "};

	Gtk::Box vbox{Gtk::ORIENTATION_VERTICAL, 0};
	ContactInputBar contact_ibar{};

public:
	MainWindow();
};

