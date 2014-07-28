// vim: noet ts=4 sw=4 sts=0 fenc=utf8
// Licensed under the MIT License. See COPYING for more details.
// (C) 2014. eXerigumo Clanjor (哆啦比猫/兰威举) <cjxgm@126.com>

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

			// only undo/redo can override this to "false"
			virtual bool reset_pos() { return true; }

			virtual ~Type() = default;
		};

		extern nde::Factory<Type> factory;
	};

	using Actions = vector<action::Type>;
};

