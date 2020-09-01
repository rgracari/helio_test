#include <iostream>

#include "Game.hpp"

int main(int argc, char* argv[])
{
	Helio::Game game;

	while (game.IsRunning())
	{
		game.CaptureEvent();
		game.ProcessInput();
		game.Update();
		game.LateUpdate();
		game.Draw();
		game.CalculateDeltaTime();
	}
	return 0;
}
