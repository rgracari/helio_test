#pragma once

#include <SDL.h>
#include <SDL_image.h>
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
		void Init();
		SDL_Window* GetSDLWindow();
		~Window();
	};
}