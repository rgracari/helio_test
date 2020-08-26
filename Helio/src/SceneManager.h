#pragma once

#include <unordered_map>

#include "Scene.h"

namespace Helio
{
	class SceneManager
	{
	private:
		static std::unordered_map<SceneName, std::shared_ptr<Scene>> scenes;
		static std::shared_ptr<Scene> currentScene;
		static Files* files;

	public:
		static void Init(std::unordered_map<SceneName, std::shared_ptr<Scene>> sc, Files* fl)
		{
			scenes = sc;
			files = fl;
		}

		static void LoadScene(SceneName sceneName)
		{
			if (currentScene != nullptr)
			{
				currentScene->Clear();
			}
			currentScene = scenes[sceneName];
			currentScene->Load(*files);
		}

		static std::shared_ptr<Scene> GetScene()
		{
			return currentScene;
		}
	};
	std::unordered_map<SceneName, std::shared_ptr<Scene>> SceneManager::scenes;
	std::shared_ptr<Scene> SceneManager::currentScene = nullptr;
	Files* SceneManager::files = nullptr;
}