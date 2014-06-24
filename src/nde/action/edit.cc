#include "edit.hh"

namespace nde
{
	namespace action
	{
		Edit::UndoCb Edit::undo_cb;
		Edit::InvokeCb Edit::invoke_cb;
		Wrapper<Edit> edit{"edit"};
	};
};

