#pragma once

#include "../characters/Player.h"

namespace Helio
{
	class Level1 : public Scene
	{
	private:
		std::shared_ptr<Player> player;
		std::shared_ptr<Tileset> tileset;
		std::shared_ptr<Tilemap> tilemap;
		std::shared_ptr<Music> music;
		std::vector<int> map1;

	public:
		void Load(Files& file)
		{
			auto [texture, rect] = file.LoadSpriteFromPNG("assets/images/mage.png");
			player = std::make_shared<Player>(texture, rect);

			auto [texture2, rect2] = file.LoadSpriteFromPNG("assets/images/background.png");
			tileset = std::make_shared<Tileset>(texture2, rect2, 16);

			std::vector<int> map1 = {
				1, 2, 3, 4, 5, 6, 7, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
				3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
				3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
				3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
				3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
				3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
				3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
				3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
				3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
				3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
				3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
				3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
			};

			tilemap = std::make_shared<Tilemap>(tileset, map1, 20, 11);
			music = file.LoadMusicFromFile("assets/music/chant.wav");
		}
		void Events(Event& events)
		{
			if (events.GetKeyDown(SDLK_v))
			{
				LOG_ERROR("PLAY");
				music->Play();
			}
			if (events.GetKeyDown(SDLK_p))
			{
				LOG_ERROR("Pause");
				music->Pause();
			}
			if (events.GetKeyDown(SDLK_r))
			{
				LOG_ERROR("Resume");
				music->Resume();
			}
			if (events.GetKeyDown(SDLK_h))
			{
				LOG_ERROR("Halt");
				music->Halt();
			}
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
			renderer.Render(tilemap);
			renderer.Render(player);
		}
		void Clear()
		{

		}
	};
}