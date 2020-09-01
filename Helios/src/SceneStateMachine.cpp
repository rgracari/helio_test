#include "SceneStateMachine.hpp"

namespace Helio
{
	SceneStateMachine::SceneStateMachine()
		: scenes(0), currentScene(0), insertedSceneID(0) {}

	void SceneStateMachine::ProcessInput()
	{
		if (currentScene)
		{
			currentScene->ProcessInput();
		}
	}

	void SceneStateMachine::Update(double deltaTime)
	{
		if (currentScene)
		{
			currentScene->Update(deltaTime);
		}
	}

	void SceneStateMachine::LateUpdate(double deltaTime)
	{
		if (currentScene)
		{
			currentScene->LateUpdate(deltaTime);
		}
	}

	void SceneStateMachine::Draw()
	{
		if (currentScene)
		{
			currentScene->Draw();
		}
	}

	unsigned int SceneStateMachine::Add(std::shared_ptr<Scene> scene)
	{
		auto inserted = scenes.insert(std::make_pair(insertedSceneID, scene));
		insertedSceneID++;
		inserted.first->second->OnCreate();
		return insertedSceneID - 1;
	}

	void SceneStateMachine::Remove(unsigned int id)
	{
		auto it = scenes.find(id);
		if (it != scenes.end())
		{
			if (currentScene == it->second)
			{
				currentScene = nullptr;
			}
		}
		it->second->OnDestroy();
		scenes.erase(it);
	}

	void SceneStateMachine::SwitchTo(unsigned int id)
	{
		auto it = scenes.find(id);
		if (it != scenes.end())
		{
			if (currentScene)
			{
				currentScene->OnDeactivate();
			}
			currentScene = it->second;
			currentScene->OnActivate();
		}
	}
}