#pragma once

#include <SDL_ttf.h>

namespace Helio
{
	class Font
	{
	private:
		TTF_Font* font = NULL;
		Texture* texture = NULL;
		std::string text = "";

	public:
		Font(TTF_Font* ft) : font(ft) {}

		TTF_Font* GetFont()
		{
			return font;
		}

		~Font()
		{
			TTF_CloseFont(font);
		}
	};
}