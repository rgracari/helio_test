#pragma once

#include "../src/Scene.h"

namespace Helio
{
	class Level1 : public Scene
	{
	private:
		std::shared_ptr<Button> button;
		
	public:
		void Load(Files& file)
		{
			auto [texture, rect] = file.LoadSpriteFromPNG("assets/images/dots.png");
			button = std::make_shared<Button>(texture, rect, 200, 200);
		}
		void Events(Event& events)
		{
			button->Events(events);
		}
		void Update()
		{
			//button.Update(events);
		}
		void Render(Renderer& renderer)
		{
			renderer.Render(button);
		}
		void Clear()
		{

		}
	};
}