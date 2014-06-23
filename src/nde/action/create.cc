#include "create.hh"

namespace nde
{
	namespace action
	{
		Create::UndoCb Create::undo_cb;
		Create::InvokeCb Create::invoke_cb;
		Wrapper<Create> create{"create"};
	};
};

