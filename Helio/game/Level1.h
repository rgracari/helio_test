#pragma once

#include "../src/Scene.h"

namespace Helio
{
	class Level1 : public Scene
	{
	private:
		std::shared_ptr<Sprite> sprite;
		uint8_t alpha = 0;

	public:
		void Load(Files& file)
		{
			sprite = file.LoadSpriteFromPNG("assets/images/dots.png");
			sprite->SetBlendMode(SDL_BLENDMODE_BLEND);
		}
		void Events(Event& events)
		{
			if (events.GetKeyDown(SDL_SCANCODE_UP))
			{
				LOG_ERROR("UPP");
				alpha++;
			}
			if (events.GetKeyDown(SDL_SCANCODE_DOWN))
			{
				LOG_ERROR("DOWN");
				alpha--;
			}
		}
		void Update()
		{
			sprite->ModulateAlpha(alpha);
		}
		void Render(Renderer& renderer)
		{
			renderer.Render(sprite);
		}
		void Clear()
		{

		}
	};
}