#pragma once

#include "Sprite.h"

namespace Helio
{
	class Tileset : public Sprite
	{
	private:
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

		std::vector<SDL_Rect>& GetTiles()
		{
			return tiles;
		}

		~Tileset()
		{

		}
	};
}