#include "Map.h"

#include <iostream>

Map::Map(const char* strMap) : strMap(NULL)
{
	
}

Map::~Map()
{

}

void Map::vLoadMap(const char* strMap)
{
	iFile.open(strMap);
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
			iFile >> temp1;
			iMap.push_back(temp1);
		}

		for(auto i: iMap)
			std::cout<<i<<' ';
		
	}
}