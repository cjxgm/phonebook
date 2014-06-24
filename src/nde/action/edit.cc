// vim: noet ts=4 sw=4 sts=0 fenc=utf8
// Licensed under the MIT License. See COPYING for more details.
// (C) 2014. eXerigumo Clanjor (哆啦比猫/兰威举) <cjxgm@126.com>

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

