// vim: noet ts=4 sw=4 sts=0 fenc=utf8
// Licensed under the MIT License. See COPYING for more details.
// (C) 2014. eXerigumo Clanjor (哆啦比猫/兰威举) <cjxgm@126.com>

#include "contact_search_bar.hh"

ContactSearchBar::ContactSearchBar()
{
	set_show_close_button();

	add(entry);
	entry.show();
	entry.set_size_request(400, -1);

	entry.signal_changed().connect([&]() {
		_signal_search.emit(entry.get_text());
	});
}

