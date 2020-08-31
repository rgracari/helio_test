#include "Game.hpp"

namespace Helio
{
	Renderer Renderer::instance("Helio game engine");

	Game::Game()
	{
		std::cout << "GAME CREATED" << std::endl;
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
		// all draw code here
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
