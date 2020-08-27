#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <memory>

#include "Texture.h"
#include "Quadrilateral.h"
#include "Sprite.h"
#include "Spritesheet.h"
#include "Window.h"
#include "Tilemap.h"

#include "Log.h"
#include "Viewport.h"
#include "Camera.h"
#include "Text.h"

namespace Helio
{
	class Renderer
	{
	private:
		SDL_Renderer* renderer = NULL;
		Viewport rendererViewport = { 0, 0, 0, 0 };
		int baseColor;

	public:
		Renderer() {}

		void Init(Window& window, int color = 0x55)
		{
			renderer = SDL_CreateRenderer(window.GetSDLWindow(), -1, SDL_RENDERER_ACCELERATED); //  | SDL_RENDERER_PRESENTVSYNC
			rendererViewport = { 0, 0, window.GetWidth(), window.GetWidth() };
			baseColor = color;
		}

		void Render(std::shared_ptr<Text> text)
		{
			if (text->hasChanged)
			{
				SDL_Surface* textSurface = TTF_RenderText_Solid(text->GetFont()->GetSDLFont(), text->GetText().c_str(), text->GetColor());
				// test if textSurface worked
				SDL_Rect rectSprite = { text->GetRect().x, text->GetRect().y, textSurface->w, textSurface->h };
				std::shared_ptr<Texture> texture = std::make_shared<Texture>(SDL_CreateTextureFromSurface(renderer, textSurface));
				text->SetTexture(texture);
				SDL_FreeSurface(textSurface);
				// test if texture worked
				text->GetRect() = rectSprite;
				text->hasChanged = false;
			}
			SDL_RenderCopy(renderer, text->GetTexture()->GetSDLTexture(), NULL, &text->GetRect());
		}

		void SetRenderLogicalSize(int width, int height)
		{
			SDL_RenderSetLogicalSize(GetSDLRenderer(), width, height);
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

		void Render(std::shared_ptr<Tilemap> tilemap)
		{		
			for (Tile& tile : tilemap->tilemap)
			{
				SDL_RenderCopy(renderer,
					tilemap->tileset->GetSDLTexture(),
					&tile.posInTileset,
					&tile.posInScreen);
			}
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
		void Render(std::shared_ptr<Quadrilateral> shape)
		{
			Render(shape, rendererViewport);
		}
		
		void Render(std::shared_ptr<Quadrilateral> shape, Viewport& vp)
		{
			SDL_Color color = shape->GetColor();
			SDL_RenderSetViewport(renderer, vp.GetRect());
			SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
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
			SDL_SetRenderDrawColor(renderer, baseColor, baseColor, baseColor, baseColor);
			SDL_RenderClear(renderer);
		}

		SDL_Renderer* GetSDLRenderer()
		{
			return renderer;
		}

		~Renderer()
		{
			if (renderer != NULL)
			{
				SDL_DestroyRenderer(renderer);
				renderer = NULL;

			}
		}
	};
}


