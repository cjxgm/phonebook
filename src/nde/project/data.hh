#pragma once

namespace nde
{
	namespace project
	{
		struct Data
		{
			string name;
			string phone;

			Data(const string& name, const string& phone)
				: name{name}, phone{phone}
			{
			}
		};
	};
};
