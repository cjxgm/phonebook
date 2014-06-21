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
	set(name, phone);
	set_can_focus(false);

	add(stack);
	stack.set_border_width(0);
	stack.show();

	stack.add(box, "main");
	box.set_border_width(4);
	box.show();

	box.pack_start(btn_edit, Gtk::PACK_SHRINK);
	btn_edit.get_style_context()->add_class("default");
	btn_edit.set_can_focus(false);	// make "default" class persistent
	btn_edit.show();

	box.pack_start(label_name, Gtk::PACK_SHRINK);
	label_name.set_alignment(1, 0.5);
	label_name.show();

	box.pack_start(label_phone, Gtk::PACK_EXPAND_WIDGET);
	label_phone.set_alignment(0, 0.6);
	label_phone.show();

	box.pack_start(btn_del, Gtk::PACK_SHRINK);
	btn_del.show();
	btn_del.get_style_context()->add_class("destructive-action");

	stack.add(ibar, "edit");
	ibar.show();

	btn_edit.signal_clicked().connect([&]() {
		stack.set_transition_type(Gtk::STACK_TRANSITION_TYPE_OVER_LEFT);
		stack.set_visible_child("edit");
		ibar.grab_focus(label_name.get_text(), label_phone.get_text());
	});

	btn_del.signal_clicked().connect([&]() {
		// TODO
	});

	ibar.signal_ok().connect([&](const string& name, const string& phone) {
		set(name, phone);
		stack.set_transition_type(Gtk::STACK_TRANSITION_TYPE_UNDER_DOWN);
		stack.set_visible_child("main");
	});

	ibar.signal_cancel().connect([&]() {
		stack.set_transition_type(Gtk::STACK_TRANSITION_TYPE_CROSSFADE);
		stack.set_visible_child("main");
	});
}

void Contact::set(const string& name, const string& phone)
{
	label_name.set_markup(markup_format("<b><big>%s</big></b>", name));
	label_phone.set_markup(markup_format("<span color='#bbb' font_weight='bold'>%s</span>", phone));
}

