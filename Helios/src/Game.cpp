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
		// there is nothing here yet
		Renderer::Get().Update();


		const Vector2 pos = vikingSprite.GetPosition();
		const int moveSpeed = 100;


		Vector2 velocity;
		if (input.IsKeyPressed(Input::Key::ArrowLeft))
		{
			velocity.x = -moveSpeed;
		}
		if (input.IsKeyPressed(Input::Key::ArrowRight))
		{
			velocity.x = moveSpeed;
		}
		if (input.IsKeyPressed(Input::Key::ArrowUp))
		{
			velocity.y = -moveSpeed;
		}
		if (input.IsKeyPressed(Input::Key::ArrowDown))
		{
			velocity.y = moveSpeed;
		}

		double xMouvement = velocity.x * deltaTime;
		double yMouvement = velocity.y * deltaTime;

		vikingSprite.SetPosition(pos.x + xMouvement, pos.y + yMouvement);
	}
	
	void Game::CaptureEvent()
	{
		event.PollEvents();
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
	
	bool Game::IsRunning()
	{
		return event.IsRunning();
	}

	void Game::CaptureInput()
	{
		input.Update();
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
