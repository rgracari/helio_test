#include "Object.hpp"

namespace Helio
{
	void Object::Awake()
	{
		for (int i = components.size() - 1; i >= 0; i--)
		{
			components[i]->Awake();
		}
	}

	void Object::Start()
	{
		for (int i = components.size() - 1; i >= 0; i--)
		{
			components[i]->Start();
		}
	}

	void Object::Update(double deltaTime)
	{
		for (int i = components.size() - 1; i >= 0; i--)
		{
			components[i]->Update(deltaTime);
		}
	}

	void Object::LateUpdate(double deltaTime)
	{
		for (int i = components.size() - 1; i >= 0; i--)
		{
			components[i]->LateUpdate(deltaTime);
		}
	}

	void Object::Draw()
	{
		for (int i = components.size() - 1; i >= 0; i--)
		{
			components[i]->Draw();
		}
	}
}