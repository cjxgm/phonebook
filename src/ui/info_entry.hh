#pragma once
#include "gtkmm.hh"
#include <string>
#include <functional>
using namespace std;

class InfoEntry : public Gtk::Entry
{
	using Validator = function<bool(const string&)>;

	Validator _validator;

	Gdk::RGBA color(const string& name);
	void theme(const string& name);
	bool validate(const string& s);

public:
	InfoEntry(const string& placeholder="");
	void validator(Validator _validator) { this->_validator = _validator; }
	bool validate();
};

