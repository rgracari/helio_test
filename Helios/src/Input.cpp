#include <SDL.h>

#include "Input.hpp"

namespace Helio
{
	void Input::Update()
	{
		const uint8_t* keyboardState = SDL_GetKeyboardState(NULL);
		lastFrameKeys.SetMask(thisFrameKeys);

		thisFrameKeys.SetBit(int(Key::ArrowLeft), keyboardState[SDL_SCANCODE_LEFT]);
		thisFrameKeys.SetBit(int(Key::ArrowRight), keyboardState[SDL_SCANCODE_RIGHT]);
		thisFrameKeys.SetBit(int(Key::ArrowUp), keyboardState[SDL_SCANCODE_UP]);
		thisFrameKeys.SetBit(int(Key::ArrowDown), keyboardState[SDL_SCANCODE_DOWN]);
		thisFrameKeys.SetBit(int(Key::Esc), keyboardState[SDL_SCANCODE_ESCAPE]);
	}

	bool Input::IsKeyPressed(Key keycode)
	{
		return lastFrameKeys.GetBit((int)keycode);
	}

	bool Input::IsKeyDown(Key keycode)
	{
		bool lastFrame = lastFrameKeys.GetBit((int)keycode);
		bool thisFrame = lastFrameKeys.GetBit((int)keycode);
		return thisFrame && !lastFrame;
	}

	bool Input::IsKeyUp(Key keycode)
	{
		bool lastFrame = lastFrameKeys.GetBit((int)keycode);
		bool thisFrame = lastFrameKeys.GetBit((int)keycode);
		return !thisFrame && lastFrame;
	}
}