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
		std::shared_ptr<Text> text;

	public:
		void Load(Files& file)
		{
			auto [textureBack, rectBack] = file.LoadSpriteFromPNG("assets/images/cc.png");
			background = std::make_shared<Sprite>(textureBack, rectBack);
			
			auto [texture, rect] = file.LoadSpriteFromPNG("assets/images/dots.png");
			player = std::make_shared<Player>(texture, rect);

			lazyFont = file.LoadFontFromTTF("assets/fonts/lazy.ttf", 28);
			text = std::make_shared<Text>("Salut les gens", lazyFont);
		}
		void Events(Event& events)
		{
			if (events.GetKeyDown(SDL_SCANCODE_E))
			{
				text->ChangeText("Il �tait une fois la vie");
			}
			player->Events(events);
		}
		void Update()
		{
			player->Update();
		}
		void Render(Renderer& renderer)
		{
			renderer.Render(background);
			renderer.Render(text);
			renderer.Render(player);
		}
		void Clear()
		{

		}
	};
}