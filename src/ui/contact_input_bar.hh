// vim: noet ts=4 sw=4 sts=0 fenc=utf8
// Licensed under the MIT License. See COPYING for more details.
// (C) 2014. eXerigumo Clanjor (哆啦比猫/兰威举) <cjxgm@126.com>

#pragma once
#include "gtkmm.hh"
#include "info_entry.hh"
#include <string>
using namespace std;

class ContactInputBar : public Gtk::HeaderBar
{
	Gtk::Box hbox{Gtk::ORIENTATION_HORIZONTAL, 10};

	Gtk::Button btn_ok;	// initialized later in constructor
	Gtk::Button btn_cancel{" cancel "};

	Gtk::Label label_name{"name:"};
	Gtk::Label label_phone{"phone:"};

	InfoEntry entry_name{"name"};
	InfoEntry entry_phone{"phone number"};

	// void signal_add_callback(const string& name, const string& phone);
	using SignalOk = sigc::signal<void, const string&, const string&>;
	// void signal_cancel_callback();
	using SignalCancel = sigc::signal<void>;

	SignalOk _signal_ok;
	SignalCancel _signal_cancel;

	void confirm();
	void cancel();

public:
	// accessors
	inline SignalOk& signal_ok() { return _signal_ok; }
	inline SignalCancel& signal_cancel() { return _signal_cancel; }

	ContactInputBar(const string& ok_text = " + ");

	// will set entry's text by the way
	void grab_focus(const string& name = "", const string& phone="");
};

