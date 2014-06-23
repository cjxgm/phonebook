#pragma once
#include "type.hh"
#include "wrapper.hh"

namespace nde
{
	namespace action
	{
		struct Create: public Type
		{
			// remove last one
			static void undo_callback();
			// append
			static void invoke_callback(const string& name, const string& phone);

			void undo(Datas& datas) override
			{
				datas.erase(datas.begin() + (datas.size()-1));
				undo_callback();
			}

			void invoke(Datas& datas) override
			{
				datas.push_back(Data{name, phone});
				invoke_callback(name, phone);
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

		Wrapper<Create> create{"create"};
	};
};

