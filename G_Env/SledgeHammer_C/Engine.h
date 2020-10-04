#pragma once
#ifndef TANK_ENGINE_H
#define TANK_ENGINE_H

#include "GameManager.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Engine_t
{
	SDL_Window* window;
	SDL_Renderer* renderer;
	GameManager* game;
	int running;
} Engine;

/// <summary>
/// Creates the SDL_Window and the SDL_Renderer for the game.
/// </summary>
/// <param name="windowTitle">The title text of the window.</param>
/// <param name="width">The width of the game screen.</param>
/// <param name="height">The height of the game screen.</param>
/// <param name="fullscreen">Play in fullscreen mode.</param>
/// <returns></returns>
Engine* Engine_Ignite(char* windowTitle, uint16_t width, uint16_t height, bool fullscreen);

/// <summary>
/// Initializes the Game System and loads the game content.
/// </summary>
void Engine_InitializeGameSystem(Engine*);

/// <summary>
/// Initializes the framerate and runs the game loop.
/// </summary>
void Engine_Run(Engine*);

/// <summary>
/// Destroys the engine by destroying the game, the renderer and the window.
/// </summary>
void Engine_Destroy(Engine*);

#endif // !TANK_ENGINE_H
