// vim: noet ts=4 sw=4 sts=0 fenc=utf8
// Licensed under the MIT License. See COPYING for more details.
// (C) 2014. eXerigumo Clanjor (哆啦比猫/兰威举) <cjxgm@126.com>

#pragma once
#include <fstream>
#include <string>
using namespace std;

namespace nde
{
	namespace project
	{
		class File
		{
			string filename;
			ifstream fin;
			ofstream fout;

			void open();
			void close();

		public:
			File(const string& filename);

			inline void flush() { fout.flush(); }
			inline operator bool() { return fin; }
			void reset();

			// string io
			string string_literal();
			void string_literal(const string& s);

			// int io
			int int_literal();
			void int_literal(int x);

			// atomic io
			string atom();
			void atom(const string& s);

			// eol/comment output
			void eol();
			void comment(const string& s);
		};
	};
};

