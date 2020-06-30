#pragma once
#include "Component.h"
#include <SDL.h>


class SpriteComponent : public Component
{
public:
	SpriteComponent(const char* spritePath, int width, int height);
	~SpriteComponent();

	void RegisterToRenderSystem();
	void UnregisterFromRenderSystem();

	bool operator==(SpriteComponent& ref)
	{
		if (*this == ref)
		{
			return true;
		}
		return false;
	}

	SDL_Rect Src;
	SDL_Rect Dest;
	SDL_Texture* Texture;
};