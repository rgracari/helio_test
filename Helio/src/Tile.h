#pragma once

#include <SDL.h>

namespace Helio
{
	class Tile
	{
	public:
		SDL_Rect posInTileset;
		SDL_Rect posInScreen;
	
		Tile(SDL_Rect tile, SDL_Rect pos)
			: posInTileset(tile), posInScreen(pos)
		{

		}

		~Tile()
		{

		}
	};
}