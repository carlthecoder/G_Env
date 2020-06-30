#pragma once
#include <SDL.h>

namespace RectHelpers
{
	/// <summary>
	/// Helper function for SDL_Rect, to set a rects coordinates and dimensions.
	/// </summary>
	void SetRect(SDL_Rect& rect, int x, int y, int w, int h);

	/// <summary>
	/// Helper function for SDL_Rect, to set a rects dimensions.
	/// </summary>
	void SetRectDimensions(SDL_Rect& rect, int w, int hy);

	/// <summary>
	/// Helper function for SDL_Rect, to set a rects coordinates.
	/// </summary>
	void SetRectPosition(SDL_Rect& rect, int x, int y);
};