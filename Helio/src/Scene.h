#pragma once

namespace Helio
{
	class Scene
	{
	public:
		virtual void Event() = 0;
		virtual void Update() = 0;
		virtual void Render() = 0;
		virtual ~Scene() = 0;
	};
}