#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#pragma once

#include <fstream>

class Map
{
public:

	Map(const char* strMap);
	~Map();

	void vLoadMap(const char* strMap);
	void vUnloadMap();
	void ifStream();

	std::ifstream iFile{};

private:

	const char* strMap;
	std::vector<int> iMap;

};