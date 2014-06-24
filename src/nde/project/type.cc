#include "type.hh"
#include "snapshot.hh"
#include "../action/helper.hh"

namespace nde
{
	namespace project
	{
		void Type::read()
		{
			snapshot::load(path::snapshot(), datas);
			while (action::read(file)) {}
		}

		void Type::snapshot()
		{
			snapshot::save(path::snapshot(), datas);
			file.reset();

			// clear actions
			for (auto action: actions)
				delete action;
			actions.clear();
			action_pos = 0;
			undo_pos = 0;
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

