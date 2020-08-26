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
		std::shared_ptr<Quadrilateral> rectangle;

	public:
		void Load(Files& file)
		{
			auto [textureBack, rectBack] = file.LoadSpriteFromPNG("assets/images/cc.png");
			background = std::make_shared<Sprite>(textureBack, rectBack);
			
			auto [texture, rect] = file.LoadSpriteFromPNG("assets/images/dots.png");
			player = std::make_shared<Player>(texture, rect);

			lazyFont = file.LoadFontFromTTF("assets/fonts/lazy.ttf", 28);
			text = std::make_shared<Text>("0 FPS", lazyFont, SDL_Color({ 255, 255, 0 }), Vector2({WINDOW_WIDTH - 150, 50}));

			rectangle = std::make_shared<Quadrilateral>(SDL_Rect({100, 100, 200, 200}), SDL_Color({255, 255, 0, 255}), false);
		}
		void Events(Event& events)
		{
			player->Events(events);
		}
		void Update(const double& delta)
		{
			text->ChangeText(std::to_string(int(1 / delta)) + " FPS");
			player->Update(delta);
		}
		void Render(Renderer& renderer)
		{
			renderer.Render(background);
			renderer.Render(rectangle);
			renderer.Render(player);
			renderer.Render(text);
		}
		void Clear()
		{

		}
	};
}