#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include <memory>

#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>

#include "Event.h"
#include "Renderer.h"
#include "Font.h"
#include "Log.h"
#include "Files.h"
#include "SceneManager.h"

namespace Helio
{
	class Engine
	{
	protected:
		bool isRunning = true;

	public:
		Engine() {}

		virtual void Init() {}
		virtual void Events() {}
		virtual void Update() {}
		virtual void Render() {}
		virtual void Clear() {}
		bool IsRunning() { return isRunning; }

		virtual ~Engine() {}
	};
}