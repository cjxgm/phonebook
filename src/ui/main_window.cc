#include "main_window.hh"
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
	btn_add.show();

	vbox.pack_start(sbar, false, false, 0);
	sbar.show();

	vbox.pack_start(scrolled);
	scrolled.set_policy(Gtk::POLICY_NEVER, Gtk::POLICY_AUTOMATIC);
	scrolled.show();

	scrolled.add(clist);
	clist.show();


	btn_add.signal_clicked().connect([&]() {
		set_titlebar(ibar);
		ibar.show();
		ibar.grab_focus(sbar.get());
		sbar.set_search_mode(false);
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

	add_events(Gdk::KEY_PRESS_MASK);
}

bool MainWindow::on_key_press_event(GdkEventKey* ev)
{
	if (Window::on_key_press_event(ev))
		return true;
	return sbar.handle_event(ev);
}

