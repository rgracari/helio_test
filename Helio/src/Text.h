#pragma once

#include "Font.h"
#include <memory>
#include <string>

// Il doit render une texture que si le texte change et qu'il est créé
// Si le render essaye de le rendre mais qu'il n'a pas de texture alors il doit le
// creer et changer le bool

namespace Helio
{
	// Devrat peut etre extand de Sprite mais a voir
	class Text
	{
	public:
		bool hasChanged = true;
	
	private:
		std::string currentText;
		std::shared_ptr<Texture> texture;
		std::shared_ptr<Font> font;
		SDL_Color color;
		SDL_Rect rect;

	public:
		Text(const std::string& string, std::shared_ptr<Font> ft, SDL_Color clr = SDL_Color{ 0, 0, 0 }, Vector2 vec = { 0, 0 })
			: currentText(string), font(ft), color(clr), rect(SDL_Rect({vec.x, vec.y, 0, 0})) {}

		const std::string& GetText() const
		{
			return currentText;
		}

		std::string& GetText()
		{
			hasChanged = true;
			return currentText;
		}

		void ChangeText(const std::string& string)
		{
			currentText = string;
			hasChanged = true;
		}

		void SetTexture(std::shared_ptr<Texture> text)
		{
			texture = text;
		}

		std::shared_ptr<Texture> GetTexture()
		{
			return texture;
		}

		std::shared_ptr<Font> GetFont()
		{
			return font;
		}

		SDL_Rect& GetRect()
		{
			return rect;
		}

		SDL_Color& GetColor()
		{
			return color;
		}
	};
}