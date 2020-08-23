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
			renderer.Render(tex);
		}
		void Clear()
		{

		}
	};
}