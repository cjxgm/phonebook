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
		set_titlebar(contact_ibar);
		contact_ibar.show();
	});

	contact_ibar.signal_add().connect([&](const string& name, const string& phone) {
		set_titlebar(bar);
		cout << "+ " << name << " = " << phone << endl;	// TODO
	});

	contact_ibar.signal_cancel().connect([&]() {
		set_titlebar(bar);
	});


	//vbox.pack_start(contact_ibar, false, false, 0);
	vbox.pack_start(contact_view);
	contact_view.show();
}

