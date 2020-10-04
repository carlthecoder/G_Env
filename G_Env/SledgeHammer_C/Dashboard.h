#pragma once
#ifndef TANK_DASHBOARD_H
#define TANK_DASHBOARD_H

#include "GameStates.h"
#include "RenderSystem.h"

typedef struct Dashboard_t
{
	Sprite* background;
	Sprite* playMenu;
	Sprite* optionsMenu;
	Sprite* exitMenu;
} Dashboard;

Dashboard* Dashboard_Create(SDL_Renderer*);
void Dashboard_Update(Dashboard* menu, GameStates* gameState, SDL_Point cursorLocation, Uint32 mouseState);
void Dashboard_Draw(Dashboard*, SDL_Renderer*);
void Dashboard_Destroy(Dashboard*);

#endif // !TANK_DASHBOARD_H