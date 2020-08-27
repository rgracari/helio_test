#pragma once

#include "SDL.h"

namespace Helio
{
	class Texture
	{
	private:
		SDL_Texture* texture = NULL;

	public:
		Texture(SDL_Texture* tex) : texture(tex) 
		{
		}

		SDL_Texture* GetSDLTexture()
		{
			return texture;
		}

		~Texture()
		{
			if (texture != NULL)
				SDL_DestroyTexture(texture);
		}
	};
}