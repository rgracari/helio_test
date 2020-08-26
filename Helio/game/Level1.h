#pragma once

//#include <SDL_mixer.h>

#include "../src/Scene.h"

#include "../src/SceneManager.h"

#include "Player.h"
#include "Player2.h"

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
			if (events.GetKeyDown(SDLK_t))
			{
				SceneManager::LoadScene(SceneName::Level2);
			}
			player->Events(events);
		}
		void Update(const double& delta)
		{
			player->Update(delta);
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