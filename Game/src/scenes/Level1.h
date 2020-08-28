#pragma once

#include "../characters/Player.h"
#include "../characters/Player2.h"

namespace Helio
{
	class Level1 : public Scene
	{
	private:
		std::shared_ptr<Player> player;
		std::shared_ptr<Player2> player2;
		std::shared_ptr<Tileset> tileset;
		std::shared_ptr<Tileset> player2Tileset;
		std::shared_ptr<Tilemap> tilemap;
		std::shared_ptr<Music> music;
		std::vector<int> map1;

	public:
		void Load(Files& file)
		{
			auto [texture, rect] = file.LoadSpriteFromPNG("assets/images/mage.png");
			player = std::make_shared<Player>(texture, rect);
			player->position.x = LOGICAL_WIDTH / 2;
			player->position.y = LOGICAL_HEIGHT - rect.h;


			auto [texture2, rect2] = file.LoadSpriteFromPNG("assets/images/background.png");
			tileset = std::make_shared<Tileset>(texture2, rect2, 16);

			auto [animatedSpriteText, animatedSpriteRect] = file.LoadSpriteFromPNG("assets/images/mage_animation.png");
			player2Tileset = std::make_shared<Tileset>(animatedSpriteText, animatedSpriteRect, 16);
			player2 = std::make_shared<Player2>(player2Tileset);

			//player2->PrintTilesRect();

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
			if (events.GetKeyDown(SDLK_h))
			{
				LOG_ERROR("Halt");
				music->Halt();
			}
			if (events.GetKeyDown(SDLK_t))
			{
				SceneManager<SceneName>::LoadScene(SceneName::Level2);
			}
			player2->Events(events);
			player->Events(events);
		}
		void Update(const double& delta)
		{
			player2->Update(delta);
			player->Update(delta);
		}
		void Render(Renderer& renderer)
		{
			//renderer.Render(tilemap);
			renderer.Render(player);
			renderer.Render<Player2Animation>(player2);
		}
		void Clear()
		{

		}
	};
}