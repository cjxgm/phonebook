#pragma once
#include "gtkmm.hh"
#include <string>
using namespace std;

class MainWindow : public Gtk::Window
{
	Gtk::HeaderBar bar{};
	Gtk::Button btn_prev{"<-"};
	Gtk::Button btn_next{"->"};
	Gtk::ToggleButton btn_color{"color"};

public:
	MainWindow();
};

