#pragma once
#include "type.hh"
#include "../project/instance.hh"

namespace nde
{
	namespace action
	{
		void read(nde::project::File& f)
		{
			auto action = factory.make(f.atom());
			action->read(f);
			project::instance.append(action, false);
		}

		void write(nde::project::File& f, Type* action)
		{
			action->write(f);
			f.eol();
		}
	};
};

