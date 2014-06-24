// vim: noet ts=4 sw=4 sts=0 fenc=utf8
// Licensed under the MIT License. See COPYING for more details.
// (C) 2014. eXerigumo Clanjor (哆啦比猫/兰威举) <cjxgm@126.com>

#pragma once
#include "../action/type.hh"
#include "../path.hh"
#include "data.hh"
#include <vector>
using namespace std;

namespace nde
{
	namespace project
	{
		struct Type
		{
			using Datas = vector<Data>;
			using Action = action::Type;
			using Actions = vector<Action*>;

		private:
			Datas datas{};
			Actions actions{};
			size_t action_pos{};
			size_t undo_pos{};

			File file{path::project()};

		public:
			void read();
			void snapshot();

			void append(Action* action, bool write=true);

			inline bool undoable() { return action_pos-undo_pos; }
			inline bool redoable() { return undo_pos; }

			size_t undo(int pos=-1);
			size_t redo(int pos=-1);
		};
	};
};

