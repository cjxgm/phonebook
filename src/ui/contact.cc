#include "contact.hh"
#include <iostream>
using namespace std;

// surround content with a tag
//
// format: something like "<b>%s</b>"
// content: will be escaped
static string markup_format(const string& format, const string& content)
{
	auto raw_markup = g_markup_printf_escaped(format.c_str(), content.c_str());
	string markup{raw_markup};
	g_free(raw_markup);
	return markup;
}

Contact::Contact(const string& name, const string& phone)
{
	add(box);
	box.show();
	box.set_border_width(4);

	box.pack_start(label_name, Gtk::PACK_SHRINK);
	label_name.show();
	label_name.set_markup(markup_format("<big>%s</big>", name));

	box.pack_start(label_phone, Gtk::PACK_EXPAND_WIDGET);
	label_phone.show();
	label_phone.set_markup(markup_format("<span color='#888' font_weight='bold'>%s</span>", phone));

	box.pack_start(btn_del, Gtk::PACK_SHRINK);
	btn_del.show();
}

