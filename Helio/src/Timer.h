#pragma once

#include <stdint.h>

#include "Time.h"

namespace Helio
{
	class Timer
	{
	private:
		uint32_t startedTicks = 0;
		uint32_t pausedTicks = 0;

		bool isPaused = false;
		bool isStarted = false;

	public:
		Timer() {}

		void start()
		{
			isStarted = true;
			isPaused = false;
			startedTicks = Time::GetTicks();
			pausedTicks = 0;
		}

		void stop()
		{
			isStarted = 0;
			isPaused = 0;
			startedTicks = 0;
			pausedTicks = 0;
		}

		void pause()
		{
			if (isStarted && !isPaused)
			{
				isPaused = true;
				pausedTicks = Time::GetTicks() - startedTicks;
				startedTicks = 0;
			}
		}

		void resume()
		{
			if (isStarted && isPaused)
			{
				isPaused = false;
				startedTicks = Time::GetTicks() - pausedTicks;
				pausedTicks = 0;
			}
		}

		uint32_t GetTicks()
		{
			uint32_t time = 0;
			if (isStarted)
			{
				if (isPaused)
				{
					time = pausedTicks;
				}
				else
				{
					time = Time::GetTicks() - startedTicks;
				}
			}
			return time;
		}

		bool IsStarted()
		{
			return isStarted;
		}

		bool IsPaused()
		{
			return isPaused;
		}

		~Timer()
		{

		}
	};
}