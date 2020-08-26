#pragma once

#include <iostream>
#include <memory>
#include <string>

#include "../game/Level1.h"
#include "Event.h"
#include "Renderer.h"
#include "Font.h"
#include "Log.h"
#include "Files.h"

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
		}

		void Init()
		{
			level1.Load(files);
		}

		void Events()
		{
			events.Listen(isRunning, window);
			//SceneManager::Get().Event();
			level1.Events(events);
		}

		void Update()
		{

			SDL_Delay(1);
			last_ticks = current_ticks;
			current_ticks = Time::GetTicks();
			delta = (current_ticks - last_ticks) * 0.001;

			level1.Update(delta);
		}

		void Render()
		{
			if (!window.IsMinimized())
			{
				renderer.ClearRenderer();
				level1.Render(renderer);
				renderer.UpdateRenderer();
			}
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