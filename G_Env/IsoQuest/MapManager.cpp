#include "MapManager.h"
#include "TextureManager.h"
#include <iostream>
#include <fstream>
#include <sstream>

using std::vector;
using std::string;

bool isoEnabled = true;

MapManager::MapManager()
{
	LoadMapTextures();

	if (!LoadMap("Levels/level1.txt"))
	{
		std::cout << "Failed loading map.\n";
		return;
	}

	xPos = 150;
	yPos = 450;

	// Initalize tile rect
	src.x = src.y = 0;
	src.w = textureWidth;
	src.h = textureHeight;

	dest.x = dest.y = 0;
	dest.w = textureWidth;
	dest.h = textureHeight;
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

void MapManager::DrawMap()
{
	for (unsigned int row = 0; row < rowSize; ++row)
	{
		for (unsigned int col = 0; col < colSize; ++col)
		{
			int type = map[row][col];
			int x = row;
			int y = col;

			if (isoEnabled)
			{
				auto isoX = (x + y);
				float isoY = (y - x) / 2.0f;
				dest.x = isoX * 8 * zoomLevel + xPos;
				dest.y = (int)(isoY * 8 * zoomLevel + yPos);

				dest.w = 16 * zoomLevel;
				dest.h = 8 * zoomLevel;
				// zooming needs to adjust both the tiles dimension as well as tile placement
			}
			else
			{
				dest.x = 64 * x + xPos;
				dest.y = 32 * y + yPos;
			}

			switch (type)
			{
				case 0:
					TextureManager::Render(dirt, &src, &dest);
					break;
				case 1:
					TextureManager::Render(grass, &src, &dest);
					break;
				case 2:
					TextureManager::Render(water, &src, &dest);
					break;
				case 3:
					TextureManager::Render(cobble, &src, &dest);
					break;
			}
		}
	}
}

void MapManager::MoveMapLeft() { xPos -= scrollSpeed; }

void MapManager::MoveMapRight() { xPos += scrollSpeed; }

void MapManager::MoveMapUp() { yPos -= scrollSpeed; }

void MapManager::MoveMapDown() { yPos += scrollSpeed; }

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
	if (isoEnabled)
	{
		dirt = TextureManager::LoadTexture("Assets/dirtISO.png");
		grass = TextureManager::LoadTexture("Assets/grassISO.png");
		water = TextureManager::LoadTexture("Assets/waterISO.png");
		cobble = TextureManager::LoadTexture("Assets/cobbleISO.png");
	}
	else
	{
		dirt = TextureManager::LoadTexture("Assets/dirt.png");
		grass = TextureManager::LoadTexture("Assets/grass.png");
		water = TextureManager::LoadTexture("Assets/water.png");
		cobble = TextureManager::LoadTexture("Assets/cobble.png");
	}
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
			while (std::getline(ss, nrStr, ' '))
			{
				auto nr = std::stoi(nrStr);
				nrs.push_back(nr);
			}
		}
	}
	file.close();
}