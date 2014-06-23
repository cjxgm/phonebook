#pragma once
#include "type.hh"
#include "wrapper.hh"
#include <functional>
using namespace std;

namespace nde
{
	namespace action
	{
		struct Remove: public Type
		{
			using UndoCb = function<void(size_t pos, const string& name, const string& phone)>;
			using InvokeCb = function<void(size_t pos)>;

			static UndoCb undo_cb;
			static InvokeCb invoke_cb;

			void undo(Datas& datas) override
			{
				datas.insert(datas.begin() + pos, Data{name, phone});
				undo_cb(pos, name, phone);
			}

			void invoke(Datas& datas) override
			{
				name = datas[pos].name;
				phone = datas[pos].phone;
				datas.erase(datas.begin() + pos);
				invoke_cb(pos);
			}

			void read(File& file) override
			{
				pos = file.int_literal();
			}

			void write(File& file) override
			{
				file.atom("remove");
				file.int_literal(pos);
			}

			Remove() {}
			Remove(size_t pos) : pos{pos} {}

		private:
			string name;
			string phone;
			size_t pos;
		};

		extern Wrapper<Remove> remove;
	};
};

