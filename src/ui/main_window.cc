#include "main_window.hh"
#include "../nde.hh"
#include <iostream>
using namespace std;


MainWindow::MainWindow()
{
	//////// create contents ////////
	set_default_size(640, 600);
	set_position(Gtk::WIN_POS_CENTER);

	add(vbox);
	vbox.show();

	// headerbar and its friends
	set_titlebar(bar);
	bar.set_show_close_button();
	bar.set_title("phonebook");
	bar.set_has_subtitle(false);
	bar.show();

	bar.pack_start(btn_add);
	btn_add.set_image_from_icon_name("list-add");
	btn_add.set_tooltip_text("add new contact.");
	btn_add.show();

	bar.pack_start(btn_snapshot);
	btn_snapshot.set_image_from_icon_name("media-record");
	btn_snapshot.set_tooltip_text(
			"snapshot the current phonebook in order to reduce disk usage.\n"
			"editing-history will be removed.");
	btn_snapshot.show();

	bar.pack_end(box_undo_redo);
	box_undo_redo.show();

	box_undo_redo.pack_end(btn_redo);
	btn_redo.set_image_from_icon_name("edit-redo");
	btn_redo.set_tooltip_text("redo last undid operation.");
	btn_redo.set_sensitive(false);
	btn_redo.show();

	box_undo_redo.pack_end(btn_undo);
	btn_undo.set_image_from_icon_name("edit-undo");
	btn_undo.set_tooltip_text("undo last operation.");
	btn_undo.set_sensitive(false);
	btn_undo.show();

	vbox.pack_start(sbar, false, false, 0);
	sbar.show();

	vbox.pack_start(scrolled);
	scrolled.set_policy(Gtk::POLICY_NEVER, Gtk::POLICY_AUTOMATIC);
	scrolled.show();

	scrolled.add(clist);
	clist.show();


	add_events(Gdk::KEY_PRESS_MASK);


	btn_add.signal_clicked().connect([&]() {
		set_titlebar(ibar);
		ibar.show();
		ibar.grab_focus(sbar.get());
		sbar.set_search_mode(false);
	});

	btn_snapshot.signal_clicked().connect([&]() {
		nde::project::instance()->snapshot();
		clist.signal_update().emit();
	});

	ibar.signal_ok().connect([&](const string& name, const string& phone) {
		ibar.hide();
		set_titlebar(bar);
		clist.add(name, phone);
		cout << "+ " << name << " = " << phone << endl;	// TODO
	});

	ibar.signal_cancel().connect([&]() {
		ibar.hide();
		set_titlebar(bar);
	});

	sbar.signal_search().connect([&](const string& key) {
		clist.search(key);
	});

	clist.signal_update().connect([&]() {
		auto proj = nde::project::instance();
		btn_undo.set_sensitive(proj->undoable());
		btn_redo.set_sensitive(proj->redoable());
	});

	btn_undo.signal_clicked().connect([&]() {
		nde::action::undo();
		clist.signal_update().emit();
	});

	btn_redo.signal_clicked().connect([&]() {
		nde::action::redo();
		clist.signal_update().emit();
	});
}

bool MainWindow::on_key_press_event(GdkEventKey* ev)
{
	if (Window::on_key_press_event(ev))
		return true;
	return sbar.handle_event(ev);
}

