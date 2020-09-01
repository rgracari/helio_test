#include "SceneSplashScreen.hpp"

#include "../Renderer.hpp"

#include "../Path.hpp"

namespace Helio
{
	SceneSplashScreen::SceneSplashScreen(SceneStateMachine& sceneStateMachine)
		: sceneStateMachine(sceneStateMachine),
		  switchToState(0),
		  currentSeconds(0.0),
		  showForSeconds(3.0) {}

	void SceneSplashScreen::OnCreate()
	{
		splashTexture.LoadFromFile(std::string(Path::imageFolder) + "idle.png");
		splashSprite.SetTexture(splashTexture);
		Vector2 center = Renderer::Get().GetCenter();
		splashSprite.SetPosition(center);
	}

	void SceneSplashScreen::OnDestroy() { }

	void SceneSplashScreen::OnActivate()
	{
		currentSeconds = 0.0;
	}

	void SceneSplashScreen::SetSwitchToScene(unsigned int id)
	{
		switchToState = id;
	}

	void SceneSplashScreen::Update(double deltaTime)
	{
		currentSeconds += deltaTime;
		if (currentSeconds >= showForSeconds)
		{
			sceneStateMachine.SwitchTo(switchToState);
		}
	}

	void SceneSplashScreen::Draw()
	{
		Renderer::Get().Draw(splashSprite);
	}
}