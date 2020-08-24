#pragma once

// should imp time too
#include <SDL.h>

namespace Helio
{
	class Time
	{
	public:
		static uint32_t GetTicks()
		{
			return SDL_GetTicks();
		}
	};
}