#pragma once

#include <SDL_ttf.h>

namespace Helio
{
	class Font
	{
	private:
		TTF_Font* font = NULL;
		int fontSize;

	public:
		Font(TTF_Font* ft, int ftSize) : font(ft), fontSize(ftSize) {}

		TTF_Font* GetSDLFont()
		{
			return font;
		}

		~Font()
		{
			TTF_CloseFont(font);
		}
	};
}