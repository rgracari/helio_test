#pragma once

#include <SDL.h>
#include <memory>

#include "Sprite.h"

namespace Helio
{
	// Le spritesheet ne devrait pas marcher comme ca
	// Il devrait pouvoir balancer une nouvelle surface avec seulement la texture a rendre
	// Ou il pourrait faire un tableau de toutes les sprites, genre on lui passe les dim et il decoupe
	// tout seul
	class Spritesheet
	{
	private:
		std::shared_ptr<Sprite> sprite;
		SDL_Rect innerRect;

	public:
		Spritesheet(std::shared_ptr<Sprite> sprt, SDL_Rect rct) : sprite(sprt), innerRect(rct) {}

		void SetInnerRect(SDL_Rect rect)
		{
			innerRect = rect;
		}

		SDL_Texture* GetSDLTexture()
		{
			return sprite->GetSDLTexture();
		}

		SDL_Rect* GetSDLRect()
		{
			return sprite->GetSDLRect();
		}

		SDL_Rect* GetSDLInnerRect()
		{
			return &innerRect;
		}
	};
}