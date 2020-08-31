#pragma once

#include "Texture.hpp"

namespace Helio
{
	class Sprite
	{
	private:
		SDL_Texture* texture = NULL;
		SDL_Rect rect = { 0, 0, 0, 0};
	
	public:
		Sprite();

		SDL_Texture* GetSDLTexture();
		SDL_Rect* GetSDLRect();
		void SetTexture(Texture& txt);
		void SetRect(SDL_Rect& rt);

		~Sprite();
	};
}