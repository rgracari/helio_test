#pragma once

#include "Bitmask.hpp"

namespace Helio
{
	class Input
	{
	private:
		Bitmask thisFrameKeys;
		Bitmask lastFrameKeys;

	public:
		enum class Key
		{
			None = 0,
			ArrowLeft,
			ArrowRight,
			ArrowUp,
			ArrowDown,
			Esc
		};

		void Update();

		bool IsKeyPressed(Key keycode);
		bool IsKeyDown(Key keycode);
		bool IsKeyUp(Key keycode);
	};
}