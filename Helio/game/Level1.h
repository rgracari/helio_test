#pragma once

//#include <SDL_mixer.h>

#include "../src/Scene.h"

#include "Player.h"
#include "Player2.h"

namespace Helio
{
	class Level1 : public Scene
	{
	private:
		std::shared_ptr<Player> player;
		std::shared_ptr<Player2> player2;

	public:
		void Load(Files& file)
		{
			auto [texture, rect] = file.LoadSpriteFromPNG("assets/images/mage.png");
			player = std::make_shared<Player>(texture, rect);

			auto [texture2, rect2] = file.LoadSpriteFromPNG("assets/images/archer.png");
			rect2.x = 100;
			rect2.y = 100;
			player2 = std::make_shared<Player2>(texture2, rect2);
		}
		void Events(Event& events)
		{
			player->Events(events);
			player2->Events(events);
		}
		void Update(const double& delta)
		{
			player->Update(delta);
			player2->Update(delta);
		}
		void Render(Renderer& renderer)
		{
			renderer.Render(player);
			renderer.Render(player2);
		}
		void Clear()
		{

		}
	};
}