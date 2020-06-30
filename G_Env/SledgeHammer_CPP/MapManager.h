#pragma once
#include "Point2D.h"
#include <SDL.h>
#include <vector>
#include <string>

class MapManager
{
public:
	MapManager();
	~MapManager();

	bool LoadMap(std::string filePath);
	void Update();
	void DrawMap();

	void MoveMapLeft();
	void MoveMapRight();
	void MoveMapUp();
	void MoveMapDown();

	void ZoomIn();
	void ZoomOut();

private:
	unsigned int rowSize;
	unsigned int colSize;
	unsigned int textureWidth;
	unsigned int textureHeight;
	unsigned int scrollSpeed { 2 };
	unsigned int zoomLevel { 4 };

	Point2D position;

	std::vector<std::vector<int>> map;

	SDL_Rect src;
	SDL_Rect dest;

	void LoadMapTextures();
	void GetMapDataFromFile(std::string& mapFile, std::vector<int>& nrs);
};