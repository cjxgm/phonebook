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

