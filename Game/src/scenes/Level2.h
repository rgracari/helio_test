#pragma once

#include "../characters/Player.h"

namespace Helio
{
	class Level2 : public Scene
	{
	private:
		std::shared_ptr<Player> player;

	public:
		void Load(Files& file)
		{
			auto [texture, rect] = file.LoadSpriteFromPNG("assets/images/archer.png");
			player = std::make_shared<Player>(texture, rect);
		}
		void Events(Event& events)
		{
			if (events.GetKeyDown(SDLK_t))
			{
				SceneManager<SceneName>::LoadScene(SceneName::Level1);
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