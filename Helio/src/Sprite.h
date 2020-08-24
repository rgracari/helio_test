#pragma once

#include <SDL.h>
#include <memory>

#include "Texture.h"

#include "Renderer.h"
#include "Event.h"

namespace Helio
{
	class Sprite
	{
	public:
		double angle = 0.0;
		SDL_Point center;

	protected:
		std::shared_ptr<Texture> texture;
		SDL_Rect rect;
		SDL_RendererFlip flip = SDL_FLIP_NONE;

	public:
		Sprite(std::shared_ptr<Texture> text, SDL_Rect rct) : texture(text), rect(rct)
		{
			center = { rect.w / 2, rect.h / 2 };
		}

		SDL_Texture* GetSDLTexture()
		{
			return texture->GetSDLTexture();
		}
		
		SDL_Rect* GetSDLRect()
		{
			return &rect;
		}

		SDL_RendererFlip& GetRendererFlip()
		{
			return flip;
		}

		void ModulateColor(uint8_t r, uint8_t g, uint8_t b)
		{
			SDL_SetTextureColorMod(texture->GetSDLTexture(), r, g, b);
		}

		void ModulateAlpha(uint8_t alpha)
		{
			SDL_SetTextureAlphaMod(texture->GetSDLTexture(), alpha);
		}

		void SetBlendMode(SDL_BlendMode blendMode)
		{
			SDL_SetTextureBlendMode(texture->GetSDLTexture(), blendMode);
		}

		void FlipTexture(SDL_RendererFlip flipFlag)
		{
			flip = flipFlag;
		}

		virtual ~Sprite()
		{

		}
	};
}