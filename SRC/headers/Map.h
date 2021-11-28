#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>

#include <fstream>
#include <stdlib.h>

class Map
{
public:

	Map(int pMapX, int pMapY, const char* pStrMap);
	Map();
	~Map();

	void vLoadMap(const char* strMap);
	void vUnloadMap();
	void ifStream();
	void setMapSize(int pMapX, int pMapY);

	std::vector<int> iGetVecMap();
	int iGetMapX();
	int iGetMapY();

	

private:

	const char* strMap;
	std::vector<int> iMap;

	int mapX, mapY;
	std::ifstream iFile{};
};