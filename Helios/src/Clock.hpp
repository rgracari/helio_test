#pragma once

#include <SDL.h>

namespace Helio
{
	class Clock
	{
	private:
		double currentTime = 0;
		double lastTime = 0;

	public:
		double GetDeltaTime();
	};
}