#pragma once

#include <SDL.h>
#include <memory>

#include "Log.h"
#include "Constants.h"

namespace Helio
{
	class Renderer
	{
	private:
		SDL_Renderer* renderer = NULL;
		SDL_Window* window = NULL;

	public:
		Renderer()
		{
			LOG_ERROR("Renderer()");
			window = SDL_CreateWindow(NAME, WINDOW_X, WINDOW_Y, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		}

		void Render(const char* mess)
		{
			LOG_ERROR(mess);
			//SDL_RenderCopy(renderer)
		}

		void UpdateRenderer()
		{
			SDL_RenderPresent(renderer);
		}

		void ClearRenderer()
		{
			SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderClear(renderer);
		}

		~Renderer()
		{
			SDL_DestroyRenderer(renderer);
			renderer = NULL;
			SDL_DestroyWindow(window);
			window = NULL;
			LOG_ERROR("~Renderer()");
		}
	};
}


