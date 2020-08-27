#pragma once

#include <vector>

#include "Tileset.h"
#include "Tile.h"

namespace Helio
{
	class Tilemap
	{
	public:
		std::shared_ptr<Tileset> tileset;
		std::vector<int> map;
		std::vector<Tile> tilemap;
		int mapWidth;
		int mapHeight;

		Tilemap(std::shared_ptr<Tileset> ts, std::vector<int> mp, int width, int height)
			: tileset(ts), map(mp), mapWidth(width), mapHeight(height)
		{
			int i = 0;
			int j = 0;
			for (int& val : map)
			{
				tilemap.push_back(Tile(tileset->GetTiles()[val], { i * 16, j * 16, 16, 16 }));
				i++;
				if (i >= mapWidth)
				{
					i = 0;
					j++;
				}
			}
		}

		void PrintTilemap()
		{
			for (Tile& tl : tilemap)
			{
				std::cout << "X: " << tl.posInScreen.x << ", Y: " << tl.posInScreen.y;
				std::cout << ", W: " << tl.posInScreen.w << ", H: " << tl.posInScreen.h << std::endl;
			}
		}
	};
}