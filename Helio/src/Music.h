#pragma once

#include <SDL_mixer.h>

namespace Helio
{
	class Music
	{
	private:
		Mix_Music* music;
	public:
		Music(Mix_Music* ms) : music(ms) {}

		Mix_Music* GetMusic()
		{
			return music;
		}

		~Music()
		{
			Mix_FreeMusic(music);
			music = NULL;
		}
	};
}