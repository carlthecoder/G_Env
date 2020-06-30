#pragma once
#include "Player.h"
#include <memory>

class Game
{
public:
	Game();
	~Game();
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;

	/// <summary>
	/// Initializes all the major game entities.
	/// </summary>
	void Initialize();

	/// <summary>
	/// Updates all the major game entities.
	/// </summary>
	void Update();

	/// <summary>
	/// Draws all the major game entities.
	/// </summary>
	void Draw();

private:
	std::unique_ptr<Player> player;
};