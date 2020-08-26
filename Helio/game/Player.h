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
			if (events.GetKey(SDL_SCANCODE_UP))
			{
				rect.y -= 5;
			}
			if (events.GetKey(SDL_SCANCODE_DOWN))
			{
				rect.y += 5;
			}
			if (events.GetKey(SDL_SCANCODE_LEFT))
			{
				rect.x -= 5;
			}
			if (events.GetKey(SDL_SCANCODE_RIGHT))
			{
				rect.x += 5;
			}
		}

		void Update()
		{
		}
	};
}