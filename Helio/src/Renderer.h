#pragma once

#include <SDL.h>
#include <memory>

#include "Texture.h"
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
			window = SDL_CreateWindow(NAME, WINDOW_X, WINDOW_Y, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		}

		void Render(std::shared_ptr<Texture> texture)
		{
			SDL_RenderCopy(renderer, texture->GetSDLTexture(), NULL, NULL);
		}

		void UpdateRenderer()
		{
			SDL_RenderPresent(renderer);
		}

		void ClearRenderer()
		{
			SDL_SetRenderDrawColor(renderer, RENDERER_BASE_COLOR, RENDERER_BASE_COLOR, RENDERER_BASE_COLOR, RENDERER_BASE_COLOR);
			SDL_RenderClear(renderer);
		}

		SDL_Renderer* GetSDLRenderer()
		{
			return renderer;
		}

		~Renderer()
		{
			SDL_DestroyRenderer(renderer);
			renderer = NULL;
			SDL_DestroyWindow(window);
			window = NULL;
		}
	};
}


