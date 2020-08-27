#pragma once

#include "Time.h"

namespace Helio
{
	class Clock
	{
	private:
		uint32_t last_ticks = 0;
		uint32_t current_ticks = Time::GetTicks();
	
	public:
		double GetDeltaTime()
		{
			last_ticks = current_ticks;
			current_ticks = Time::GetTicks();
			return ((current_ticks - last_ticks) * 0.001);
		}
	};
}