#include "main_window.hh"
#include <iostream>
using namespace std;


MainWindow::MainWindow()
{
	//////// create contents ////////
	set_default_size(800, 600);
	set_position(Gtk::WIN_POS_CENTER);

	// headerbar and its friends
	set_titlebar(bar);
	bar.set_show_close_button();
	bar.set_title("click on the image to copy color info");
	bar.set_subtitle("move your mouse on the image to show color info");
	bar.show();

	bar.pack_start(btn_prev);
	btn_prev.show();

	bar.pack_start(btn_next);
	btn_next.show();

	bar.pack_start(btn_color);
	btn_color.set_active();
	btn_color.show();
}

