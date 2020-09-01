#pragma once


namespace Helio
{
	class Object;

	class Component
	{
	protected:
		Object* owner;

	public:
		Component(Object* owner) : owner(owner) {}

		virtual void Awake() {};
		virtual void Start() {};

		virtual void Update(double deltaTime) {};
		virtual void LateUpdate(double deltaTime) {};
		virtual void Draw() {};
	};
}
