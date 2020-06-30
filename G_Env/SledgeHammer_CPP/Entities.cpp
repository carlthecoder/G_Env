#include "Entities.h"

DrawableEntity::DrawableEntity(const char* filePath, Vector2D position,
	Vector2D sheetsize, Vector2D texturesize,
	Vector2D currentframe,
	float angle, float scale,
	int anchorX, int anchorY)
	:
	sprite { filePath, position, sheetsize,
			texturesize, currentframe, angle,
			scale, anchorX, anchorY }
{}