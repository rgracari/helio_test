#pragma once

#include "../src/Sprite.h"

namespace Helio
{
	class Player : public Sprite
	{
	private:
		Vector2 velocity = { 0, 0 };
	public:
		Player(std::shared_ptr<Texture> text, SDL_Rect rct) : Sprite(text, rct) {}

		void Events(Event& events)
		{
			velocity.y = 0;
			velocity.x = 0;
			if (events.GetKey(SDL_SCANCODE_UP))
			{
				velocity.y -= 500;
			}
			if (events.GetKey(SDL_SCANCODE_DOWN))
			{
				velocity.y += 500;
			}
			if (events.GetKey(SDL_SCANCODE_LEFT))
			{
				velocity.x -= 500;
			}
			if (events.GetKey(SDL_SCANCODE_RIGHT))
			{
				velocity.x += 500;
			}
		}

		void Update(const double& delta)
		{
			rect.x += velocity.x * delta;
			rect.y += velocity.y * delta;
		}
	};
}