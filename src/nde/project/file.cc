#include "file.hh"
#include <unistd.h>

#include <iostream>
using namespace std;


static void find_and_replace(string& str,
		const string& what, const string& replacement)
{
	for (string::size_type pos=0;
			(pos = str.find(what, pos)) != string::npos; ) {
		str.replace(pos, what.size(), replacement);
		pos += replacement.size();
	}
}

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
			unlink(filename.c_str());
			open();
		}


		string File::string_literal()
		{
			struct bad_string_literal {};

			string s;
			char c;

			while (fin.get(c) && (c == ' ' || c == '\t' || c == '\n')) {}
			if (c != '"') throw bad_string_literal{};

			while (fin.get(c) && c != '"') {
				if (c == '\\' && !fin.get(c))
					throw bad_string_literal{};
				s += c;
			}
			if (c != '"') throw bad_string_literal{};

			return s;
		}

		void File::string_literal(const string& s)
		{
			string escaped{s};
			find_and_replace(escaped, "\\", "\\\\");
			find_and_replace(escaped, "\"", "\\\"");
			fout << " \"" << escaped << "\"";
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

