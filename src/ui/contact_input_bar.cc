#include "contact_input_bar.hh"
#include <iostream>
#include <regex>
using namespace std;


void ContactInputBar::confirm()
{
	if (!entry_name.validate()) return entry_name.grab_focus();
	if (!entry_phone.validate()) return entry_phone.grab_focus();
	string name = entry_name.get_text();
	string phone = entry_phone.get_text();
	entry_name.reset();
	entry_phone.reset();
	hide();
	_signal_ok.emit(name, phone);
}

ContactInputBar::ContactInputBar()
{
	set_has_subtitle(false);
	pack_start(hbox);
	hbox.show();

	auto context = get_style_context();
	context->add_class("selection-mode");

	hbox.pack_start(btn_ok);
	btn_ok.show();

	pack_end(btn_cancel);
	btn_cancel.show();

	hbox.pack_start(label_name);
	hbox.pack_start(entry_name);
	hbox.pack_start(label_phone);
	hbox.pack_start(entry_phone);
	label_name.show();
	entry_name.show();
	label_phone.show();
	entry_phone.show();

	entry_name.validator([&](const string& s) {
		string name{s};
		name = regex_replace(name, regex{"\\s+"}, "");
		return (name != "");
	});

	entry_phone.validator([&](const string& s) {
		string phone{s};
		if (regex_match(phone, regex{".*\\s"})) return false;
		if (regex_match(phone, regex{"\\s.*"})) return false;
		if (regex_match(phone, regex{".*\\s{2,}.*"})) return false;
		phone = regex_replace(phone, regex{"^\\+"}, "");
		phone = regex_replace(phone, regex{"\\s+"}, "");
		return bool(regex_match(phone, regex{"\\d+"}));
	});

	btn_ok.signal_clicked().connect([&]() {
		confirm();
	});

	btn_cancel.signal_clicked().connect([&]() {
		entry_name.reset();
		entry_phone.reset();
		hide();
		_signal_cancel.emit();
	});

	entry_name.signal_activate().connect([&]() {
		confirm();
	});

	entry_phone.signal_activate().connect([&]() {
		confirm();
	});
}

void ContactInputBar::show(const string& name)
{
	HeaderBar::show();
	if (name == "") entry_name.grab_focus();
	else {
		entry_name.set_text(name);
		entry_phone.grab_focus();
	}
}

