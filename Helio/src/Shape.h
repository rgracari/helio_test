#pragma once

#include <SDL.h>

namespace Helio
{
	// A voir si on ne peut pas extendre a point et ligne
	class Shape
	{
	public:
		SDL_Rect rect;
		uint8_t red;
		uint8_t green;
		uint8_t blue;
		uint8_t alpha;
		bool isFilled;

		Shape(SDL_Rect rct, uint8_t r, uint8_t g, uint8_t b, uint8_t a, bool filled)
			: rect(rct), red(r), green(g), blue(b), alpha(a), isFilled(filled) {}
	};
}