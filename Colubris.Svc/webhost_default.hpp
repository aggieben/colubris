#include "webhost_interface.hpp"
#include <stdexcept>

namespace colubris {
	class webhost_default : public webhost_interface
	{
	public:
		webhost_default();

	private:
		static HINSTANCE _dll_handle;
	};
}