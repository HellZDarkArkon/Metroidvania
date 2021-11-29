#include "Map.h"

#include <iostream>
#include <stdlib.h>

Map::Map(int pMapX, int pMapY, const char* pStrMap) : strMap(NULL), mapX(pMapX), mapY(pMapY)
{
	iFile.open(pStrMap);
	ifStream();
}

Map::Map() : strMap(NULL), mapX(0), mapY(0)
{
	
}


Map::~Map()
{

}

void Map::setMapSize(int pMapX, int pMapY)
{
	mapX = pMapX;
	mapY = pMapY;
}

void Map::vLoadMap(const char* pStrMap)
{
	iFile.open(pStrMap);
}

void Map::vUnloadMap()
{
	iFile.close();
}

void Map::ifStream()
{
	if(iFile.is_open())
	{
		while(!iFile.eof())
		{
			int temp1;
			iFile >> std::hex >> temp1;

			iMap.push_back(temp1);
		}
	}

	iFile.close();

	for(int& i: iMap)
	{
		if(i == 0xFF)
		{
			std::cout<<std::endl;
		}
		else if(i != 0xFF)
		{
			std::cout<<i<<" ";
		}
	}

}

int Map::iGetMapX()
{
	return mapX;
}

int Map::iGetMapY()
{
	return mapY;
}

std::vector<int> Map::iGetVecMap()
{
	return iMap;
}