#pragma once
#include "gtkmm.hh"
#include "contact_input_bar.hh"
#include <string>
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
	Gtk::Button btn_remove{" remove "};

	using SizeGroupPtr = Glib::RefPtr<Gtk::SizeGroup>;
	using SignalRemove = sigc::signal<void>;
	using SignalUpdate = sigc::signal<void>;
	// void signal_remove_callback();
	SignalRemove _signal_remove;
	SignalUpdate _signal_update;

public:
	// accessors
	inline SignalRemove& signal_remove() { return _signal_remove; }
	inline SignalUpdate& signal_update() { return _signal_update; }

	Contact(const string& name, const string& phone, SizeGroupPtr sgroup);
	void set(const string& name, const string& phone);
	bool find(const string& key);	// for filtering.
};

