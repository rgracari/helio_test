#include <iostream>

#include <Helio.h>

#include "Config.h"

#include "scenes/Level1.h"
#include "scenes/Level2.h"

namespace Helio
{
	class Game : public Engine
	{
	private:
		Event events;
		Window window;
		Renderer renderer;
		Files files;
		Clock clock;
		double deltaTime;

	public:
		Game()
		{
			window.Init("Helio Engine", 1280, 720);
			renderer.Init(window);
			renderer.SetRenderLogicalSize(320, 180);
			files.Init(&renderer);
		}

		void Init()
		{
			std::unordered_map<SceneName, std::shared_ptr<Scene>> scenes;
			scenes[SceneName::Level1] = std::make_shared<Level1>();
			scenes[SceneName::Level2] = std::make_shared<Level2>();
			SceneManager<SceneName>::Init(scenes, &files);
			SceneManager<SceneName>::LoadScene(SceneName::Level1);
		}

		void Events()
		{
			events.Listen(isRunning, window);
			SceneManager<SceneName>::GetScene()->Events(events);
		}

		void Update()
		{
			deltaTime = clock.GetDeltaTime();
			SceneManager<SceneName>::GetScene()->Update(deltaTime);
		}

		void Render()
		{
			renderer.ClearRenderer();
			SceneManager<SceneName>::GetScene()->Render(renderer);
			renderer.UpdateRenderer();
		}

		void Clear()
		{
		}
	};
}

int main(int argc, char* argv[])
{
	std::shared_ptr<Helio::Game> game = std::make_shared<Helio::Game>();
	Helio::RunEngine(game);
	return 0;
}
