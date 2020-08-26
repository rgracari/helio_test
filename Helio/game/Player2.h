#pragma once

#include "../src/Sprite.h"

namespace Helio
{
	class Player2 : public Sprite
	{
	private:
		Vector2 velocity = { 0, 0 };
	public:
		Player2(std::shared_ptr<Texture> text, SDL_Rect rct) : Sprite(text, rct) {}

		void Events(Event& events)
		{
			velocity.y = 0;
			velocity.x = 0;
			if (events.GetKey(SDL_SCANCODE_W))
			{
				velocity.y -= 300;
			}
			if (events.GetKey(SDL_SCANCODE_S))
			{
				velocity.y += 300;
			}
			if (events.GetKey(SDL_SCANCODE_A))
			{
				velocity.x -= 300;
			}
			if (events.GetKey(SDL_SCANCODE_D))
			{
				velocity.x += 300;
			}
		}

		void Update(const double& delta)
		{
			rect.x += velocity.x * delta;
			rect.y += velocity.y * delta;
		}
	};
}