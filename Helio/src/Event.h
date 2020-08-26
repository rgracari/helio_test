#pragma once

#include <SDL.h>
#include <tuple>
#include <vector>

#include "Window.h"

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
		SDL_Event e2;

		const uint8_t* keyboardState = NULL;
		uint32_t mouseState = NULL;
		int mousePosX = 0;
		int mousePosY = 0;
		std::vector<SDL_Keycode> keyUp;
		std::vector<SDL_Keycode> keyDown;
		//std::vector<SDL_Keycode> keyDown;
		//std::vector<char[32]> textInput;

	public:
		Event() 
		{
		}

		// Surement faire une meilleur impl + rapide de ce genre de methode

		const std::vector<SDL_Keycode>& GetKeysUp()
		{
			return keyUp;
		}

		const std::vector<SDL_Keycode>& GetKeysDown()
		{
			return keyDown;
		}

		/*const std::vector<char[32]>& GetTextInput()
		{
			return textInput;
		}*/

		bool GetKeyDown(SDL_Keycode key)
		{
			for (const SDL_Keycode& code : keyDown)
			{
				if (code == key)
					return true;
			}
			return false;
		}

		bool GetKeyUp(SDL_Keycode key)
		{
			for (const SDL_Keycode& code : keyUp)
			{
				if (code == key)
					return true;
			}
			return false;
		}

		bool GetKey(SDL_Scancode key)
		{
			return keyboardState[key];
		}

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

		void Listen(bool& isRunning, Window& window)
		{
			keyDown.clear();
			keyUp.clear();
			//textInput.clear();
			int i = 0;
			while (SDL_PollEvent(&e) != 0)
			{
				i++;
				switch (e.type)
				{
					case SDL_QUIT:
						isRunning = false;
						break;
					case SDL_KEYDOWN:
						keyDown.push_back(e.key.keysym.sym);
						break;
					case SDL_KEYUP:
						keyUp.push_back(e.key.keysym.sym);
						break;
					case SDL_TEXTINPUT:
						//textInput.push_back(e.text.text);
						break;
					case SDL_WINDOWEVENT:
						window.HandleEvents(e);
						break;
				}
			}
			keyboardState = SDL_GetKeyboardState(NULL);
			mouseState = SDL_GetMouseState(&mousePosX, &mousePosY);
		}
	};

}
