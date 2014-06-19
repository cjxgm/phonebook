#include "ui/gtkmm.hh"
#include "ui/main_window.hh"

int main(int argc, char* argv[])
{
	int fake_argc = 1;
	auto app = Gtk::Application::create(fake_argc, argv);

	MainWindow win{};

	return app->run(win);
}

