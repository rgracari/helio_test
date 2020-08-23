#pragma once

#include "../src/Scene.h"

namespace Helio
{
	class Level1 : public Scene
	{
	private:
		std::shared_ptr<Spritesheet> spritesheet;

	public:
		void Load(Files& file)
		{
			std::shared_ptr<Sprite> tempSprite = file.LoadSpriteFromPNG("assets/images/dots.png", true, 0x00, 0xFF, 0xFF);
			
			spritesheet = std::make_shared<Spritesheet>(tempSprite, SDL_Rect({ 0, 100, 100, 100 }));
		}
		void Events(Event& events)
		{

		}
		void Update()
		{

		}
		void Render(Renderer& renderer)
		{
			renderer.Render(spritesheet);
		}
		void Clear()
		{

		}
	};
}