#include <iostream>

#include "Sprite.hpp"

namespace Helio
{
	Sprite::Sprite()
	{
		std::cout << "Sprite Created" << std::endl;
	}

	SDL_Rect* Sprite::GetSDLRect()
	{
		return &rect;
	}

	SDL_Texture* Sprite::GetSDLTexture()
	{
		return texture;
	}

	void Sprite::SetTexture(Texture& txt)
	{
		texture = txt.GetSDLTexture();
		rect = txt.GetSDLSurface()->clip_rect;
	}

	void Sprite::SetRect(SDL_Rect& rt)
	{
		rect = rt;
	}

	Sprite::~Sprite()
	{
		std::cout << "Sprite Destroyed" << std::endl;
	}
}