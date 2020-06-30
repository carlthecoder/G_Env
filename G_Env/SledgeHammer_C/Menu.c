#include "Menu.h"

static void InitializeMenu(Menu* menu, SDL_Renderer* renderer)
{
	Vector2D position = { 0 , 0 };
	Vector2D sheetSize = { 0, 0 };
	Vector2D textureSize = { 1920, 1080 };
	Vector2D currentFrame = { 0, 0 };
	SDL_Point anchor = { 0, 0 };
	double angle = 0;
	double scale = 0.75;

	menu->background = malloc(sizeof(Sprite));

	InitializeSprite(
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

Menu* CreateMenu(SDL_Renderer* renderer)
{
	Menu* menu = malloc(sizeof(Menu));

	InitializeMenu(menu, renderer);
	return menu;
}

void UpdateMenu(Menu* menu)
{

}

void DrawMenu(Menu* menu, SDL_Renderer* renderer)
{
	DrawSprite(menu->background, renderer);
}

void DestroyMenu(Menu* menu)
{
	if (menu)
	{
		DestroySprite(menu->background);
		//DestroySprite(menu->playMenu);
		//DestroySprite(menu->optionsMenu);
		//DestroySprite(menu->exitMenu);

		free(menu);
		menu = NULL;
		printf("Released menu set to NULL.\n");
	}
}