#include "Dashboard.h"

static void Dashboard_Initialize(Dashboard* dashboard, SDL_Renderer* renderer)
{
	Vector2D position = { 0 , 0 };
	Vector2D sheetSize = { 0, 0 };
	Vector2D textureSize = { 1920, 1080 };
	Vector2D currentFrame = { 0, 0 };
	SDL_Point anchor = { 0, 0 };
	double angle = 0;
	double scale = 0.75;

	dashboard->background = malloc(sizeof(Sprite));
	RenderSystem_InitializeSprite(
		dashboard->background,
		"Assets/menubackground.png",
		position,
		sheetSize,
		textureSize,
		currentFrame,
		anchor,
		angle,
		scale,
		renderer);

	scale = 0.5;

	position.x = 100;
	position.y = 100;
	textureSize.x = 390;
	textureSize.y = 130;
	dashboard->playMenu = malloc(sizeof(Sprite));
	RenderSystem_InitializeSprite(
		dashboard->playMenu,
		"Assets/newgame_menu.png",
		position,
		sheetSize,
		textureSize,
		currentFrame,
		anchor,
		angle,
		scale,
		renderer);

	position.x = 100;
	position.y = 230;
	textureSize.x = 390;
	textureSize.y = 130;
	dashboard->exitMenu = malloc(sizeof(Sprite));
	RenderSystem_InitializeSprite(
		dashboard->exitMenu,
		"Assets/exit_menu.png",
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

void Dashboard_Update(Dashboard* dashboard, GameStates* gameState, SDL_Point cursorLocation, Uint32 mouseState)
{
	if (mouseState == SDL_BUTTON(SDL_BUTTON_LEFT))
	{
		if (100 < cursorLocation.x && cursorLocation.x < 295 &&
			100 < cursorLocation.y && cursorLocation.y < 165)
		{
			*gameState = GAMESTATE_PLAYING;
		}

		else if (100 < cursorLocation.x && cursorLocation.x < 295 &&
			230 < cursorLocation.y && cursorLocation.y < 295)
		{
			*gameState = GAMESATE_EXITING;
		}
	}
}

void Dashboard_Draw(Dashboard* dashboard, SDL_Renderer* renderer)
{
	RenderSystem_DrawSprite(dashboard->background, renderer);
	RenderSystem_DrawSprite(dashboard->playMenu, renderer);
	RenderSystem_DrawSprite(dashboard->exitMenu, renderer);
}

void Dashboard_Destroy(Dashboard* dashboard)
{
	if (dashboard)
	{
		RenderSystem_DestroySprite(dashboard->background);
		RenderSystem_DestroySprite(dashboard->playMenu);
		RenderSystem_DestroySprite(dashboard->exitMenu);

		free(dashboard->background);
		free(dashboard->playMenu);
		free(dashboard->exitMenu);
		free(dashboard);

		dashboard = NULL;
		printf("Dashboard destroyed.\n");
	}
}