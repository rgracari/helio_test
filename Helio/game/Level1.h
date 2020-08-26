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
		std::shared_ptr<Font> lazyFont;
		std::shared_ptr<Input> input;

	public:
		void Load(Files& file)
		{
			auto [textureBack, rectBack] = file.LoadSpriteFromPNG("assets/images/cc.png");
			background = std::make_shared<Sprite>(textureBack, rectBack);
			
			auto [texture, rect] = file.LoadSpriteFromPNG("assets/images/dots.png");
			player = std::make_shared<Player>(texture, rect);

			lazyFont = file.LoadFontFromTTF("assets/fonts/lazy.ttf", 28);
			std::shared_ptr<Text> text = std::make_shared<Text>("Salut les gens", lazyFont);
			
			input = std::make_shared<Input>(text);
			
		}
		void Events(Event& events)
		{
			input->Events(events);
			player->Events(events);
		}
		void Update()
		{
			player->Update();
		}
		void Render(Renderer& renderer)
		{
			renderer.Render(background);
			renderer.Render(player);
			renderer.Render(input->GetText());
		}
		void Clear()
		{

		}
	};
}