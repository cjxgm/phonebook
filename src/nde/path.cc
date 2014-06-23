#include "path.hh"

static string root;


void nde::path::root(const string& path)
{
	::root = path;
}

string project()
{
	string path{::root + "/" + "nde:phonebook"};
	return path;
}


