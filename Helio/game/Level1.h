#pragma once

#include "../src/Scene.h"

namespace Helio
{
	class Level1 : public Scene
	{
	private:
		std::shared_ptr<Sprite> sprite;
		uint8_t r = 0;

	public:
		void Load(Files& file)
		{
			sprite = file.LoadSpriteFromPNG("assets/images/dots.png");
		}
		void Events(Event& events)
		{

		}
		void Update()
		{
			if (r >= 255) r = 0;
			sprite->ModulateColor(r, 255, 255);
			r++;
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