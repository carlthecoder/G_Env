#include "GameManager.h"


GameManager* Game_Startup(SDL_Renderer* renderer)
{
	GameManager* game = malloc(sizeof(GameManager));
	if (game)
	{
		game->renderer = renderer;
		game->gameState = GAMESTATE_DASHBOARD;
		game->dashboard = Dashboard_Create(renderer);
	}

	return game;
}

void Game_LoadContent(GameManager* gameManager)
{	
}

void Game_Update(GameManager* gameManager, int* engineRunning)
{
	// Retrieve cursor location and state
	SDL_Point cursorLocation = { 0, 0 };
	Uint32 mouseState = SDL_GetMouseState(&cursorLocation.x, &cursorLocation.y);

	// Update the game based on its state
	if (gameManager->gameState == GAMESTATE_DASHBOARD)
	{		
		Dashboard_Update(gameManager->dashboard, &gameManager->gameState, cursorLocation, mouseState);
	}
	else if (gameManager->gameState == GAMESTATE_LOADING)
	{
	}
	else if (gameManager->gameState == GAMESTATE_PLAYING)
	{
		
	}
	else if (gameManager->gameState == GAMESTATE_PAUSED)
	{
	}
	else if (gameManager->gameState == GAMESTATE_GAMEOVER)
	{
	}
	else if (gameManager->gameState == GAMESATE_EXITING)
	{
		*engineRunning = 0;
	}
}

void Game_Draw(GameManager* gameManager)
{
	if (gameManager->gameState == GAMESTATE_DASHBOARD)
	{
		// Draw menu
		Dashboard_Draw(gameManager->dashboard, gameManager->renderer);
	}
	else if (gameManager->gameState == GAMESTATE_LOADING)
	{
		// Load game
	}
	else if (gameManager->gameState == GAMESTATE_PLAYING)
	{
		// Draw game
	}
	else if (gameManager->gameState == GAMESTATE_PAUSED)
	{
		// hold drawing // show overlay
	}
	else if (gameManager->gameState == GAMESTATE_GAMEOVER)
	{
		// Draw result screen
	}
}

void Game_SetState(GameManager* gameManager, GameStates newState)
{
	gameManager->gameState = newState;
}

void Game_Destroy(GameManager* gameManager)
{
	// Release and Destroy all game objects here:
	Dashboard_Destroy(gameManager->dashboard);

	// Release the game object itself:
	if (gameManager)
	{
		free(gameManager);
		gameManager = NULL;
		printf("GameManager destroyed.\n");
	}
}