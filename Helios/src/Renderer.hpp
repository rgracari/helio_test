#pragma once

#include <SDL.h>
#include <iostream>

#include "Window.hpp"
#include "Sprite.hpp"

namespace Helio
{
	class Renderer
	{
	public:
		Renderer(const Renderer&) = delete;
		Renderer(const std::string& windowName);

		static Renderer& Get();

		SDL_Renderer* GetSDLRenderer();

		void Update();

		void BeginDraw();
		void Draw(Sprite& sprite);
		void EndDraw();

		bool IsOpen() const;

		~Renderer();

	public:
		static Renderer instance;
	
	private:
		bool isOpen = true;
		Window window;
		SDL_Renderer* renderer = NULL;
	};
}
