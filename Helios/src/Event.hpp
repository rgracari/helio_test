#pragma once

#include <SDL.h>

namespace Helio
{
	class Event
	{
	private:
		bool isRunning = true;

	public:
		void PollEvents();
		bool IsRunning();
	};
}