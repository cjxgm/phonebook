#pragma once
#include "type.hh"
#include "wrapper.hh"
#include <functional>
using namespace std;

namespace nde
{
	namespace action
	{
		struct Create: public Type
		{
			using UndoCb = function<void()>;
			using InvokeCb = function<void(const string& name, const string& phone)>;

			static UndoCb undo_cb;
			static InvokeCb invoke_cb;


			void undo(Datas& datas) override
			{
				datas.erase(datas.begin() + (datas.size()-1));
				undo_cb();
			}

			void invoke(Datas& datas) override
			{
				datas.push_back(Data{name, phone});
				invoke_cb(name, phone);
			}

			void read(File& file) override
			{
				name = file.string_literal();
				phone = file.string_literal();
			}

			void write(File& file) override
			{
				file.atom("create");
				file.string_literal(name);
				file.string_literal(phone);
			}

			Create() {}
			Create(const string& name, const string& phone)
				: name{name}, phone{phone}
			{
			}

		private:
			string name;
			string phone;
		};

		extern Wrapper<Create> create;
	};
};

