#include <SDL_image.h>

#include "Texture.hpp"
#include "Renderer.hpp"

namespace Helio
{
	Texture::Texture()
	{
		std::cout << "Texture created" << std::endl;
	}

	SDL_Surface* Texture::GetSDLSurface()
	{
		return surface;
	}

	SDL_Texture* Texture::GetSDLTexture()
	{
		return texture;
	}

	void Texture::LoadFromFile(const std::string& path)
	{
		SDL_Surface* imageSurface = IMG_Load(path.c_str());
		if (imageSurface == NULL)
		{
			std::cout << "Unable to load image " << path.c_str() << "! SDL_image Error: " << IMG_GetError() << std::endl;
		}
		surface = imageSurface;
		texture = SDL_CreateTextureFromSurface(Renderer::Get().GetSDLRenderer(), imageSurface);
		if (texture == NULL)
		{
			std::cout << "CreateTextureFromSurface failed :" << SDL_GetError() << std::endl;
		}
	}

	Texture::~Texture()
	{
		if (surface != NULL)
		{
			std::cout << "Surface Freed" << std::endl;
			SDL_FreeSurface(surface);
			surface = NULL;
		}
		if (texture != NULL)
		{
			std::cout << "Texture Freed" << std::endl;
			SDL_DestroyTexture(texture);
			texture = NULL;
		}
	}
}