#pragma once

#include "../SceneStateMachine.hpp"

#include "../Sprite.hpp"
#include "../Texture.hpp"

namespace Helio
{
	class SceneSplashScreen : public Scene
	{
	private:
		Texture splashTexture;
		Sprite splashSprite;
		SceneStateMachine& sceneStateMachine;
		double showForSeconds;
		double currentSeconds;
		unsigned int switchToState;

	public:
		SceneSplashScreen(SceneStateMachine& sceneStateMachine);

		void OnCreate() override;
		void OnDestroy() override;
		void OnActivate() override;

		void SetSwitchToScene(unsigned int id);

		void Update(double deltaTime) override;
		void Draw() override;
	};
}