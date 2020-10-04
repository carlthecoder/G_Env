#include "GameManager.h"

GameManager* Game_Startup(SDL_Renderer* renderer)
{
	GameManager* gameManager = malloc(sizeof(GameManager));
	if (gameManager)
	{
		gameManager->renderer = renderer;
		gameManager->gameState = GAMESTATE_DASHBOARD;
		gameManager->dashboard = Dashboard_Create(renderer);
	}

	return gameManager;
}

void Game_LoadContent(GameManager* gameManager)
{	
}

void Game_Update(GameManager* gameManager, int* engineRunning)
{
	// Retrieve cursor location and the state of the keyboard and mouse;
	SDL_Point cursorLocation = { 0, 0 };
	Uint32 mouseState = SDL_GetMouseState(&cursorLocation.x, &cursorLocation.y);
	Uint8* keyboardState = SDL_GetKeyboardState(0);
	if (keyboardState[SDL_SCANCODE_ESCAPE])
	{
		gameManager->gameState = GAMESTATE_DASHBOARD;
	}

	// Update the game based on its state
	if (gameManager->gameState == GAMESTATE_DASHBOARD)
	{		
		Dashboard_Update(gameManager->dashboard, &gameManager->gameState, cursorLocation, mouseState);
	}
	else if (gameManager->gameState == GAMESTATE_PLAYING)
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
		Dashboard_Draw(gameManager->dashboard, gameManager->renderer);
	}
	else if (gameManager->gameState == GAMESTATE_PLAYING)
	{
	}
	else if (gameManager->gameState == GAMESTATE_GAMEOVER)
	{
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