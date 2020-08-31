#pragma once

#include <SDL.h>
#include <string>

namespace Helio
{
	class Texture
	{
	private:
		SDL_Surface* surface = NULL;
		SDL_Texture* texture = NULL;

	public:
		Texture();

		SDL_Surface* GetSDLSurface();
		SDL_Texture* GetSDLTexture();

		void LoadFromFile(const std::string& path);
		
		~Texture();
	};
}