#pragma once
#include "gtkmm.hh"
#include <string>
#include <iostream>
using namespace std;

class ContactList : public Gtk::TreeView
{
	struct Record : public Gtk::TreeModel::ColumnRecord
	{
		Gtk::TreeModelColumn<Glib::ustring> name;
		Gtk::TreeModelColumn<Glib::ustring> phone;

		Record()
		{
			add(name);
			add(phone);
		}
	};

	Record record;

public:
	ContactList()
	{
		auto store = Gtk::ListStore::create(record);
		set_model(store);
		set_reorderable();

		auto row = *store->append();
		row[record.name] = "hello";
		row[record.phone] = "12345";

		row = *store->append();
		row[record.name] = "world";
		row[record.phone] = "54321";

		append_column_editable("name", record.name);
		append_column_editable("phone", record.phone);

		store->signal_row_changed().connect([&](const Gtk::ListStore::Path& path, const Gtk::TreeIter& text) {
			//cerr << path << " = " << text << endl;
		});

		auto ren = dynamic_cast<Gtk::CellRendererText*>(get_column_cell_renderer(1));
		ren->signal_edited().connect([&](const Glib::ustring& path, const Glib::ustring& text) {
			cerr << path << " = " << text << endl;
		});
	}
};

