#pragma once
#include <SDL.h>

class Tile
{
public:
	Tile();
	void Update();
	void Draw();

private:
	SDL_Rect src;
	SDL_Rect dest;
	SDL_Texture* texture;
};

