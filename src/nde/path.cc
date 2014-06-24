// vim: noet ts=4 sw=4 sts=0 fenc=utf8
// Licensed under the MIT License. See COPYING for more details.
// (C) 2014. eXerigumo Clanjor (哆啦比猫/兰威举) <cjxgm@126.com>

#include "path.hh"


string nde::path::root()
{
	return "./";
}

string nde::path::project()
{
	return root() + "nde:phonebook";
}

string nde::path::snapshot()
{
	return project() + ":snapshot";
}

