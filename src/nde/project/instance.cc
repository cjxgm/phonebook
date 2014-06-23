#include "instance.hh"

static nde::project::Type* instance;

namespace nde
{
	namespace project
	{
		Type* instance()
		{
			if (!::instance) ::instance = new Type{};
			return ::instance;
		}
	};
};

