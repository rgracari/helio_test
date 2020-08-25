#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <memory>

#include "Texture.h"
#include "Shape.h"
#include "Sprite.h"
#include "Spritesheet.h"

#include "Log.h"
#include "Constants.h"
#include "Viewport.h"
#include "Camera.h"
#include "Text.h"

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
			renderer = SDL_CreateRenderer(window, -1, RENDERER_MODE);
		}

		void Render(std::shared_ptr<Text> text)
		{
			if (text->hasChanged)
			{
				SDL_Surface* textSurface = TTF_RenderText_Solid(text->GetFont()->GetSDLFont(), text->GetText().c_str(), text->GetColor());
				// test if textSurface worked
				SDL_Rect rectSprite = { 0, 0, textSurface->w, textSurface->h };
				std::shared_ptr<Texture> texture = std::make_shared<Texture>(SDL_CreateTextureFromSurface(renderer, textSurface));
				text->SetTexture(texture);
				SDL_FreeSurface(textSurface);
				// test if texture worked
				text->GetRect() = rectSprite;
				text->hasChanged = false;
			}
			SDL_RenderCopy(renderer, text->GetTexture()->GetSDLTexture(), NULL, &text->GetRect());
		}

		void Render(std::shared_ptr<Sprite> sprite, Camera& camera)
		{
			SDL_RenderCopyEx(renderer,
				sprite->GetSDLTexture(),
				NULL,
				&camera.Apply(sprite->GetSDLRect()),
				sprite->angle,
				&sprite->center,
				sprite->GetRendererFlip());
		}

		void Render(std::shared_ptr<Sprite> sprite)
		{
			Render(sprite, rendererViewport);
		}

		void Render(std::shared_ptr<Sprite> sprite, Viewport& vp)
		{
			SDL_RenderSetViewport(renderer, vp.GetRect());
			SDL_RenderCopyEx(renderer,
							sprite->GetSDLTexture(),
							NULL,
							sprite->GetSDLRect(),
							sprite->angle,
							&sprite->center,
							sprite->GetRendererFlip());
		}

		void Render(std::shared_ptr<Spritesheet> spritesheet)
		{
			Render(spritesheet, rendererViewport);
		}

		void Render(std::shared_ptr<Spritesheet> spritesheet, Viewport& vp)
		{
			SDL_RenderSetViewport(renderer, vp.GetRect());
			SDL_RenderCopy(renderer, spritesheet->GetSDLTexture(), spritesheet->GetSDLInnerRect(), spritesheet->GetSDLRect());
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


