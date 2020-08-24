#pragma once

#include <SDL.h>
#include <memory>
#include <tuple>

#include "Sprite.h"

namespace Helio
{
	class Button : public Sprite
	{
	public:
		Button(std::shared_ptr<Texture> text, SDL_Rect rct, int x, int y) 
			: Sprite(text, rct)
		{
			rect.x = x;
			rect.y = y;
		}

		void Events(Event& events)
		{
			if (events.GetMouseButton(MouseButtton::LEFT))
			{
				auto [xMousePos, yMousePos] = events.GetMousePos();
			
				if (xMousePos >= rect.x && xMousePos <= (rect.x + rect.w) &&
					yMousePos >= rect.y && yMousePos <= (rect.y + rect.h))
				{
					LOG_ERROR("INSIDE");
				}
				else
				{
					LOG_ERROR("OUTSIDE");
				}

			}
		}

		void Update()
		{

		}
	};
}

/*
* On verra plus tard si on peut faire un truc comme ca
Button button(x, y, sprite)

button.onHover(() => {
	dsfdfsdf
});

button.onClick(() => {
	dsfdfsdf
});
*/