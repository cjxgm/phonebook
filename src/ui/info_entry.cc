#include "info_entry.hh"
#include <iostream>
using namespace std;


Gdk::RGBA InfoEntry::color(const string& name)
{
	auto style = get_style_context();
	Gdk::RGBA clr;
	style->lookup_color(name, clr);
	return clr;
}

InfoEntry::InfoEntry()
{
	override_color(color("info_fg_color"));
	override_background_color(color("info_bg_color"));
}

