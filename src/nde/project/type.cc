#include "type.hh"
#include "../action/helper.hh"

namespace nde
{
	namespace project
	{
		void Type::append(Action* action, bool write)
		{
			actions.push_back(action);
			action->invoke(datas);
			if (write) action::write(file, action);
		}
	};
};

