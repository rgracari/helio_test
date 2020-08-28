#pragma once

#include "Sprite.h"

namespace Helio
{
	class Tileset : public Sprite
	{
	protected:
		int tileSize;
		std::vector<SDL_Rect> tiles;

	public:
		Tileset(std::shared_ptr<Texture> text, SDL_Rect rct, int tl)
			: Sprite(text, rct), tileSize(tl)
		{
			int xnumberOfTile = rct.w / tileSize;
			int ynumberOfTile = rct.h / tileSize;
			for (int i = 0; i < ynumberOfTile; i++)
			{
				for (int j = 0; j < xnumberOfTile; j++)
					tiles.push_back(SDL_Rect({ j * tileSize, i * tileSize, tileSize, tileSize }));
			}
		}

		void PrintTilesRect()
		{
			for (SDL_Rect& tile : tiles)
			{
				std::cout << "X :" << tile.x << ", Y: " << tile.y;
				std::cout << ", H :" << tile.h << ", W: " << tile.w << std::endl;
			}
		}

		std::vector<SDL_Rect>& GetTiles()
		{
			return tiles;
		}

		~Tileset()
		{

		}
	};
}