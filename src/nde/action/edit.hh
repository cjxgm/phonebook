#pragma once
#include "type.hh"
#include "wrapper.hh"
#include <functional>
using namespace std;

namespace nde
{
	namespace action
	{
		struct Edit: public Type
		{
			using UndoCb = function<void(size_t pos, const string& name, const string& phone)>;
			using InvokeCb = UndoCb;

			static UndoCb undo_cb;
			static InvokeCb invoke_cb;


			void undo(Datas& datas) override
			{
				datas[pos] = Data{old_name, old_phone};
				undo_cb(pos, old_name, old_phone);
			}

			void invoke(Datas& datas) override
			{
				old_name = datas[pos].name;
				old_phone = datas[pos].phone;
				datas[pos] = Data{name, phone};
				invoke_cb(pos, name, phone);
			}

			void read(File& file) override
			{
				pos = file.int_literal();
				name = file.string_literal();
				phone = file.string_literal();
			}

			void write(File& file) override
			{
				file.atom("edit");
				file.int_literal(pos);
				file.string_literal(name);
				file.string_literal(phone);
			}

			Edit() {}
			Edit(size_t pos, const string& name, const string& phone)
				: pos{pos}, name{name}, phone{phone}
			{
			}

		private:
			size_t pos;
			string name;
			string phone;
			string old_name;
			string old_phone;
		};

		extern Wrapper<Edit> edit;
	};
};

