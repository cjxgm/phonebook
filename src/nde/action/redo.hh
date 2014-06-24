#pragma once
#include "type.hh"
#include "wrapper.hh"

namespace nde
{
	namespace action
	{
		struct Redo: public Type
		{
			void undo(Datas& datas) override
			{
				project::instance()->undo(pos);
			}

			void invoke(Datas& datas) override
			{
				pos = project::instance()->redo(pos);
			}

			void read(File& file) override {}

			void write(File& file) override
			{
				file.atom("redo");
			}

			bool reset_pos() override { return false; }

			Redo() {}

		private:
			int pos{-1};
		};

		extern Wrapper<Redo> redo;
	};
};

