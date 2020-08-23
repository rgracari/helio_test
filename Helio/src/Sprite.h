#pragma once

#include <SDL.h>
#include <memory>

#include "Texture.h"

namespace Helio
{
	class Sprite
	{
	private:
		std::shared_ptr<Texture> texture;
		SDL_Rect rect;

	public:
		Sprite(std::shared_ptr<Texture> text, SDL_Rect rct) : texture(text), rect(rct) {}

		SDL_Texture* GetSDLTexture()
		{
			return texture->GetSDLTexture();
		}
		
		SDL_Rect* GetSDLRect()
		{
			return &rect;
		}

		void ModulateColor(uint8_t r, uint8_t g, uint8_t b)
		{
			SDL_SetTextureColorMod(texture->GetSDLTexture(), r, g, b);
		}
	};
}