// vim: noet ts=4 sw=4 sts=0 fenc=utf8
// Licensed under the MIT License. See COPYING for more details.
// (C) 2014. eXerigumo Clanjor (哆啦比猫/兰威举) <cjxgm@126.com>

#include "contact.hh"
#include "../nde.hh"
#include <regex>
#include <cstring>
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

Contact::Contact(const string& name, const string& phone, SizeGroupPtr sgroup)
{
	set(name, phone);
	set_can_focus(false);

	add(stack);
	stack.set_border_width(0);
	stack.show();

	stack.add(empty, "empty");
	empty.show();

	stack.add(box, "main");
	box.set_border_width(4);
	box.show();


	box.pack_start(btn_edit, Gtk::PACK_SHRINK);
	btn_edit.get_style_context()->add_class("default");
	btn_edit.set_can_focus(false);	// make "default" class persistent
	btn_edit.show();

	box.pack_start(box_info, Gtk::PACK_EXPAND_PADDING);
	box_info.show();

	box.pack_start(btn_remove, Gtk::PACK_SHRINK);
	btn_remove.get_style_context()->add_class("destructive-action");
	btn_remove.show();


	box_info.pack_start(label_name, Gtk::PACK_SHRINK);
	sgroup->add_widget(label_name);
	label_name.set_alignment(1, 0.5);
	label_name.show();

	box_info.pack_start(label_phone, Gtk::PACK_SHRINK);
	sgroup->add_widget(label_phone);
	label_phone.set_alignment(0, 0.6);
	label_phone.show();


	stack.add(ibar, "edit");
	ibar.show();


	signal_map().connect([&]() {
		stack.set_transition_type(Gtk::STACK_TRANSITION_TYPE_OVER_DOWN);
		stack.set_visible_child("main");
	});

	btn_edit.signal_clicked().connect([&]() {
		stack.set_transition_type(Gtk::STACK_TRANSITION_TYPE_OVER_LEFT);
		stack.set_visible_child("edit");
		ibar.grab_focus(label_name.get_text(), label_phone.get_text());
	});

	btn_remove.signal_clicked().connect([&]() {
		_signal_remove.emit();
	});

	ibar.signal_ok().connect([&](const string& name, const string& phone) {
		nde::action::edit(size_t(get_index()), name, phone);
		_signal_update.emit();
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


// case-insensitive find
static inline bool case_find(const string& haystack, const string& needle)
{
	return strcasestr(haystack.c_str(), needle.c_str());
}

bool Contact::find(const string& key)
{
	string name = label_name.get_text();
	string phone = label_phone.get_text();

	if (case_find( name, key)) return true;
	if (case_find(phone, key)) return true;

	string k = regex_replace(key, regex{"\\s+"}, "");
	name = regex_replace(name, regex{"\\s+"}, "");
	if (case_find(name, k)) return true;

	k = regex_replace(k, regex{"^\\+"}, "");
	phone = regex_replace(phone, regex{"^\\+"}, "");
	phone = regex_replace(phone, regex{"\\s+"}, "");
	if (case_find(phone, k)) return true;

	return false;
}

