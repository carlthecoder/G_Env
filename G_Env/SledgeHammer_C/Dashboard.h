#pragma once
#ifndef TANK_DASHBOARD_H
#define TANK_DASHBOARD_H

#include "RenderSystem.h"

typedef struct Dashboard_t
{
	Sprite* background;
	Sprite* playMenu;
	Sprite* optionsMenu;
	Sprite* exitMenu;
} Dashboard;

Dashboard* Dashboard_Create(SDL_Renderer*);
void Dashboard_Update(Dashboard*);
void Dashboard_Draw(Dashboard*, SDL_Renderer*);
void Dashboard_Destroy(Dashboard*);

#endif // !TANK_DASHBOARD_H