#pragma once

#include "../src/Scene.h"

namespace Helio
{
	class Level1 : public Scene
	{
	private:
		std::shared_ptr<Sprite> sprite;
	
	public:
		void Load(Files& file)
		{
			sprite = file.LoadSpriteFromTTF("assets/fonts/lazy.ttf", "Salut les gens", SDL_Color({0, 0, 0}), 45);
		}
		void Events(Event& events)
		{

		}
		void Update()
		{
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