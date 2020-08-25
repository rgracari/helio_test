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
			//events.
		}

		~Input()
		{
			SDL_StopTextInput();
		}
	};
}