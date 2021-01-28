#pragma once

#include <stdint.h>
#include "utilities/hi_res_timer.hpp"

namespace Lilliputian
{
	class Profiler
	{
	public:
		HiResTimer& process();
		uint64_t lag_ms = 0;
		uint64_t frameCount = 0;
		uint16_t FPS = 0;
	private:
		HiResTimer processTimer;
	};
}