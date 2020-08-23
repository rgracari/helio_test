#include <SDL.h>
#include <SDL_image.h>
#include <memory>

#include "Log.h"
#include "Engine.h"
#include "Renderer.h"

bool isRunning = true;

void Run()
{
	std::unique_ptr<Helio::Engine> engine = std::make_unique<Helio::Engine>();
	
	engine->Init();
	while (engine->IsRunning())
	{
		engine->Event();
		engine->Update();
		engine->Render();
	}
	engine->Clear();
}

int main(int argc, char* argv[])
{
	// Pour chaque il faudrait tester si OK
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
	{
		LOG_ERROR("SDL unable to init: ");
		LOG_ERROR(SDL_GetError());
		return -1;
	}

	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
	{
		LOG_ERROR("Warning: Linear texture filtering not enabled!\n");
	}

	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		LOG_ERROR("SDL_image could not initialize! SDL_image Error: %s\n");
	}

	Run();

	IMG_Quit();
	SDL_Quit();
	return 0;
}