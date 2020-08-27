#include "Engine.h"
#include "Clock.h"
#include "Collider.h"

namespace Helio
{
	void RunEngine(std::shared_ptr<Engine> engine)
	{
		engine->Init();
		while (engine->IsRunning())
		{
			engine->Events();
			engine->Update();
			engine->Render();
		}
		engine->Clear();
	}

	void Clear()
	{
		TTF_Quit();
		Mix_Quit();
		IMG_Quit();
		SDL_Quit();
	}

	void Setup()
	{
		if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK | SDL_INIT_AUDIO) > 0)
		{
			LOG_ERROR("SDL unable to init: ");
			LOG_ERROR(SDL_GetError());
		}

		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0"))
		{
			LOG_ERROR("Warning: Linear texture filtering not enabled!\n");
		}

		int imgFlags = IMG_INIT_PNG;
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
	}
}
