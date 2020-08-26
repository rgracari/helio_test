#pragma once

#include <SDL.h>

namespace Helio
{
	// A voir si on ne peut pas extendre a point et ligne
	class Quadrilateral
	{
	public:
		SDL_Rect rect;
		SDL_Color color;
		bool isFilled;

		Quadrilateral(SDL_Rect rct, SDL_Color clr, bool filled)
			: rect(rct), color(clr), isFilled(filled) {}

		const SDL_Color& GetColor()
		{
			return color;
		}
	};
}