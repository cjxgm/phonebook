// vim: noet ts=4 sw=4 sts=0 fenc=utf8
// Licensed under the MIT License. See COPYING for more details.
// (C) 2014. eXerigumo Clanjor (哆啦比猫/兰威举) <cjxgm@126.com>

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

	string last_theme;
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

