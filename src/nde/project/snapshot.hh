#pragma once
#include "data.hh"
#include <vector>
#include <string>
using namespace std;

namespace nde
{
	namespace project
	{
		namespace snapshot
		{
			using Datas = vector<Data>;
			void load(const string& filename, Datas& datas);
			void save(const string& filename, const Datas& datas);
		};
	};
};

