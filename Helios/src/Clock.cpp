#include "Clock.hpp"

namespace Helio
{
	double Clock::GetDeltaTime()
	{
		lastTime = currentTime;
		currentTime = SDL_GetTicks();
		return (currentTime - lastTime) / 1000.00;
	}
}