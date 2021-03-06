// vim: noet ts=4 sw=4 sts=0 fenc=utf8
// Licensed under the MIT License. See COPYING for more details.
// (C) 2014. eXerigumo Clanjor (哆啦比猫/兰威举) <cjxgm@126.com>

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

