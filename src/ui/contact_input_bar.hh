#pragma once
#include "gtkmm.hh"
#include "info_entry.hh"
#include <string>
using namespace std;

class ContactInputBar : public Gtk::HeaderBar
{
	Gtk::Box hbox{Gtk::ORIENTATION_HORIZONTAL, 10};

	Gtk::Button btn_ok{" + "};
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

public:
	// accessors
	inline SignalOk& signal_ok() { return _signal_ok; }
	inline SignalCancel& signal_cancel() { return _signal_cancel; }

	ContactInputBar();

	void show(const string& name = "");	// set focus automatically
};

