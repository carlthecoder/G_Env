#pragma once
#ifndef TANK_GAMESTATES_H
#define TANK_GAMESTATES_H

typedef enum GameStates_E
{
	GAMESTATE_DASHBOARD,
	GAMESTATE_LOADING,
	GAMESTATE_PLAYING,
	GAMESTATE_PAUSED,
	GAMESTATE_GAMEOVER,
	GAMESATE_EXITING
} GameStates;

#endif // !TANK_GAMESTATES_H