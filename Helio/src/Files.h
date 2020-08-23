#pragma once

#include "Texture.h"

namespace Helio
{
	class Files
	{
	private:
		Renderer& renderer;

	public:
		Files(Renderer& render) : renderer(render) {}

		std::shared_ptr<Sprite> LoadSpriteFromPNG(std::string path, bool setColorKey = false, int r = 0x00, int g = 0x00, int b = 0x00)
		{
			SDL_Surface* loadedSurface = IMG_Load(path.c_str());
			if (loadedSurface == NULL)
			{
				LOG_ERROR(std::string("Unable to load image %s! SDL_image Error: ") + path.c_str() + IMG_GetError());
			} // maybe make a else
			if (setColorKey)
				SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, r, g, b));
			std::shared_ptr<Texture> newTexture = std::make_shared<Texture>(SDL_CreateTextureFromSurface(renderer.GetSDLRenderer(), loadedSurface));
			SDL_Rect rectSprite = { 0, 0, loadedSurface->w, loadedSurface->h };
			SDL_FreeSurface(loadedSurface);
			std::shared_ptr<Sprite> sprite = std::make_shared<Sprite>(newTexture, rectSprite);
			return sprite;
		}
	};
}
