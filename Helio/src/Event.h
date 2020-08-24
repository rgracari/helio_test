#pragma once

#include <SDL.h>
#include <tuple>

namespace Helio
{
	enum class MouseButtton
	{
		LEFT,
		MIDDLE,
		RIGHT,
		X1,
		X2
	};

	class Event
	{
	private:
		SDL_Event e;
		const uint8_t* keyboardState = NULL;
		uint32_t mouseState = NULL;
		int mousePosX = 0;
		int mousePosY = 0;

	public:
		Event() {}

		// a voir changer ca
		bool GetKeyDown(SDL_Scancode key)
		{
			return (keyboardState[key]);
		}

		/*
		LEFT,
		MIDDLE,
		RIGHT,
		X1,
		X2
		*/

		bool GetMouseButton(MouseButtton button)
		{
			switch (button)
			{
				case MouseButtton::LEFT:
					if (mouseState & SDL_BUTTON(SDL_BUTTON_LEFT))
						return true;
					return false;

				case MouseButtton::RIGHT:
					if (mouseState & SDL_BUTTON(SDL_BUTTON_RIGHT))
						return true;
					return false;

				case MouseButtton::MIDDLE:
					if (mouseState & SDL_BUTTON(SDL_BUTTON_MIDDLE))
						return true;
					return false;

				default:
					return false;
			}
		}

		std::tuple<int, int> GetMousePos()
		{
			return { mousePosX, mousePosY };
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
			mouseState = SDL_GetMouseState(&mousePosX, &mousePosY);
		}
	};

}
