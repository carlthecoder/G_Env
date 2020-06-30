#include "RectHelpers.h"
#include "Sprite.h"
#include "SpriteManager.h"

extern SDL_Renderer* renderer;

Sprite::Sprite(const char* filePath, Vector2D position, Vector2D sheetsize, Vector2D texturesize, Vector2D currentframe, float angle, float scale, int anchorX, int anchorY)
	: pos { position }, sheetSize { sheetsize }, textureSize { texturesize }, currentFrame { currentframe }, angle { angle }
{
	anchor.x = anchorX;
	anchor.y = anchorY;
	texture = SpriteManager::LoadTexture(filePath);
	RectHelpers::SetRect(src, 0, 0, (int)textureSize.x, (int)textureSize.y);
	RectHelpers::SetRect(clip, 0, 0, (int)(textureSize.x* scale), (int)(textureSize.y* scale));
}

void Sprite::Update()
{
	++currentFrame.x;

	if (currentFrame.x > sheetSize.x)
	{
		currentFrame.x = 0;
		++currentFrame.y;
	}

	if (currentFrame.y >= sheetSize.y)
	{
		currentFrame.y = 0;
	}

	// to apply the animation we need to set the src rect to the current frame
	src.x = (int)(currentFrame.x * textureSize.x);
	src.y = (int)(currentFrame.y * textureSize.y);

	clip.x = (int)pos.x;
	clip.y = (int)pos.y;
}

void Sprite::Draw()
{
	SDL_RenderCopyEx(renderer, texture, &src, &clip, angle, &anchor, SDL_RendererFlip::SDL_FLIP_NONE);
}