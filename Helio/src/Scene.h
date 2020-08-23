#pragma once

#include "Event.h"
#include "Renderer.h"

namespace Helio
{
	class Scene
	{
	public:
		virtual void Load() = 0;
		virtual void Events(Event& events) = 0;
		virtual void Update() = 0;
		virtual void Render(Renderer& renderer) = 0;
		virtual void Clear() = 0;
		virtual ~Scene()
		{
		};
	};
}