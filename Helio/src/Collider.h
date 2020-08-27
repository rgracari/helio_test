#pragma once

#include <SDL.h>

namespace Helio
{
	class Collider
	{
	public:
		static bool CheckCollision(SDL_Rect& a, SDL_Rect& b)
		{
			int leftA, rightA, topA, bottomA;
			int leftB, rightB, topB, bottomB;

			leftA = a.x;
			rightA = a.x + a.w;
			topA = a.y;
			bottomA = a.y + a.h;

			leftB = b.x;
			rightB = b.x + b.w;
			topB = b.y;
			bottomB = b.y + b.h;

			if (rightB < leftA)
				return false;
			if (leftB > rightA)
				return false;
			if (bottomB < topA)
				return false;
			if (bottomA < topB)
				return false;

			return true;
		}
	};
}