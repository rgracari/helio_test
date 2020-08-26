#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>

#include "../game/Level1.h"
#include "../game/Level2.h"

#include "Event.h"
#include "Renderer.h"
#include "Font.h"
#include "Log.h"
#include "Files.h"
#include "SceneManager.h"

namespace Helio
{
	class Engine
	{
	private:
		bool isRunning = true;
		Event events;
		Window window;
		Renderer renderer;
		Level1 level1;
		Files files;

		uint32_t last_ticks = 0;
		uint32_t current_ticks = Time::GetTicks();
		double delta = 0;

	public:
		Engine()
		{
			window.Init();
			renderer.Init(SDL_CreateRenderer(window.GetSDLWindow(), -1, RENDERER_MODE));
			files.Init(&renderer);
			SDL_RenderSetLogicalSize(renderer.GetSDLRenderer(), LOGICAL_WIDTH, LOGICAL_HEIGHT);
			
			// Setting up scenes

			std::unordered_map<SceneName, std::shared_ptr<Scene>> scenes;
			scenes[SceneName::Level1] = std::make_shared<Level1>();
			scenes[SceneName::Level2] = std::make_shared<Level2>();
			SceneManager::Init(scenes, &files);
		}

		void Init()
		{
			SceneManager::LoadScene(SceneName::Level1);
		}

		void Events()
		{
			events.Listen(isRunning, window);
			SceneManager::GetScene()->Events(events);
		}

		void Update()
		{
			delta = GetDeltaTime();
			SceneManager::GetScene()->Update(delta);
		}

		void Render()
		{
			if (!window.IsMinimized())
			{
				renderer.ClearRenderer();
				SceneManager::GetScene()->Render(renderer);
				renderer.UpdateRenderer();
			}
		}

		double GetDeltaTime()
		{
			SDL_Delay(1);
			last_ticks = current_ticks;
			current_ticks = Time::GetTicks();
			double delta = (current_ticks - last_ticks) * 0.001;
			return delta;
		}

		bool IsRunning()
		{
			return isRunning;
		}

		Renderer& GetRenderer()
		{
			return renderer;
		}

		void Clear()
		{
		}

		~Engine()
		{

		}
	};
}