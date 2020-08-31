#pragma once

#include <SDL.h>

#include "Texture.hpp"
#include "Sprite.hpp"
#include "Clock.hpp"
#include "Input.hpp"
#include "Event.hpp"

namespace Helio
{
	class Game
	{
	public:
		Game();
		void CaptureEvent();
		void CaptureInput();
		void Update();
		void LateUpdate();
		void Draw();
		bool IsRunning();
		void CalculateDeltaTime();
		~Game();
	private:
		Event event;
		Input input;
		Clock clock;
		Texture vikingTexture;
		Sprite vikingSprite;
		double deltaTime;
	};
}