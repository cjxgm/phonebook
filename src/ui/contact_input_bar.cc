#include "contact_input_bar.hh"
#include <iostream>
using namespace std;


ContactInputBar::ContactInputBar()
{
	add(hbox);
	hbox.show();

	auto context = get_style_context();
	context->add_class("selection-mode");

	hbox.pack_start(label_name);
	hbox.pack_start(entry_name);
	hbox.pack_start(label_phone);
	hbox.pack_start(entry_phone);
	label_name.show();
	entry_name.show();
	label_phone.show();
	entry_phone.show();

	entry_name.validator([&](const string& s) {
		return (s != "");
	});

	/*
	signal_response().connect([&](int response_id) {
		switch (response_id) {
			case Gtk::RESPONSE_CLOSE: hide(); break;
		}
	});
	*/
}

