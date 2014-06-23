#pragma once
#include "type.hh"
#include "wrapper.hh"

namespace nde
{
	namespace action
	{
		struct Undo: public Type
		{
		};

		Wrapper<Undo> undo{"undo"};
	};
};

