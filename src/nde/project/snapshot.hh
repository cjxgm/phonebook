// vim: noet ts=4 sw=4 sts=0 fenc=utf8
// Licensed under the MIT License. See COPYING for more details.
// (C) 2014. eXerigumo Clanjor (哆啦比猫/兰威举) <cjxgm@126.com>

#pragma once
#include "data.hh"
#include <vector>
#include <string>
#include <functional>
using namespace std;

namespace nde
{
	namespace project
	{
		namespace snapshot
		{
			using Datas = vector<Data>;
			using LoadCb = function<void(const string& name, const string& phone)>;

			extern LoadCb load_cb;


			void load(const string& filename, Datas& datas);
			void save(const string& filename, const Datas& datas);
		};
	};
};

