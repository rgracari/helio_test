#include "Game.hpp"

#include "Renderer.hpp"

namespace Helio
{
	Renderer Renderer::instance("Helio game engine");

	Game::Game() : deltaTime(0)
	{
		//std::shared_ptr<S
		std::shared_ptr<SceneSplashScreen> splashScreen =
			std::make_shared<SceneSplashScreen>(sceneStateMachine);

		std::shared_ptr<SceneGame> gameScene =
			std::make_shared<SceneGame>();

		unsigned int splashScreenID = sceneStateMachine.Add(splashScreen);
		unsigned int gameSceneID = sceneStateMachine.Add(gameScene);

		splashScreen->SetSwitchToScene(gameSceneID);
		sceneStateMachine.SwitchTo(splashScreenID);
	}

	void Game::ProcessInput()
	{
		sceneStateMachine.ProcessInput();
	}

	void Game::Update()
	{
		// there is nothing here yet
		Renderer::Get().Update();
		// ---
		sceneStateMachine.Update(deltaTime);
	}

	void Game::LateUpdate()
	{
		sceneStateMachine.LateUpdate(deltaTime);
	}
	
	void Game::Draw()
	{
		Renderer::Get().BeginDraw();
		sceneStateMachine.Draw();
		Renderer::Get().EndDraw();
	}

	void Game::CaptureEvent()
	{
		event.PollEvents();
	}
	
	bool Game::IsRunning()
	{
		return event.IsRunning();
	}

	void Game::CalculateDeltaTime()
	{
		deltaTime = clock.GetDeltaTime();
		std::cout << deltaTime << std::endl;
	}

	Game::~Game()
	{
		std::cout << "GAME DESTROYED" << std::endl;
	}
}
