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

	Game::~Game()
	{
		std::cout << "GAME DESTROYED" << std::endl;
	}
}
