#pragma once

#include <SDL.h>

#include "Texture.hpp"
#include "Sprite.hpp"

namespace Helio
{
	class Game
	{
	public:
		Game();
		void Update();
		void LateUpdate();
		void Draw();
		bool IsRunning() const;
		~Game();
	private:
		Texture vikingTexture;
		Sprite vikingSprite;
	};
}