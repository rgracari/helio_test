#pragma once

#include <iostream>
#include <memory>

#include "Event.h"
#include "Renderer.h"

namespace Helio
{
	class Engine
	{
	private:
		bool isRunning = true;

	public:
		Engine()
		{
			Renderer::Get().Render("RENDER THIS TEXTURE");
		}

		void Init()
		{
		}

		void Event()
		{
			//Event::SetEvents();
			Event::Get().Listen(isRunning);
			//SceneManager::Get().Event();
		}

		void Update()
		{
			//SceneManager::Get().Update();
		}

		void Render()
		{
			Renderer::Get().ClearRenderer();
			Renderer::Get().UpdateRenderer();
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