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
			}
			/*
			if (events.GetKey(SDL_SCANCODE_DOWN))
			{
				acceleration.y = 700;
			}
			if (events.GetKey(SDL_SCANCODE_LEFT))
			{
				acceleration.x = -700;
			}
			*/
			if (events.GetKey(SDL_SCANCODE_RIGHT))
			{
				acceleration.x = 800;
			}
			if (events.GetKeyDown(SDLK_SPACE))
			{
				LOG_ERROR("SAPCE PRESSED");
				velocity.y = -200;
			}
		}

		void Update(const double& delta)
		{
			
			/*
			if (abs(velocity.x) < 1)
				velocity.x = 0;

			if (abs(velocity.y) < 1)
				velocity.y = 0;
			*/

			velocity.x += acceleration.x * delta;
			velocity.y += acceleration.y * delta;

			velocity.x *= friction;
			velocity.y += 0.5;

			position.x += velocity.x * delta;
			position.y += velocity.y * delta;


			KeepPlayerWithinBorders();
			
			rect.x = position.x;
			rect.y = position.y;

			//SDL_Rect
			//rect.x = rect.x + velocity.x * delta;
			//std::cout << velocity.x * delta << std::endl;

			//velocity.x += acceleration.x * delta;
			//velocity.y += acceleration.y * delta;
			
			/*
			rect.x += velocity.x * delta;
			rect.y += velocity.y * delta;

			acceleration.y += 1;
			if (acceleration < )
			rect.y += 

			std::cout << "vel X: " << velocity.x * delta << std::endl;
			std::cout << "vel Y: " << velocity.y * delta << std::endl;

			*/
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