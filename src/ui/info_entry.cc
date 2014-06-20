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

bool InfoEntry::validate(const string& s)
{
	if (_validator) return _validator(s);
	return true;
}

void InfoEntry::theme(const string& name)
{
	auto info_fg = color(name + "_fg_color");
	auto info_bg = color(name + "_bg_color");
	override_symbolic_color("text_color", info_fg);
	override_symbolic_color("bg_color", info_fg);
	override_symbolic_color("base_color", info_bg);
}

InfoEntry::InfoEntry(const string& placeholder)
{
	set_placeholder_text(placeholder);
	reset();

	signal_changed().connect([&]() {
		validate();
	});
}

bool InfoEntry::validate()
{
	if (validate(get_text())) {
		theme("info");
		return true;
	}

	theme("error");
	return false;
}

void InfoEntry::reset()
{
	set_text("");
	theme("info");
}

