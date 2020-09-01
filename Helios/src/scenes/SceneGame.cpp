#include "SceneGame.hpp"

#include "../Renderer.hpp"
#include "../Path.hpp"

namespace Helio
{
	SceneGame::SceneGame() {}

	void SceneGame::OnCreate()
	{
        player = std::make_shared<Object>();

        auto sprite = player->AddComponent<C_Sprite>();
        sprite->Load(std::string(Path::imageFolder) + "idle.png");
	}

	void SceneGame::OnDestroy()
	{
	}

	void SceneGame::ProcessInput()
	{
		input.Update();
	}

    void SceneGame::Update(double deltaTime)
    {
	}

	void SceneGame::Draw()
	{
		player->Draw();
	}
}