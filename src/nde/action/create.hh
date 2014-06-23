#pragma once
#include "type.hh"
#include "wrapper.hh"

namespace nde
{
	namespace action
	{
		struct Create: public Type
		{
		};

		Wrapper<Create> create{"create"};
	};
};

