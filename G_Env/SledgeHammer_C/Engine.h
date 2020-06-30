#pragma once
#ifndef TANK_ENGINE_H
#define TANK_ENGINE_H

#include "Menu.h"
#include "Game.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Engine_t
{
	SDL_Window* window;
	SDL_Renderer* renderer;
	Game* game;
} Engine;


Engine* BootEngine(char* windowTitle, uint16_t width, uint16_t height, bool fullscreen);
void InitializeGameSystem(Engine*);
void RunEngine(Engine*);
void DestroyEngine(Engine*);

#endif // !TANK_ENGINE_H
