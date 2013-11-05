#include "stdafx.h"
#include <functional>

namespace colubris {
	class mini_profiler
	{
	public:
		mini_profiler()
		{
			// need to set up some sort of internal state that can be queried for output at a later time, perhaps through the planned API 
		}

		template<typename Tn>
		void profile(std::function<Tn> function);
	};
}
