#include "Helpers.h"

void Helpers_SDLRectInitialize(SDL_Rect* rect, Uint32 x, Uint32 y, Uint32 width, Uint32 height)
{
	rect->x = x;
	rect->y = y;
	rect->w = width;
	rect->h = height;
}