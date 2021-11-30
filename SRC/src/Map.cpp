#include "Map.h"

#include <iostream>
#include <stdlib.h>

Map::Map(Vector2i pMapSize, const char* pStrMap) : strMap(pStrMap), mapSize(pMapSize)
{
	iFile.open(strMap);
	ifStream();
}


Map::~Map()
{

}

void Map::setMapSize(Vector2i pMapSize)
{
	mapSize = pMapSize;
}

void Map::vLoadMap(const char* pStrMap)
{
	strMap = pStrMap;
	iFile.open(strMap);
	ifStream();
}

void Map::vUnloadMap()
{
	iFile.close();
	strMap = NULL;
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

Vector2i Map::iGetMapSize()
{
	return mapSize;
}

std::vector<int> Map::iGetVecMap()
{
	return iMap;
}