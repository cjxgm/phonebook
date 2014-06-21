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
	set_can_focus(false);

	add(box);
	box.show();
	box.set_border_width(4);

	box.pack_start(btn_edit, Gtk::PACK_SHRINK);
	btn_edit.get_style_context()->add_class("default");
	btn_edit.set_can_focus(false);	// make "default" class persistent
	btn_edit.show();

	box.pack_start(label_name, Gtk::PACK_SHRINK);
	label_name.set_markup(markup_format("<b><big>%s</big></b>", name));
	label_name.set_alignment(1, 0.5);
	label_name.show();

	box.pack_start(label_phone, Gtk::PACK_EXPAND_WIDGET);
	label_phone.set_markup(markup_format("<span color='#bbb' font_weight='bold'>%s</span>", phone));
	label_phone.set_alignment(0, 0.6);
	label_phone.show();

	box.pack_start(btn_del, Gtk::PACK_SHRINK);
	btn_del.show();
	btn_del.get_style_context()->add_class("destructive-action");


	btn_edit.signal_clicked().connect([&]() {
		// TODO
	});

	btn_del.signal_clicked().connect([&]() {
		// TODO
	});
}

