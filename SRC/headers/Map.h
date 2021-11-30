#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>

#include <fstream>
#include <stdlib.h>

#include "Math.h"

class Map
{
public:

	Map(Vector2i pMapSize, const char* pStrMap);
	~Map();

	void vLoadMap(const char* strMap);
	void vUnloadMap();
	void ifStream();
	void setMapSize(Vector2i pMapSize);

	std::vector<int> iGetVecMap();
	Vector2i iGetMapSize();

	

private:

	const char* strMap;
	std::vector<int> iMap;

	Vector2i mapSize;
	std::ifstream iFile{};
};