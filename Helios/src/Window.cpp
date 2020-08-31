#include "Window.hpp"

namespace Helio
{
	Window::Window(const std::string& windowName)
	{
		std::cout << "SDL INIT" << std::endl;
		SDL_Init(SDL_INIT_VIDEO);
		
		std::cout << "Window Created" << std::endl;
		window = SDL_CreateWindow(
			windowName.c_str(),
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			640,
			480,
			SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
		
		if (window == NULL)
			std::cout << "Could not create window: " << SDL_GetError() << std::endl;;
	}

	SDL_Window* Window::GetSDLWindow()
	{
		return window;
	}


	Window::~Window()
	{
		std::cout << "Window Destroyed" << std::endl;
		if (window != NULL)
		{
			SDL_DestroyWindow(window);
			window = NULL;
		}
		std::cout << "SDL QUIT" << std::endl;
		SDL_Quit();
	}
}