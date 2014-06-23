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

	Gtk::Label empty;

	Gtk::Label label_name;
	Gtk::Label label_phone;
	Gtk::Button btn_edit{" edit "};
	Gtk::Button btn_del{" remove "};

	using SizeGroupPtr = Glib::RefPtr<Gtk::SizeGroup>;
	using SignalRemove = sigc::signal<void>;
	// void signal_remove_callback();
	SignalRemove _signal_remove;

public:
	// accessors
	inline SignalRemove& signal_remove() { return _signal_remove; }

	Contact(const string& name, const string& phone, SizeGroupPtr sgroup);
	void set(const string& name, const string& phone);
	bool find(const string& key);	// for filtering.
};

