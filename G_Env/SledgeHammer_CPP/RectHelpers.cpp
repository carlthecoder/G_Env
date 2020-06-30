#include "RectHelpers.h"

namespace RectHelpers
{
	void SetRect(SDL_Rect& rect, int x, int y, int w, int h)
	{
		rect.x = x;
		rect.y = y;
		rect.w = w;
		rect.h = h;
	}

	void SetRectDimensions(SDL_Rect& rect, int w, int h)
	{
		rect.w = w;
		rect.h = h;
	}

	void SetRectPosition(SDL_Rect& rect, int x, int y)
	{
		rect.x = x;
		rect.y = y;
	}
}