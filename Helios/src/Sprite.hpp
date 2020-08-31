#pragma once

#include "Texture.hpp"
#include "Vector2.hpp"

namespace Helio
{
	class Sprite
	{
	private:
		SDL_Texture* texture = NULL;
		SDL_Rect rect = { 0, 0, 0, 0};
		Vector2 position;

	public:
		Sprite();

		SDL_Texture* GetSDLTexture();
		SDL_Rect* GetSDLRect();
		void SetTexture(Texture& txt);
		void SetRect(SDL_Rect& rt);
		void SetPosition(double x, double y);
		void SetPosition(Vector2 v);
		const Vector2& GetPosition();

		~Sprite();
	};
}