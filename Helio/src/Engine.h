#pragma once

#include <iostream>
#include <memory>

#include "../game/Level1.h"
#include "Event.h"
#include "Renderer.h"

namespace Helio
{
	class Engine
	{
	private:
		bool isRunning = true;
		Event events;
		Renderer renderer;
		Level1 level1;

	public:
		Engine()
		{
			renderer.Render("RENDER THIS TEXTURE");
		}

		void Init()
		{
		}

		void Event()
		{
			events.Listen(isRunning);
			//SceneManager::Get().Event();
			level1.Events(events);
		}

		void Update()
		{
			//SceneManager::Get().Update();
			level1.Update();
		}

		void Render()
		{
			renderer.ClearRenderer();
			level1.Render(renderer);
			renderer.UpdateRenderer();
		}

		bool IsRunning()
		{
			return isRunning;
		}

		void Clear()
		{
		}

		~Engine()
		{

		}
	};
}