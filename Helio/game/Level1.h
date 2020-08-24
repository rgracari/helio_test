#pragma once

#include "../src/Scene.h"




namespace Helio
{
	class Level1 : public Scene
	{
	private:
		std::shared_ptr<Sprite> sprite;
		int frame = 0;
	
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