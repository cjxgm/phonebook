// vim: noet ts=4 sw=4 sts=0 fenc=utf8
// Licensed under the MIT License. See COPYING for more details.
// (C) 2014. eXerigumo Clanjor (哆啦比猫/兰威举) <cjxgm@126.com>

#pragma once
#include <string>
using namespace std;

namespace nde
{
	namespace project
	{
		struct Data
		{
			string name;
			string phone;

			Data() {}
			Data(const string& name, const string& phone)
				: name{name}, phone{phone}
			{
			}
		};
	};
};

