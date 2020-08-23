#pragma once

#include <SDL.h>
#include <memory>

#include "Texture.h"
#include "Shape.h"
#include "Sprite.h"

#include "Log.h"
#include "Constants.h"
#include "Viewport.h"

namespace Helio
{
	class Renderer
	{
	private:
		SDL_Renderer* renderer = NULL;
		SDL_Window* window = NULL;
		Viewport rendererViewport = { 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT };

	public:
		Renderer()
		{
			window = SDL_CreateWindow(NAME, WINDOW_X, WINDOW_Y, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		}

		void Render(std::shared_ptr<Sprite> texture)
		{
			Render(texture, rendererViewport);
		}

		void Render(std::shared_ptr<Sprite> sprite, Viewport& vp)
		{
			SDL_RenderSetViewport(renderer, vp.GetRect());
			SDL_RenderCopy(renderer, sprite->GetSDLTexture(), NULL, sprite->GetSDLRect());
		}

		// a voir si on transforme pas en sharedptr
		void Render(Shape* shape)
		{
			Render(shape, rendererViewport);
		}
		
		void Render(Shape* shape, Viewport& vp)
		{
			SDL_RenderSetViewport(renderer, vp.GetRect());
			SDL_SetRenderDrawColor(renderer, shape->red, shape->green, shape->blue, shape->alpha);
			if (shape->isFilled)
				SDL_RenderFillRect(renderer, &shape->rect);
			else
				SDL_RenderDrawRect(renderer, &shape->rect);
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


