#include "Game.h"


Game* Game_Startup(SDL_Renderer* renderer)
{
	Game* game = malloc(sizeof(Game));
	if (game)
	{
		game->renderer = renderer;
		game->gameState = GAMESTATE_DASHBOARD;
		game->dashboard = Dashboard_Create(renderer);
	}

	return game;
}

void Game_LoadContent(Game* game)
{
	
}

void Game_Update(Game* game)
{
	if (game->gameState == GAMESTATE_DASHBOARD)
	{
		// Handle menu 
		Dashboard_Update(game->dashboard);
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
	else if (game->gameState == GAMESTATE_GAMEOVER)
	{
		// Draw result screen
	}
}

void Game_Draw(Game* game)
{
	if (game->gameState == GAMESTATE_DASHBOARD)
	{
		// Draw menu
		Dashboard_Draw(game->dashboard, game->renderer);
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
	else if (game->gameState == GAMESTATE_GAMEOVER)
	{
		// Draw result screen
	}
}

void Game_SetState(Game* game, GameStates newState)
{
	game->gameState = newState;
}

void Game_Destroy(Game* game)
{
	// Release and Destroy all game objects here:

	Dashboard_Destroy(game->dashboard);

	// Release the game object itself:
	if (game)
	{
		free(game);
		game = NULL;
		printf("Game released, set to NULL. ");
	}

	printf("Game destroyed.\n");
}