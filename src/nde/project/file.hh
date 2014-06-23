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
			fstream fs;

		public:
			File(const string& filename);

			inline void flush() { fs.flush(); }
			inline operator bool() { return fs; }

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

