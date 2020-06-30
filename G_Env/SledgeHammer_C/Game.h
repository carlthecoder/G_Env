#pragma once
#ifndef TANK_GAME_H
#define TANK_GAME_H

#include "Menu.h"
#include "GameStates.h"
#include "Sprite.h"
#include <SDL.h>

typedef struct Game_t
{
	SDL_Renderer* renderer;
	GameStates gameState;
	Menu* menu;
} Game;

Game* BootGame(SDL_Renderer*);
void LoadGameContent(Game*);
void UpdateGame(Game*);
void DrawGame(Game*);
void SetGameState(Game*, GameStates);
void DestroyGame(Game*);

#endif // !TANK_GAME_H
