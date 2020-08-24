#pragma once

#include "../src/Scene.h"

#include <SDL_mixer.h>

namespace Helio
{
	class Level1 : public Scene
	{
	private:
		std::shared_ptr<Button> button;
		std::shared_ptr<Music> music;
		
	public:
		void Load(Files& file)
		{
			auto [texture, rect] = file.LoadSpriteFromPNG("assets/images/dots.png");
			button = std::make_shared<Button>(texture, rect, 200, 200);

			music = file.LoadMusicFromFile("assets/musics/beat.wav");
		}
		void Events(Event& events)
		{
			if (events.GetKeyDown(SDL_SCANCODE_UP))
			{
				Mix_PlayMusic(music->GetMusic(), -1);
			}
			if (events.GetKeyDown(SDL_SCANCODE_DOWN))
			{
				Mix_PauseMusic();
			}
			if (events.GetKeyDown(SDL_SCANCODE_LEFT))
			{
				Mix_ResumeMusic();
			}
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