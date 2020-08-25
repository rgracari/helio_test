#pragma once

#include "Event.h"
#include "Renderer.h"
#include "Files.h"
#include "Button.h"
#include "Timer.h"
#include "Text.h"
#include "Input.h"

namespace Helio
{
	class Scene
	{
	public:
		virtual void Load(Files& file) = 0;
		virtual void Events(Event& events) = 0;
		virtual void Update() = 0;
		virtual void Render(Renderer& renderer) = 0;
		virtual void Clear() = 0;
		virtual ~Scene()
		{
		};
	};
}