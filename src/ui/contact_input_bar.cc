#include "contact_input_bar.hh"
#include <iostream>
using namespace std;


ContactInputBar::ContactInputBar()
{
	set_message_type(Gtk::MESSAGE_INFO);
	set_show_close_button();
	dynamic_cast<Gtk::Box*>(get_content_area())->pack_start(hbox, false, false, 0);
	hbox.show();

	hbox.pack_start(label_name);
	hbox.pack_start(entry_name);
	hbox.pack_start(label_phone);
	hbox.pack_start(entry_phone);
	label_name.show();
	entry_name.show();
	label_phone.show();
	entry_phone.show();

	signal_response().connect([&](int response_id) {
		switch (response_id) {
			case Gtk::RESPONSE_CLOSE: hide(); break;
		}
	});
}

