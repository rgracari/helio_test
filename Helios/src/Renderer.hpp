#pragma once

#include <SDL.h>
#include <iostream>

#include "Window.hpp"

namespace Helio
{
	class Renderer
	{
	public:
		Renderer(const Renderer&) = delete;

		static Renderer& Get();

		static void Set(const std::string& windowName);

		Renderer(const std::string& windowName);

		void Update();

		void BeginDraw();
		void Draw(SDL_Texture* texture);
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
