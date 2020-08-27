#pragma once

#include <SDL.h>

#include "Log.h"

namespace Helio
{
	class Window
	{
	private:
		SDL_Window* window;
		int height;
		int width;
		
		bool isMinimised;

	public:
		Window()
		{
			window = NULL;
			height = 0;
			width = 0;
			isMinimised = false;
		}

		void Init(std::string name, int w, int h, int x = SDL_WINDOWPOS_CENTERED, int y = SDL_WINDOWPOS_CENTERED)
		{
			window = SDL_CreateWindow(name.c_str(), x, y, w, h, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
			// Check if the window is really create
			width = w;
			height = h;
		}

		int GetWidth()
		{
			return width;
		}

		int GetHeight()
		{
			return height;
		}

		void HandleEvents(SDL_Event& e)
		{
			switch (e.window.event)
			{
			case SDL_WINDOWEVENT_SIZE_CHANGED:
				width = e.window.data1;
				height = e.window.data2;
				break;
			case SDL_WINDOWEVENT_EXPOSED:
				isMinimised = false;
				break;
			case SDL_WINDOWEVENT_ENTER:
				break;
			case SDL_WINDOWEVENT_LEAVE:
				break;
			case SDL_WINDOWEVENT_FOCUS_GAINED:
				break;
			case SDL_WINDOWEVENT_FOCUS_LOST:
				break;
			case SDL_WINDOWEVENT_MINIMIZED:
				isMinimised = true;
				break;
			case SDL_WINDOWEVENT_MAXIMIZED:
				isMinimised = false;
				break;
			case SDL_WINDOWEVENT_RESTORED:
				break;
			default:
				break;
			}
		}

		bool IsMinimized()
		{
			return isMinimised;
		}

		/*
		int LWindow::getWidth()
		{
			return mWidth;
		}

		int LWindow::getHeight()
		{
			return mHeight;
		}

		bool LWindow::hasMouseFocus()
		{
			return mMouseFocus;
		}

		bool LWindow::hasKeyboardFocus()
		{
			return mKeyboardFocus;
		}

		bool LWindow::isMinimized()
		{
			return mMinimized;
		}*/

		SDL_Window* GetSDLWindow()
		{
			return window;
		}

		~Window()
		{
			if (window != NULL)
			{
				SDL_DestroyWindow(window);
				window = NULL;
			}
		}
	};
}