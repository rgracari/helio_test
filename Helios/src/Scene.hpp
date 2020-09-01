#pragma once

namespace Helio
{
	class Scene
	{
	public:
		virtual void OnCreate() = 0;

		virtual void OnDestroy() = 0;
		
		virtual void OnActivate() {};

		virtual void OnDeactivate() {};

		virtual void ProcessInput() {};
		virtual void Update(double deltaTime) {};
		virtual void LateUpdate(double deltaTime) {};
		virtual void Draw() {};
	};
}