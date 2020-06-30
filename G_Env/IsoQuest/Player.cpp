//#include "Player.h"
//#include <iostream>
//#include <SDL.h>
//
//int row = 0;
//int col = 0;
//int sprtWidth = 96;
//int sprtHeight = 104;
//
//Player::Player(const char* texturePath, int x, int y)
//{}
//
//Player::~Player()
//{
//	std::cout << "Player deleted" << std::endl;
//}
//
////void Player::Update()
////{
////	bool hasMoved = false;
////	auto keystates = SDL_GetKeyboardState(NULL);
////
////	if (keystates[SDL_SCANCODE_A])
////	{
////		MoveLeft();
////		hasMoved = true;
////	}
////	if (keystates[SDL_SCANCODE_D])
////	{
////		MoveRight();
////		hasMoved = true;
////	}
////	if (keystates[SDL_SCANCODE_W])
////	{
////		MoveUp();
////		hasMoved = true;
////	}
////	if (keystates[SDL_SCANCODE_S])
////	{
////		MoveDown();
////		hasMoved = true;
////	}	
////
////	col++;
////
////	if (!hasMoved)
////	{
////		row = 0;
////
////		if (col > 2)
////		{
////			col = 0;
////		}
////	}
////
////	if (col > 9) col = 0;
////
////	//srcRect.x = sprtWidth * col;
////	//srcRect.y = sprtHeight * row;
////	//srcRect.w = sprtWidth;
////	//srcRect.h = sprtHeight;
////
////	//dstRect.x = xPos;
////	//dstRect.y = yPos;
////	//dstRect.w = sprtWidth / 2;
////	//dstRect.h = sprtHeight / 2;
////}
//
//void Player::MoveLeft()
//{
//	row = 5;
//	//xPos -= moveSpeed;
//}
//
//void Player::MoveRight()
//{
//	row = 7;
//	//xPos += moveSpeed;
//}
//
//void Player::MoveUp()
//{
//	row = 6;
//	//yPos -= moveSpeed;
//}
//
//void Player::MoveDown()
//{
//	row = 4;
//	//yPos += moveSpeed;
//}