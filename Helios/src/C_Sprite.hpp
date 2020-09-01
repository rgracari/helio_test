#pragma once

#include <string>

#include "Sprite.hpp"
#include "Texture.hpp"
#include "Component.hpp"

namespace Helio
{
	class C_Sprite : public Component
	{
	private:
		Texture texture;
		Sprite sprite;
	public:
		C_Sprite(Object* owner);

		void Load(const std::string& filePath);
		void Draw() override;
	};
}
