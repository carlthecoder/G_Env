#pragma once
#ifndef TANK_RENDERSYS_H
#define TANK_RENDERSYS_H

#include "Sprite.h"
#include "Helpers.h"
#include <SDL.h>
#include <SDL_image.h>

SDL_Texture* LoadTexture(char* filePath, SDL_Renderer* renderer);

void InitializeSprite(Sprite* sprite,
	char* filePath,
	Vector2D position,
	Vector2D sheetSize,
	Vector2D textureSize,
	Vector2D currentFrame,
	SDL_Point anchor,
	double angle,
	double scale,
	SDL_Renderer*);

void DrawSprite(Sprite* sprite, SDL_Renderer*);
void DestroySprite(Sprite* sprite);

#endif // !TANK_RENDERSYS_H