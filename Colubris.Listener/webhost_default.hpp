#pragma once
#include "api.hpp"
#include "webhost_interface.hpp"
#include <stdexcept>

namespace colubris {
	class COLUBRISLISTENER_API webhost_default : public webhost_interface
	{
	public:
		webhost_default();

	private:
		static HINSTANCE _dll_handle;
	};
}