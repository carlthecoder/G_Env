#pragma once
#include <SDL.h>

class TextureManager
{
public:
	static SDL_Texture* LoadTexture(const char* filePath);

	static void Render(SDL_Texture* texture, SDL_Rect* src, SDL_Rect* dst);
};