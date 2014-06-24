// vim: noet ts=4 sw=4 sts=0 fenc=utf8
// Licensed under the MIT License. See COPYING for more details.
// (C) 2014. eXerigumo Clanjor (哆啦比猫/兰威举) <cjxgm@126.com>

#include "snapshot.hh"
#include <zlib.h>
#include <cstdio>
using namespace std;


static void gzwrite(gzFile fp, size_t x)
{
	gzwrite(fp, &x, sizeof(x));
}

static void gzwrite(gzFile fp, const string& s)
{
	size_t size = s.size();
	gzwrite(fp, size);
	gzwrite(fp, s.c_str(), size);
}

static void gzread(gzFile fp, size_t& x)
{
	gzread(fp, &x, sizeof(x));
}

static void gzread(gzFile fp, string& s)
{
	size_t size;
	gzread(fp, size);

	char cstr[size+1];
	gzread(fp, cstr, size);
	cstr[size] = 0;

	s = string{cstr};
}


namespace nde
{
	namespace project
	{
		namespace snapshot
		{
			LoadCb load_cb;


			void load(const string& filename, Datas& datas)
			{
				auto fp = gzopen(filename.c_str(), "r");
				if (!fp) return;

				size_t size;
				gzread(fp, size);

				while (size--) {
					Data data;
					gzread(fp, data.name);
					gzread(fp, data.phone);
					datas.push_back(data);
					load_cb(data.name, data.phone);
				}

				gzclose(fp);
			}

			void save(const string& filename, const Datas& datas)
			{
				auto tmp = filename + ".swp";
				auto fp = gzopen(tmp.c_str(), "w");

				gzwrite(fp, datas.size());
				for (auto& data: datas) {
					gzwrite(fp, data.name);
					gzwrite(fp, data.phone);
				}

				gzclose(fp);

				rename(tmp.c_str(), filename.c_str());
			}
		};
	};
};

