#include "Game.h"
#include <stdio.h>

Game* BootGame(SDL_Renderer* renderer)
{
	Game* game = malloc(sizeof(Game));
	game->renderer = renderer;
	game->gameState = GAMESTATE_MENU;
	game->menu = CreateMenu(renderer);

	return game;
}

void LoadGameContent(Game* game)
{
	
}

void UpdateGame(Game* game)
{
	if (game->gameState == GAMESTATE_MENU)
	{
		// Handle menu 
		UpdateMenu(game->menu);
	}
	else if (game->gameState == GAMESTATE_LOADING)
	{
		// Load game
	}
	else if (game->gameState == GAMESTATE_PLAYING)
	{
		// Update game
	}
	else if (game->gameState == GAMESTATE_PAUSED)
	{
		// hold updates
	}
	else if (game->gameState == GAMESTATE_OVER)
	{
		// Draw result screen
	}
}

void DrawGame(Game* game)
{
	if (game->gameState == GAMESTATE_MENU)
	{
		// Draw menu
		DrawMenu(game->menu, game->renderer);
	}
	else if (game->gameState == GAMESTATE_LOADING)
	{
		// Load game
	}
	else if (game->gameState == GAMESTATE_PLAYING)
	{
		// Draw game
	}
	else if (game->gameState == GAMESTATE_PAUSED)
	{
		// hold drawing // show overlay
	}
	else if (game->gameState == GAMESTATE_OVER)
	{
		// Draw result screen
	}
}

void SetGameState(Game* game, GameStates newState)
{
	game->gameState = newState;
}

void DestroyGame(Game* game)
{
	// Release and Destroy all game objects here:

	DestroyMenu(game->menu);

	// Release the game object itself:
	if (game)
	{
		free(game);
		game = NULL;
		printf("Game released, set to NULL. ");
	}

	printf("Game destroyed.\n");
}