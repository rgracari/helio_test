#pragma once

#include "../src/Sprite.h"

namespace Helio
{
	class Player : public Sprite
	{
	private:
		Vector2 vel = { 0, 0 };
	public:
		Player(std::shared_ptr<Texture> text, SDL_Rect rct) : Sprite(text, rct) {}

		void Events(Event& events)
		{
			if (events.GetKeyDown(SDL_SCANCODE_UP))
			{
				rect.y -= 1;
			}
			if (events.GetKeyDown(SDL_SCANCODE_DOWN))
			{
				rect.y += 1;
			}
			if (events.GetKeyDown(SDL_SCANCODE_LEFT))
			{
				rect.x -= 1;
			}
			if (events.GetKeyDown(SDL_SCANCODE_RIGHT))
			{
				rect.x += 1;
			}
		}

		void Update()
		{
		}
	};
}