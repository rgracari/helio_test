#include "Game.hpp"

#include "Renderer.hpp"

namespace Helio
{
	Renderer Renderer::instance("Helio game engine");

	Game::Game()
	{
		std::cout << "GAME CREATED" << std::endl;
		vikingTexture.LoadFromFile("assets/images/idle.png");
		vikingSprite.SetTexture(vikingTexture);
	}

	void Game::Update()
	{
		Renderer::Get().Update();
		const int pixelPerSec = 100;
		Vector2 pos = vikingSprite.GetPosition();
		double frameMovement = pixelPerSec * deltaTime;
		std::cout << "FrameMovement:" << frameMovement << std::endl;
		vikingSprite.SetPosition(pos.x + frameMovement, pos.y);
	}

	void Game::LateUpdate()
	{
	}
	
	void Game::Draw()
	{
		Renderer::Get().BeginDraw();
		Renderer::Get().Draw(vikingSprite);
		Renderer::Get().EndDraw();
	}
	
	bool Game::IsRunning() const
	{
		return Renderer::Get().IsOpen();
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
