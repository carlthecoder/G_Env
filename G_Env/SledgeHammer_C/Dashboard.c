#include "Dashboard.h"

static void Dashboard_Initialize(Dashboard* menu, SDL_Renderer* renderer)
{
	Vector2D position = { 0 , 0 };
	Vector2D sheetSize = { 0, 0 };
	Vector2D textureSize = { 1920, 1080 };
	Vector2D currentFrame = { 0, 0 };
	SDL_Point anchor = { 0, 0 };
	double angle = 0;
	double scale = 0.75;

	menu->background = malloc(sizeof(Sprite));

	RenderSystem_InitializeSprite(
		menu->background,
		"Assets/menubackground.png",
		position,
		sheetSize,
		textureSize,
		currentFrame,
		anchor,
		angle,
		scale,
		renderer);
}

Dashboard* Dashboard_Create(SDL_Renderer* renderer)
{
	Dashboard* dashboard = malloc(sizeof(Dashboard));

	Dashboard_Initialize(dashboard, renderer);
	return dashboard;
}

void Dashboard_Update(Dashboard* menu)
{

}

void Dashboard_Draw(Dashboard* menu, SDL_Renderer* renderer)
{
	RenderSystem_DrawSprite(menu->background, renderer);
}

void Dashboard_Destroy(Dashboard* menu)
{
	if (menu)
	{
		RenderSystem_DestroySprite(menu->background);
		//DestroySprite(menu->playMenu);
		//DestroySprite(menu->optionsMenu);
		//DestroySprite(menu->exitMenu);

		free(menu);
		menu = NULL;
		printf("Released menu set to NULL.\n");
	}
}