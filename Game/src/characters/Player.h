#pragma once

namespace Helio
{
	class Player : public Sprite
	{
	public:
		Vector2 velocity = { 0.0, 0.0 };
		Vector2 acceleration = { 0.0, 0.0 };
		Vector2 position = { 0.0, 0.0 };
		double friction = 0.995;

		Player(std::shared_ptr<Texture> text, SDL_Rect rct) : Sprite(text, rct) {}

		void Events(Event& events)
		{
			acceleration.x = 0;
			acceleration.y = 0;
			if (events.GetKey(SDL_SCANCODE_LEFT))
			{
				acceleration.x = -800;
				FlipTexture(SDL_FLIP_HORIZONTAL);
			}
			if (events.GetKey(SDL_SCANCODE_RIGHT))
			{
				acceleration.x = 800;
				FlipTexture(SDL_FLIP_NONE);
			}
			if (events.GetKeyDown(SDLK_UP))
			{
				velocity.y = -200;
			}
		}

		void Update(const double& delta)
		{

			velocity.x += acceleration.x * delta;
			velocity.y += acceleration.y * delta;

			velocity.x *= friction;
			velocity.y += 0.5;

			position.x += velocity.x * delta;
			position.y += velocity.y * delta;


			KeepPlayerWithinBorders();
			
			rect.x = position.x;
			rect.y = position.y;
		}

		void KeepPlayerWithinBorders()
		{
			if (position.y > LOGICAL_HEIGHT - rect.w)
				position.y = LOGICAL_HEIGHT - rect.w;
			if (position.y < 0)
				position.y = 0;

			if (position.x > LOGICAL_WIDTH - rect.h)
				position.x = LOGICAL_WIDTH - rect.h;
			if (position.x < 0)
				position.x = 0;
		}
	};
}