// vim: noet ts=4 sw=4 sts=0 fenc=utf8
// Licensed under the MIT License. See COPYING for more details.
// (C) 2014. eXerigumo Clanjor (哆啦比猫/兰威举) <cjxgm@126.com>

#pragma once
#include "type.hh"
#include "../project/instance.hh"

namespace nde
{
	namespace action
	{
		bool read(project::File& f)
		{
			string name = f.atom();
			if (!f) return false;

			auto action = factory.make(name);
			action->read(f);
			project::instance()->append(action, false);

			return true;
		}

		void write(project::File& f, Type* action)
		{
			action->write(f);
			f.eol();
			f.flush();
		}
	};
};

