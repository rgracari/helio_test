#pragma once

#include <SDL.h>

namespace Helio
{
	class Viewport
	{
	private:
		SDL_Rect rect;
	public:
		Viewport(int x, int y, int w, int h) : rect({ x, y, w, h}) {}
		SDL_Rect* GetRect() { return &rect; }
	};
}