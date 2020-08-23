#pragma once

#include "Texture.h"


namespace Helio
{
	class Files
	{
	private:
		Renderer& renderer;

	public:
		Files(Renderer& render) : renderer(render)
		{
		}

		std::shared_ptr<Texture> LoadTextureFromPNG(std::string path)
		{
			SDL_Surface* loadedSurface = IMG_Load(path.c_str());
			if (loadedSurface == NULL)
			{
				LOG_ERROR(std::string("Unable to load image %s! SDL_image Error: ") + path.c_str() + IMG_GetError());
			} // maybe make a else
			std::shared_ptr<Texture> newTexture = std::make_shared<Texture>(SDL_CreateTextureFromSurface(renderer.GetSDLRenderer(), loadedSurface));
			SDL_FreeSurface(loadedSurface);
			return newTexture;
		}
	};
}
