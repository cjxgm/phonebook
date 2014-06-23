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

			File file{path::project()};

		public:
			void append(Action* action, bool write=true);

			inline bool undoable() { return (action_pos >            0  ); }
			inline bool redoable() { return (action_pos < actions.size()); }
		};
	};
};

