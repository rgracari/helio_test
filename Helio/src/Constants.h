#pragma once

#include <string>

namespace Helio
{
	enum class SceneName
	{
		Level1 = 0,
		Level2,
	};

	constexpr uint32_t INIT_SDL_FLAGS = SDL_INIT_VIDEO | SDL_INIT_JOYSTICK | SDL_INIT_AUDIO;
	constexpr uint32_t INIT_IMG_FLAGS = IMG_INIT_PNG;
	constexpr const char* NAME = "Helio Engine";
	
	constexpr int WINDOW_X = SDL_WINDOWPOS_UNDEFINED;
	constexpr int WINDOW_Y = SDL_WINDOWPOS_UNDEFINED;
	constexpr int WINDOW_HEIGHT = 720;
	constexpr int WINDOW_WIDTH = 1280;
	constexpr uint32_t WINDOW_FLAGS = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;
	
	constexpr int RENDERER_BASE_COLOR = 0x55;
	constexpr uint32_t RENDERER_MODE = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	//constexpr uint32_t RENDERER_MODE = SDL_RENDERER_ACCELERATED;
	constexpr const char* RENDERER_HINT_SCALE_QUALITY = "0";
	constexpr int LOGICAL_WIDTH = WINDOW_WIDTH / 4;
	constexpr int LOGICAL_HEIGHT = WINDOW_HEIGHT / 4;
}