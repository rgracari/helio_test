#pragma once

#include "../Scene.hpp"
#include "../Input.hpp"
#include "../Object.hpp"
#include "../C_Sprite.hpp"

namespace Helio
{
	class SceneGame : public Scene
	{
	private:
		Input input;
		std::shared_ptr<Object> player;

	public:
		SceneGame();

		void OnCreate() override;
		void OnDestroy() override;

		void ProcessInput() override;
		void Update(double deltaTime) override;
		void Draw() override;
	};
}