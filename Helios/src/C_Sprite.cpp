#include "C_Sprite.hpp"

#include "Renderer.hpp"

namespace Helio
{
	C_Sprite::C_Sprite(Object* owner) : Component(owner) {}

	void C_Sprite::Load(const std::string& filePath)
	{
		texture.LoadFromFile(filePath);
		sprite.SetTexture(texture);
	}

	void C_Sprite::Draw()
	{
		Renderer::Get().Draw(sprite);
	}
}