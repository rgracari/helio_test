#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include <memory>

#include "Constants.h"
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
		engine->Events();
		engine->Update();
		engine->Render();
	}
	engine->Clear();
}

int main(int argc, char* argv[])
{
	// Pour chaque il faudrait tester si OK
	if (SDL_Init(Helio::INIT_SDL_FLAGS) > 0)
	{
		LOG_ERROR("SDL unable to init: ");
		LOG_ERROR(SDL_GetError());
		return -1;
	}

	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
	{
		LOG_ERROR("Warning: Linear texture filtering not enabled!\n");
	}

	int imgFlags = Helio::INIT_IMG_FLAGS;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		LOG_ERROR("SDL_image could not initialize! SDL_image Error: %s\n");
	}

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		LOG_ERROR("SDL_mixer could not initialize! SDL_mixer Error: %s\n");
	}

	if (TTF_Init() == -1)
	{
		LOG_ERROR("SDL_ttf could not initialize! SDL_ttf Error: %s");
	}

	Run();

	TTF_Quit();
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();
	return 0;
}