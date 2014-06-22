#pragma once
#include "gtkmm.hh"
#include "contact_input_bar.hh"
#include <string>
#include <iostream>
using namespace std;

class Contact: public Gtk::ListBoxRow
{
	Gtk::Stack stack{};
	Gtk::Box box{Gtk::ORIENTATION_HORIZONTAL, 10};
	Gtk::Box box_info{Gtk::ORIENTATION_HORIZONTAL, 10};
	ContactInputBar ibar{" edit "};

	Gtk::Label label_name;
	Gtk::Label label_phone;
	Gtk::Button btn_edit{" edit "};
	Gtk::Button btn_del{" delete "};

	using SizeGroupPtr = Glib::RefPtr<Gtk::SizeGroup>;
	using SignalDelete = sigc::signal<void>;
	// void signal_delete_callback();
	SignalDelete _signal_delete;

public:
	// accessors
	inline SignalDelete& signal_delete() { return _signal_delete; }

	Contact(const string& name, const string& phone, SizeGroupPtr sgroup);
	void set(const string& name, const string& phone);
};

