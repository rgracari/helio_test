#pragma once

#include <SDL.h>

namespace Helio
{
	class Event
	{
	private:
		SDL_Event e;
		const uint8_t* keyboardState = NULL;

	public:
		Event() {}

		// a voir changer ca
		bool GetKeyDown(SDL_Scancode key)
		{
			return (keyboardState[key] == true);
		}

		void Listen(bool& isRunning)
		{
			while (SDL_PollEvent(&e) != 0)
			{
				switch (e.type)
				{
				case SDL_QUIT:
					isRunning = false;
				}
			}
			keyboardState = SDL_GetKeyboardState(NULL);
		}
	};

}