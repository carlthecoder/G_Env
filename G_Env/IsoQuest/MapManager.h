#pragma once
#include <SDL.h>
#include <vector>
#include <string>

class MapManager
{
public:
	MapManager();
	~MapManager();

	bool LoadMap(std::string filePath);
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
	unsigned int zoomLevel { 1 };
	int xPos;
	int yPos;

	std::vector<std::vector<int>> map;

	SDL_Rect src;
	SDL_Rect dest;
	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;
	SDL_Texture* cobble;

	void LoadMapTextures();
	void GetMapDataFromFile(std::string& filePath, std::vector<int>& nrs);
};