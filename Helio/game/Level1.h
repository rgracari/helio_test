#pragma once

//#include <SDL_mixer.h>

#include "../src/Scene.h"

#include "Player.h"


namespace Helio
{
	class Level1 : public Scene
	{
	private:
		std::shared_ptr<Sprite> background;
		std::shared_ptr<Player> player;
		Camera camera = { WINDOW_WIDTH, WINDOW_HEIGHT, 1920, 1080 };

	public:
		void Load(Files& file)
		{
			auto [textureBack, rectBack] = file.LoadSpriteFromPNG("assets/images/cc.png");
			background = std::make_shared<Sprite>(textureBack, rectBack);
			
			auto [texture, rect] = file.LoadSpriteFromPNG("assets/images/dots.png");
			player = std::make_shared<Player>(texture, rect);
		}
		void Events(Event& events)
		{
			player->Events(events);
		}
		void Update()
		{
			player->Update();
			camera.Update(player->GetSDLRect());
		}
		void Render(Renderer& renderer)
		{
			renderer.Render(background, camera);
			renderer.Render(player, camera);
		}
		void Clear()
		{

		}
	};
}