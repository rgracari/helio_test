#pragma once

#include "SDL.h"

namespace Helio
{
	class Texture
	{
	private:
		SDL_Texture* texture = NULL;

	public:
		Texture(SDL_Texture* tex) : texture(tex) {
			LOG_INFO("Texture created");
		}

		SDL_Texture* GetSDLTexture()
		{
			return texture;
		}

		~Texture()
		{
			if (texture != NULL)
				LOG_INFO("Texture destroyed");
				SDL_DestroyTexture(texture);
		}
	};
}