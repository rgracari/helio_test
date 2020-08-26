#pragma once

#include <SDL.h>

namespace Helio
{
	class File
	{
	private:
		SDL_RWops* file;
	
	public:
		File(SDL_RWops* f) : file(f)
		{
			/*
			SDL_RWops* fileItem = SDL_RWFromFile("assets/data/things.txt", "rb");
			if (fileItem != NULL)
			{
				LOG_ERROR("HERE");
				char name[256];
				SDL_RWread(fileItem, name, sizeof(name), 1);
				std::cout << name << std::endl;
				//SDL_RWwrite(fileItem, t.c_str(), t.size(), 1);
				SDL_RWclose(fileItem);
			}*/
		}

		~File()
		{
			if (file != NULL)
				SDL_RWclose(file);
		}
	};
}