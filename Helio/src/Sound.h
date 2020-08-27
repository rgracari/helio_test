#pragma once

#include <SDL_mixer.h>

namespace Helio
{
	class Sound
	{
	private:
		Mix_Chunk* sound;

	public:
		Sound(Mix_Chunk* s) : sound(s) {}

		void Play()
		{
			Mix_PlayChannel(-1, sound, 0);
		}

		~Sound()
		{
			Mix_FreeChunk(sound);
			sound = NULL;
		}
	};
}