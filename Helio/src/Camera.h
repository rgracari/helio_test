#pragma once

#include <SDL.h>

namespace Helio
{
	class Camera
	{
	public:
		SDL_Rect camRect;
		int LEVEL_WIDTH;
		int LEVEL_HEIGHT;

	public:
		Camera(int width, int height, int level_width, int level_height)
			: camRect({ 0, 0, width, height }), LEVEL_WIDTH(level_width), LEVEL_HEIGHT(level_height) {}

		SDL_Rect Apply(SDL_Rect* rect)
		{
			SDL_Rect final = { rect->x - camRect.x, rect->y - camRect.y, rect->w, rect->h };
			return final;
		}

		void Update(SDL_Rect* target)
		{
			/*
			camRect.x = target->x - (WINDOW_WIDTH / 2 - target->w / 2);
			camRect.y = target->y - (WINDOW_HEIGHT / 2 - target->h / 2);

			if (camRect.x < 0)
				camRect.x = 0;
			if (camRect.y < 0)
				camRect.y = 0;
			if (camRect.x > LEVEL_WIDTH - camRect.w)
				camRect.x = LEVEL_WIDTH - camRect.w;
			if (camRect.y > LEVEL_HEIGHT - camRect.h)
				camRect.y = LEVEL_HEIGHT - camRect.h;
			*/
		}
	};
}