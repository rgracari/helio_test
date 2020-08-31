#pragma once

#include <SDL.h>

#include "Renderer.hpp"
#include "Texture.hpp"

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
		//Sprite vikingSprite;
	};
}