#include "main_window.hh"
#include <iostream>
using namespace std;


MainWindow::MainWindow()
{
	//////// create contents ////////
	set_default_size(800, 600);
	set_position(Gtk::WIN_POS_CENTER);
	set_border_width(10);
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

	btn_add.signal_clicked().connect([&]() {
		set_titlebar(ibar);
		ibar.show(sbar.get());
		sbar.set_search_mode(false);
	});

	ibar.signal_add().connect([&](const string& name, const string& phone) {
		set_titlebar(bar);
		cout << "+ " << name << " = " << phone << endl;	// TODO
	});

	ibar.signal_cancel().connect([&]() {
		set_titlebar(bar);
	});

	signal_key_press_event().connect(sigc::mem_fun(*this, &MainWindow::on_window_key_press));

	vbox.pack_start(sbar, false, false, 0);
	sbar.show();

	vbox.pack_start(view);
	view.show();

	add_events(Gdk::KEY_PRESS_MASK);
}

bool MainWindow::on_window_key_press(GdkEventKey* ev)
{
	return sbar.handle_event(ev);
}

