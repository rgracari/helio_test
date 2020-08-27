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

		void Play()
		{
			if (Mix_PlayingMusic() == 0)
			{
				Mix_PlayMusic(music, -1);
			}
		}

		void Pause()
		{
			if (Mix_PlayingMusic())
			{
				LOG_ERROR("PauseHERE");
				Mix_PauseMusic();
			}
		}

		void Resume()
		{
			if (Mix_PausedMusic())
			{
				Mix_ResumeMusic();
			}
		}

		void Halt()
		{
			if (Mix_PlayingMusic())
			{
				Mix_HaltMusic();
			}
		}

		~Music()
		{
			Mix_FreeMusic(music);
			music = NULL;
		}
	};
}

/*
if (events.GetKeyDown(SDL_SCANCODE_UP))
{
	Mix_PlayMusic(music->GetMusic(), -1);
}
if (events.GetKeyDown(SDL_SCANCODE_DOWN))
{
	Mix_PauseMusic();
}
if (events.GetKeyDown(SDL_SCANCODE_LEFT))
{
	Mix_ResumeMusic();
}
*/