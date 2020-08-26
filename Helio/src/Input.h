#pragma once

#include <SDL.h>
#include <memory>

#include "Text.h"

namespace Helio
{
	class Input
	{
	private:
		std::shared_ptr<Text> text;

	public:
		Input(std::shared_ptr<Text> txt) : text(txt)
		{
			SDL_StartTextInput();
		}

		void Events(Event& events)
		{
			for (const SDL_Keycode& key : events.GetKeysDown())
			{
				if (key == SDLK_BACKSPACE && text->GetText().length() > 1)
				{
					text->GetText().pop_back();
				}
				if (key == SDLK_c && SDL_GetModState() & KMOD_CTRL)
				{
					SDL_SetClipboardText(text->GetText().c_str());
				}
				if (key == SDLK_v && SDL_GetModState() & KMOD_CTRL)
				{
					text->GetText().append(SDL_GetClipboardText());
				}
			}
		}

		std::shared_ptr<Text>& GetText()
		{
			return text;
		}

		~Input()
		{
			SDL_StopTextInput();
		}
	};
}