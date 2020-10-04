#pragma once
#ifndef TANK_GAME_H
#define TANK_GAME_H

#include "Dashboard.h"
#include "GameStates.h"
#include <SDL.h>
#include <stdio.h>

typedef struct GameManager_t
{
	SDL_Renderer* renderer;
	GameStates gameState;
	Dashboard* dashboard;
} GameManager;

GameManager* Game_Startup(SDL_Renderer*);
void Game_LoadContent(GameManager*);
void Game_Update(GameManager*, int* engineRunning);
void Game_Draw(GameManager*);
void Game_SetState(GameManager*, GameStates);
void Game_Destroy(GameManager*);

#endif // !TANK_GAME_H
