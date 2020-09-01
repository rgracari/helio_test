#pragma once

#include <SDL.h>
#include <memory>

#include "Texture.hpp"
#include "Sprite.hpp"
#include "Clock.hpp"
#include "Input.hpp"
#include "Event.hpp"

#include "SceneStateMachine.hpp"
#include "scenes/SceneSplashScreen.hpp"
#include "scenes/SceneGame.hpp"

namespace Helio
{
	class Game
	{
	private:
		Event event;
		Clock clock;
		double deltaTime;
		SceneStateMachine sceneStateMachine;

	public:
		Game();
		void CaptureEvent();
		//void CaptureInput();
		void ProcessInput();
		void Update();
		void LateUpdate();
		void Draw();
		void CalculateDeltaTime();
		bool IsRunning();
		~Game();
	};
}