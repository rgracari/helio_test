#pragma once

namespace Helio
{
	enum class Player2Animation
	{
		Idle,
		Run,
	};

	class Player2 : public AnimatedSprite<Player2Animation>
	{
	public:
		Vector2 velocity = { 0.0, 0.0 };
		Vector2 acceleration = { 0.0, 0.0 };
		Vector2 position = { 0.0, 0.0 };
		double friction = 0.995;

		Player2(std::shared_ptr<Tileset> tl) : AnimatedSprite<Player2Animation>(tl)
		{
			SetAnimation(Player2Animation::Idle, std::make_tuple(std::vector({ 0 }), 0 ));
			SetAnimation(Player2Animation::Run, std::make_tuple(std::vector({ 1, 2, 3 }), 100));
		}

		void Events(Event& events)
		{
			HandleInputs(events);
		}

		void Update(const double& delta)
		{
			ApplyPhysic(delta);
			KeepPlayerWithinBorders();

			rect.x = position.x;
			rect.y = position.y;
		}

		void HandleInputs(Event& events)
		{
			acceleration.x = 0;
			acceleration.y = 0;
			if (events.GetKey(SDL_SCANCODE_A))
			{
				acceleration.x = -800;
				Flip(SDL_FLIP_HORIZONTAL);
				Animate(Player2Animation::Run);
			}
			if (events.GetKey(SDL_SCANCODE_D))
			{
				acceleration.x = 800;
				Flip(SDL_FLIP_NONE);
				Animate(Player2Animation::Run);
			}
			if (events.GetKeyDown(SDLK_z))
			{
				velocity.y = -200;
			}
		}

		void ApplyPhysic(const double& delta)
		{
			velocity.x += acceleration.x * delta;
			velocity.y += acceleration.y * delta;

			velocity.x *= friction;
			velocity.y += 0.5;

			position.x += velocity.x * delta;
			position.y += velocity.y * delta;
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