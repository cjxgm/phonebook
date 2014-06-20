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
	static string last_name;
	auto context = get_style_context();
	context->remove_class(last_name);
	context->add_class(name);
	last_name = name;
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

