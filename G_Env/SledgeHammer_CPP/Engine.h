#pragma once
#include "Game.h"
#include <SDL.h>
#include <SDL_image.h>

SDL_Window* InitializeWindow(const char title[], int width, int height, int fullscreen);
SDL_Renderer* InitializeRenderer(SDL_Window* window);
int HandleEvents();
void Update(Game& game);
void Draw(SDL_Renderer* renderer, Game& game);
void DestroyEngine(SDL_Window* window, SDL_Renderer* renderer);