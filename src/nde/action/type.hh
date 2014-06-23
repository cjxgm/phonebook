#pragma once
#include "../factory.hh"
#include "../project/file.hh"

namespace nde
{
	namespace action
	{
		struct Type
		{
			virtual void undo() = 0;
			virtual void invoke() = 0;

			virtual void read(nde::project::File& file) = 0;
			virtual void write(nde::project::File& file) = 0;

			virtual ~Type() {}
		};

		extern nde::Factory<Type> factory;
	};
};

