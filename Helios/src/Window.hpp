#pragma once

#include <SDL.h>
#include <string>
#include <iostream>

namespace Helio
{
	class Window
	{
	private:
		SDL_Window* window = NULL;
	
	public:
		Window(const std::string& windowName);
		SDL_Window* GetSDLWindow();
		~Window();
	};
}