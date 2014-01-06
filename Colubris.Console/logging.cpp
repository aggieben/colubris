#include "stdafx.h"

namespace cl = colubris::logging;

const char *
cl::to_string(cl::severity_level lvl)
{
	const char * result = nullptr;

	switch (lvl)
	{
	case cl::trace:
		result = "trace";
		break;
	case cl::debug:
		result = "debug";
		break;
	case cl::info:
		result = "info";
		break;
	case cl::warning:
		result = "warning";
		break;
	case cl::error:
		result = "error";
		break;
	case cl::fatal:
		result = "fatal";
		break;
	}

	return result;
}