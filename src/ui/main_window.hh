// vim: noet ts=4 sw=4 sts=0 fenc=utf8
// Licensed under the MIT License. See COPYING for more details.
// (C) 2014. eXerigumo Clanjor (哆啦比猫/兰威举) <cjxgm@126.com>

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
	Gtk::Button btn_add{};
	Gtk::Button btn_snapshot{};

	Gtk::Box box_undo_redo{Gtk::ORIENTATION_HORIZONTAL, 0};
	Gtk::Button btn_undo{};
	Gtk::Button btn_redo{};

	Gtk::Box vbox{Gtk::ORIENTATION_VERTICAL, 0};
	Gtk::ScrolledWindow scrolled{};

	ContactInputBar ibar{};
	ContactSearchBar sbar{};
	ContactList clist{};

public:
	MainWindow();

	bool on_key_press_event(GdkEventKey* ev);
};

