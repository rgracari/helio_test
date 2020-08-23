#pragma once

#include "../src/Scene.h"

namespace Helio
{
	class Level1 : public Scene
	{
	private:
		std::shared_ptr<Texture> tex;

	public:
		void Load(Files& file)
		{
			tex = file.LoadTextureFromPNG("assets/images/texture.png");
		}
		void Events(Event& events)
		{

		}
		void Update()
		{

		}
		void Render(Renderer& renderer)
		{
			/*
			SDL_Rect rect = {
				WINDOW_WIDTH / 3,
				WINDOW_HEIGHT / 6,
				WINDOW_WIDTH * 2 / 3,
				WINDOW_HEIGHT * 2 / 3
			};
			Shape shape = Shape(rect, 0xFF, 0xFF, 0x00, 0x05, true);
			*/
			//renderer.Render(&shape);
			
			renderer.Render(tex);
		}
		void Clear()
		{

		}
	};
}