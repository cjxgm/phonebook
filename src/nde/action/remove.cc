#include "remove.hh"

namespace nde
{
	namespace action
	{
		Remove::UndoCb Remove::undo_cb;
		Remove::InvokeCb Remove::invoke_cb;
		Wrapper<Remove> remove{"remove"};
	};
};

