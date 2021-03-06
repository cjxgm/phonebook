// vim: noet ts=4 sw=4 sts=0 fenc=utf8
// Licensed under the MIT License. See COPYING for more details.
// (C) 2014. eXerigumo Clanjor (哆啦比猫/兰威举) <cjxgm@126.com>

#include "ui/gtkmm.hh"
#include "ui/main_window.hh"

int main(int argc, char* argv[])
{
	int fake_argc = 1;
	auto app = Gtk::Application::create(fake_argc, argv);

	MainWindow win{};

	return app->run(win);
}

