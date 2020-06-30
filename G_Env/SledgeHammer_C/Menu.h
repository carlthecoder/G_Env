#pragma once
#ifndef TANK_MENU_H
#define TANK_MENU_H


#include "RenderSystem.h"

//typedef struct Game_t Game;

typedef struct Menu_t
{
	Sprite* background;
	Sprite* playMenu;
	Sprite* optionsMenu;
	Sprite* exitMenu;
	//Game* game;
} Menu;

Menu* CreateMenu(SDL_Renderer*);
void UpdateMenu(Menu*);
void DrawMenu(Menu*, SDL_Renderer*);
void DestroyMenu(Menu*);

#endif // !TANK_MENU_H