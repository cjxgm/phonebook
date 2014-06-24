#include "type.hh"
#include "../action/helper.hh"

#include <iostream>
using namespace std;


namespace nde
{
	namespace project
	{
		void Type::read()
		{
			while (action::read(file)) {}
		}

		void Type::append(Action* action, bool write)
		{
			actions.push_back(action);
			if (write) action::write(file, action);
			action->invoke(datas);
			if (action->reset_pos()) {
				action_pos = actions.size();
				undo_pos = 0;
			}
		}

		size_t Type::undo(int pos)
		{
			if (pos < 0) pos = action_pos - ++undo_pos;
			actions[pos]->undo(datas);
			return pos;
		}

		size_t Type::redo(int pos)
		{
			if (pos < 0) pos = action_pos - undo_pos--;
			actions[pos]->invoke(datas);
			return pos;
		}
	};
};

