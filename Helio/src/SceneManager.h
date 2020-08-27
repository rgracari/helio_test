#pragma once

#include <unordered_map>

#include "Scene.h"

namespace Helio
{
	template<typename T>
	class SceneManager
	{
	private:
		static std::unordered_map<T, std::shared_ptr<Scene>> scenes;
		static std::shared_ptr<Scene> currentScene;
		static Files* files;

	public:
		static void Init(std::unordered_map<T, std::shared_ptr<Scene>> sc, Files* fl)
		{
			scenes = sc;
			files = fl;
		}

		static void LoadScene(T sceneName)
		{
			if (scenes.find(sceneName) == scenes.end())
			{
				LOG_ERROR("The scenes doesn't exist or isn't registered");
				return;
			}
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
	template<typename T>
	std::unordered_map<T, std::shared_ptr<Scene>> SceneManager<T>::scenes;
	template<typename T>
	std::shared_ptr<Scene> SceneManager<T>::currentScene = nullptr;
	template<typename T>
	Files* SceneManager<T>::files = nullptr;
}