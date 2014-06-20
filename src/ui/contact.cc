#include "contact.hh"
#include <iostream>
using namespace std;

Contact::Contact(const string& name, const string& phone)
	: label_name{name}, label_phone{phone}
{
	add(box);
	box.show();
	box.set_border_width(4);

	box.pack_start(label_name);
	label_name.show();

	box.set_center_widget(label_phone);
	label_phone.show();

	box.pack_end(btn_del);
	btn_del.show();
}

