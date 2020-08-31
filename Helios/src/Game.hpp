#pragma once

#include <SDL.h>

#include "Texture.hpp"
#include "Sprite.hpp"
#include "Clock.hpp"

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
		void CalculateDeltaTime();
		~Game();
	private:
		Clock clock;
		Texture vikingTexture;
		Sprite vikingSprite;
		double deltaTime;
	};
}