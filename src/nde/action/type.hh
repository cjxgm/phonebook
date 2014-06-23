#pragma once
#include "../factory.hh"
#include "../project/file.hh"
#include "../project/data.hh"
#include <vector>
using namespace std;

namespace nde
{
	namespace action
	{
		struct Type
		{
			using File = project::File;
			using Data = project::Data;
			using Datas = vector<Data>;

			virtual void undo(Datas& datas) = 0;
			virtual void invoke(Datas& datas) = 0;

			virtual void read(File& file) = 0;
			virtual void write(File& file) = 0;

			virtual ~Type() {}
		};

		extern nde::Factory<Type> factory;
	};

	using Actions = vector<action::Type>;
};

