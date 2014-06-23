#include "file.hh"

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
		File::File(const string& filename)
		{
			struct bad_filename {};

			fs.open(filename, ios::in);
			if (fs.is_open()) fs.close();
			else {
				fs.open(filename, ios::out);
				if (!fs.is_open()) throw bad_filename{};
				fs.close();
			}

			fs.open(filename, ios::in | ios::app);
		}


		string File::string_literal()
		{
			struct bad_string_literal {};

			string s;
			char c;

			while (fs.get(c) && (c == ' ' || c == '\t' || c == '\n')) {}
			if (c != '"') throw bad_string_literal{};

			while (fs.get(c) && c != '"') {
				if (c == '\\' && !fs.get(c))
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
			fs << " \"" << escaped << "\"";
		}


		int File::int_literal()
		{
			int x;
			fs >> x;
			return x;
		}

		void File::int_literal(int x)
		{
			fs << " " << x;
		}


		string File::atom()
		{
			string s;
			fs >> s;
			return s;
		}

		void File::atom(const string& s)
		{
			fs << s;
		}


		void File::eol()
		{
			fs << endl;
		}
	};
};

