#pragma once

#include <memory>
#include <unordered_map>

#include "Scene.hpp"

namespace Helio
{
	class SceneStateMachine
	{
	private:
		std::unordered_map<unsigned int, std::shared_ptr<Scene>> scenes;
		std::shared_ptr<Scene> currentScene;
		unsigned int insertedSceneID;

	public:
		SceneStateMachine();

		void ProcessInput();
		void Update(double deltaTime);
		void LateUpdate(double deltaTime);
		void Draw();

		unsigned int Add(std::shared_ptr<Scene> scene);
		void SwitchTo(unsigned int id);
		void Remove(unsigned int id);
	};
}
