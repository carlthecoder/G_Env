#include "MapManager.h"
#include "RectHelpers.h"
#include "SpriteManager.h"
#include <iostream>
#include <fstream>
#include <sstream>

using std::vector;
using std::string;

MapManager::MapManager()
{
	LoadMapTextures();

	if (!LoadMap("Levels/SledgeMap01.txt"))
	{
		std::cout << "Failed loading map.\n";
		return;
	}

	position.x = 150;
	position.y = 450;

	// Initalize tile rect
	RectHelpers::SetRect(src, 0, 0, textureWidth, textureHeight);
	RectHelpers::SetRect(dest, 0, 0, textureWidth, textureHeight);
}

MapManager::~MapManager() { std::cout << "MapManager destructed.\n"; }

bool MapManager::LoadMap(string filePath)
{
	if (filePath.empty())
	{
		std::cout << "Map file path is empty.\n";
		return false;
	}

	std::vector<int> mapData;
	GetMapDataFromFile(filePath, mapData);

	// The first 4 numbers from the mapData mark the rowSize, colSize and textureWidth, textureHeight.
	auto viT = mapData.cbegin();
	rowSize = *viT++;
	colSize = *viT++;
	textureWidth = *viT++;
	textureHeight = *viT++;

	for (size_t row = 0; row < rowSize; ++row)
	{
		vector<int> tmpVec;
		for (size_t col = 0; col < colSize; ++col)
		{
			if (viT != mapData.cend())
			{
				tmpVec.push_back(*viT++);
			}
		}
		map.push_back(tmpVec);
	}

	return true;
}

void MapManager::Update()
{
	auto kbd = SDL_GetKeyboardState(0);

	if (kbd[SDL_SCANCODE_A])
	{
		MoveMapLeft();
	}
	if (kbd[SDL_SCANCODE_D])
	{
		MoveMapRight();
	}
	if (kbd[SDL_SCANCODE_W])
	{
		MoveMapUp();
	}
	if (kbd[SDL_SCANCODE_S])
	{
		MoveMapDown();
	}
}

void MapManager::DrawMap()
{
	for (unsigned int row = 0; row < rowSize; ++row)
	{
		for (unsigned int col = 0; col < colSize; ++col)
		{
			int type = map[row][col];
			int x = row;
			int y = col;

			Point2D pos;
			pos.x = (float)x;
			pos.y = (float)y;

			dest.x = textureWidth * x + (int)position.x;
			dest.y = textureHeight * y + (int)position.y;

			switch (type)
			{
				case 0:
					/*	TextureManager::Render(dirt, &src, &dest);
					break;
				case 1:
					TextureManager::Render(grass, &src, &dest);
					break;
				case 2:
					TextureManager::Render(water, &src, &dest);
					break;
				case 3:
					TextureManager::Render(cobble, &src, &dest);
					break;*/
				default:
					break;
			}
		}
	}
}

void MapManager::MoveMapLeft() { position.x -= scrollSpeed; }

void MapManager::MoveMapRight() { position.x += scrollSpeed; }

void MapManager::MoveMapUp() { position.y -= scrollSpeed; }

void MapManager::MoveMapDown() { position.y += scrollSpeed; }

void MapManager::ZoomIn()
{
	if (zoomLevel < 10)
	{
		++zoomLevel;
	}
}

void MapManager::ZoomOut()
{
	if (zoomLevel > 1)
	{
		--zoomLevel;
	}
}

void MapManager::LoadMapTextures()
{
	/*dirt = SpriteManager::LoadTexture("Assets/dirt.png");
	grass = SpriteManager::LoadTexture("Assets/grass.png");
	water = SpriteManager::LoadTexture("Assets/water.png");
	cobble = SpriteManager::LoadTexture("Assets/cobble.png");*/
}

void MapManager::GetMapDataFromFile(std::string& filePath, std::vector<int>& nrs)
{
	std::ifstream file(filePath);
	string line;

	if (file.is_open())
	{
		// read the file line by line
		while (std::getline(file, line))
		{
			// store each line into a stringstream
			std::stringstream ss(line);
			string nrStr;

			// parse the string stream using a delimiter
			while (std::getline(ss, nrStr, ','))
			{
				auto nr = std::stoi(nrStr);
				nrs.push_back(nr);
			}
		}

		file.close();
	}
}