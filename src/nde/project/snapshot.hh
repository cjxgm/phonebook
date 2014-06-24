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

