#pragma once

#include "../characters/Player.h"

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
				SceneManager<SceneName>::LoadScene(SceneName::Level2);
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