#pragma once
#include "type.hh"
#include "wrapper.hh"

namespace nde
{
	namespace action
	{
		struct Remove: public Type
		{
			// insert at pos
			static void undo_callback(size_t pos, const string& name, const string& phone);
			// remove at pos
			static void invoke_callback(size_t pos);

			void undo(Datas& datas) override
			{
				datas.insert(datas.begin() + pos, Data{name, phone});
				undo_callback(pos, name, phone);
			}

			void invoke(Datas& datas) override
			{
				name = datas[pos].name;
				phone = datas[pos].phone;
				datas.erase(datas.begin() + pos);
				invoke_callback(pos);
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

		Wrapper<Remove> remove{"remove"};
	};
};

