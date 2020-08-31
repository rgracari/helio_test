#include "Renderer.hpp"

namespace Helio
{
	Renderer::Renderer(const std::string& windowName)
		: window(windowName)
	{
		std::cout << "Renderer Created" << std::endl;

		renderer = SDL_CreateRenderer(window.GetSDLWindow(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (renderer == NULL)
			std::cout << "Could not create Renderer: " << SDL_GetError() << std::endl;
	}

	Renderer& Renderer::Get()
	{
		return instance;
	}

	SDL_Renderer* Renderer::GetSDLRenderer()
	{
		return renderer;
	}

	void Renderer::Update()
	{
		SDL_Event events;
		while (SDL_PollEvent(&events))
		{
			switch (events.type)
			{
				case SDL_QUIT:
				{
					std::cout << "EVENT: CLOSE WINDOW" << std::endl;
					isOpen = false;
				}
			}
		}
	}

	void Renderer::BeginDraw()
	{
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);
	}

	void Renderer::Draw(Sprite& sprite)
	{
		SDL_RenderCopy(renderer, sprite.GetSDLTexture(), NULL, sprite.GetSDLRect());
	}
	
	void Renderer::EndDraw()
	{
		SDL_RenderPresent(renderer);
	}
	
	bool Renderer::IsOpen() const
	{
		return isOpen;
	}

	Renderer::~Renderer()
	{
		std::cout << "Renderer Destroyed" << std::endl;
		if (renderer != NULL)
		{
			SDL_DestroyRenderer(renderer);
			renderer = NULL;
		}
	}
}