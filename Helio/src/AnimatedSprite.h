#pragma once

#include "Tileset.h"
#include "Time.h"

namespace Helio
{
	template<typename T>
	class AnimatedSprite
	{
	protected:
		double lastUpdate;
		double currentTime;
		SDL_Rect innerRect;
		SDL_Rect rect;
		std::shared_ptr<Tileset> tileset;
		std::unordered_map <T, std::tuple<std::vector<int>, int, bool>> animations;

	public:
		AnimatedSprite(std::shared_ptr<Tileset> tls) : tileset(tls)
		{
			lastUpdate = Time::GetTicks();
			currentTime = 0;
			innerRect = tileset->GetTiles()[0];
			rect = SDL_Rect({0, 0, tileset->GetTiles()[0].w, tileset->GetTiles()[0].h });
		}

		void SetAnimation(T animationName, std::tuple<std::vector<int>, int, bool> animationInfo)
		{
			animations[animationName] = animationInfo;
		}

		void Animate(T animationName)
		{
			if (animations.find(animationName) == animations.end())
			{
				LOG_ERROR("The animation name doesn't exist or isn't registered");
				return;
			}
			auto [spriteKey, time, repeat] = animations[animationName];
			if (time == 0)
			{
				innerRect = tileset->GetTiles()[spriteKey[0]];
			}
			else
			{
				double timePassed = TimePassed();
				if (timePassed > time * spriteKey.size() - 1)
				{
					if (repeat)
						ResetUpdate();
				}
				else
				{
					innerRect = tileset->GetTiles()[spriteKey[int(timePassed / time)]];
				}
			}
		}

		void ResetUpdate()
		{
			lastUpdate = Time::GetTicks();
		}

		SDL_Rect GetInnerRect()
		{
			return innerRect;
		}

		void SetInnerRect(int index)
		{
			innerRect = tileset->GetTiles()[index];
		}

		SDL_Rect GetRect()
		{
			return rect;
		}

		SDL_Texture* GetTexture()
		{
			return tileset->GetSDLTexture();
		}

		std::shared_ptr<Tileset> GetTileset()
		{
			return tileset;
		}

		double TimePassed()
		{
			currentTime = Time::GetTicks();
			return currentTime - lastUpdate;
		}

		void Flip(SDL_RendererFlip flipflag)
		{
			tileset->FlipTexture(flipflag);
		}

		~AnimatedSprite()
		{

		}
	};
}