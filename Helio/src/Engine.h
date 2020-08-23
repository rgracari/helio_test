#pragma once

#include <iostream>
#include <memory>
#include <string>

#include "../game/Level1.h"
#include "Event.h"
#include "Renderer.h"
#include "Log.h"
#include "Files.h"

namespace Helio
{
	class Engine
	{
	private:
		bool isRunning = true;
		Event events;
		Renderer renderer;
		Level1 level1;
		Files files;

	public:
		Engine() : files(renderer)
		{
		}

		void Init()
		{
			level1.Load(files);
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