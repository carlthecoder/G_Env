#pragma once
#ifndef TANK_SPRITE_H
#define TANK_SPRITE_H

#include "Vector2D.h"
#include <SDL.h>

typedef struct Sprite_t
{
	SDL_Texture* texture;
	SDL_Rect src;
	SDL_Rect clip;
	SDL_Point anchor;
	double angle;

	Vector2D position;
	Vector2D sheetSize;
	Vector2D textureSize;
	Vector2D currentFrame;
} Sprite;


#endif // !TANK_SPRITE_H