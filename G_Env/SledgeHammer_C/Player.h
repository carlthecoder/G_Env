#pragma once
#ifndef TANK_PLAYER_H
#define TANK_PLAYER_H

#include "Vector2D.h"
#include <SDL.h>
#include <stdbool.h>

typedef struct Player_t
{
	int x;
} Player;


void InitializePlayer(Player*);
void UpdatePlayer(Player*);
void DrawPlayer(Player*);

#endif // !TANK_PLAYER_H