#include "path.hh"


string nde::path::root()
{
	return "./";
}

string nde::path::project()
{
	return root() + "nde:phonebook";
}

string nde::path::snapshot()
{
	return project() + ":snapshot";
}

