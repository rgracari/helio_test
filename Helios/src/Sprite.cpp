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
		position.x = rect.x;
		position.y = rect.y;
	}

	void Sprite::SetPosition(Vector2 v)
	{
		position.x = v.x;
		position.y = v.y;
		rect.x = position.x;
		rect.y = position.y;
	}

	void Sprite::SetPosition(double x, double y)
	{
		position.x = x;
		position.y = y;
		rect.x = position.x;
		rect.y = position.y;
	}


	const Vector2& Sprite::GetPosition()
	{
		return position;
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