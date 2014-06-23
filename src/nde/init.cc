#include "project/instance.hh"

namespace nde
{
	void init()
	{
		project::instance()->read();
	}
};

