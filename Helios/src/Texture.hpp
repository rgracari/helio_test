#pragma once

#include <SDL.h>
#include <string>

namespace Helio
{
	class Texture
	{
	private:
		SDL_Texture* texture = NULL;

	public:
		Texture() {}
		Texture(SDL_Texture* tex);
		
		void LoadFromFile(const std::string& path);
		
		~Texture();
	};
}