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
			action->invoke(datas);
			if (write) action::write(file, action);
		}
	};
};

