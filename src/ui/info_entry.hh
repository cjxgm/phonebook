#pragma once
#include "gtkmm.hh"
#include <string>
using namespace std;

class InfoEntry : public Gtk::Entry
{
	Gdk::RGBA color(const string& name);

public:
	InfoEntry();
};

