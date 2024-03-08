#include <iostream>
#include "Map.h"

using namespace std;



Map::Map(){}

Map::~Map(){}

void Map::buildMap()
{
	for (int row = 0; row < SIZEMAP; row++)
	{
		for (int col = 0; col < SIZEMAP; col++)
		{
			map[row][col] = '.';
			cout << map[row][col];
		}
	}
		
}



