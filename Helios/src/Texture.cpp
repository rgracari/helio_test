#include "Texture.hpp"

namespace Helio
{
	Texture::Texture(SDL_Texture* tex) : texture(tex)
	{
	}

	void Texture::LoadFromFile(const std::string& path)
	{

	}

	Texture::~Texture()
	{
		if (texture != NULL)
			SDL_DestroyTexture(texture);
	}
}