#pragma once
#pragma once

#include "../src/Sprite.h"

namespace Helio
{
	class Player2 : public Sprite
	{
	private:
		Vector2 vel = { 0, 0 };
	public:
		Player2(std::shared_ptr<Texture> text, SDL_Rect rct) : Sprite(text, rct) {}

		void Events(Event& events)
		{

		}

		void Update()
		{
		}
	};
}