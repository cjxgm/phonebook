#include "info_entry.hh"
#include <iostream>
using namespace std;


bool InfoEntry::validate(const string& s)
{
	if (_validator) return _validator(s);
	return true;
}

void InfoEntry::theme(const string& name)
{
	get_style_context()->add_class(name);
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

bool InfoEntry::on_key_press_event(GdkEventKey* ev)
{
	if (ev->keyval == GDK_KEY_Escape) {
		_signal_cancel.emit();
		return true;
	}
	return Entry::on_key_press_event(ev);
}

