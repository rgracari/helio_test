#pragma once

namespace Helio
{
	constexpr int WINDOW_X = SDL_WINDOWPOS_UNDEFINED;
	constexpr int WINDOW_Y = SDL_WINDOWPOS_UNDEFINED;
	constexpr int WINDOW_HEIGHT = 480;
	constexpr int WINDOW_WIDTH = 640;
	constexpr int RENDERER_BASE_COLOR = 0xFF;
	//constexpr uint32_t RENDERER_MODE = SDL_RENDERER_ACCELERATED;
	constexpr uint32_t RENDERER_MODE = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	constexpr const char* NAME = "Helio Engine";
}