#include "Event.hpp"

#include <iostream>

namespace Helio
{
	void Event::PollEvents()
	{
		SDL_Event events;

		while (SDL_PollEvent(&events))
		{
			switch (events.type)
			{
				case SDL_QUIT:
				{
					std::cout << "EVENT: CLOSE WINDOW" << std::endl;
					isRunning = false;
				}
			}
		} 
	}

	bool Event::IsRunning()
	{
		return isRunning;
	}
}

