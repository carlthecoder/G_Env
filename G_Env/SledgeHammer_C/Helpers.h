#pragma once
#ifndef TANK_HELPERS_H
#define TANK_HELPERS_H

#include <SDL.h>
#include <stdint.h>

void Helpers_SDLRectInitialize(SDL_Rect* rect, Uint32 x, Uint32 y, Uint32 width, Uint32 height);

#endif // !TANK_HELPERS_H