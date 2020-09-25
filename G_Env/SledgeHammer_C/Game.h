#pragma once
#ifndef TANK_GAME_H
#define TANK_GAME_H

#include "Dashboard.h"
#include "GameStates.h"
#include <SDL.h>
#include <stdio.h>

typedef struct Game_t
{
	SDL_Renderer* renderer;
	GameStates gameState;
	Dashboard* dashboard;
} Game;

Game* Game_Startup(SDL_Renderer*);
void Game_LoadContent(Game*);
void Game_Update(Game*);
void Game_Draw(Game*);
void Game_SetState(Game*, GameStates);
void Game_Destroy(Game*);

#endif // !TANK_GAME_H
