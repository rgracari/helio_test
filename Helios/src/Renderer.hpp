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

		Vector2 GetCenter()
		{
			int w;
			int h;
			SDL_GetWindowSize(window.GetSDLWindow(), &w, &h);
			return Vector2(w / 2, h / 2);
		}

		~Renderer();


	public:
		static Renderer instance;
	
	private:
		bool isOpen = true;
		Window window;
		SDL_Renderer* renderer = NULL;
	};
}
