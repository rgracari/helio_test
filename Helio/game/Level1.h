#pragma once

//#include <SDL_mixer.h>

#include "../src/Scene.h"

#include "Player.h"


namespace Helio
{
	class Level1 : public Scene
	{
	private:
		std::shared_ptr<Player> player;

	public:
		void Load(Files& file)
		{
			auto [texture, rect] = file.LoadSpriteFromPNG("assets/images/mage.png");
			player = std::make_shared<Player>(texture, rect);
		}
		void Events(Event& events)
		{
			player->Events(events);
		}
		void Update()
		{
			player->Update();
		}
		void Render(Renderer& renderer)
		{
			renderer.Render(player);
		}
		void Clear()
		{

		}
	};
}