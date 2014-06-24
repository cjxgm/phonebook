// vim: noet ts=4 sw=4 sts=0 fenc=utf8
// Licensed under the MIT License. See COPYING for more details.
// (C) 2014. eXerigumo Clanjor (哆啦比猫/兰威举) <cjxgm@126.com>

#include "file.hh"
#include <cstdio>
#include <iomanip>
using namespace std;

namespace nde
{
	namespace project
	{
		void File::open()
		{
			struct bad_file {};
			fin.open(filename, ios::in);
			fout.open(filename, ios::app);
			if (!fout.is_open()) throw bad_file{};
		}

		void File::close()
		{
			fin.close();
			fout.close();
		}

		File::File(const string& filename)
			: filename{filename}
		{
			open();
		}

		void File::reset()
		{
			close();
			remove(filename.c_str());
			open();
		}


		string File::string_literal()
		{
			string s;
			fin >> std::quoted(s);
			return s;
		}

		void File::string_literal(const string& s)
		{
			fout << " " << quoted(s);
		}


		int File::int_literal()
		{
			int x;
			fin >> x;
			return x;
		}

		void File::int_literal(int x)
		{
			fout << " " << x;
		}


		string File::atom()
		{
			string s;
			fin >> s;
			return s;
		}

		void File::atom(const string& s)
		{
			fout << s;
		}


		void File::eol()
		{
			fout << endl;
		}
	};
};

