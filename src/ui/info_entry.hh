#pragma once
#include "gtkmm.hh"
#include <string>
#include <functional>
using namespace std;

class InfoEntry : public Gtk::Entry
{
	using Validator = function<bool(const string&)>;
	using SignalCancel = sigc::signal<void>;

	Validator _validator;
	SignalCancel _signal_cancel;

	void theme(const string& name);
	bool validate(const string& s);

public:
	// accessors
	inline SignalCancel& signal_cancel() { return _signal_cancel; }

	InfoEntry(const string& placeholder="");
	void validator(Validator _validator) { this->_validator = _validator; }
	bool validate();
	void reset();
	bool on_key_press_event(GdkEventKey* ev);
};

