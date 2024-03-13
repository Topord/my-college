#ifndef TERRAIN_H
#define TERRAIN_H
#include "point.h"
#include "tools.h"
#include<vector>

class Terrain
{
public:
	Terrain(){}
public:
	void TerrInform(int x);
	std::vector<Point> tertext;
	void PrintTerrain();
	friend class Food;
	friend class Snake;
};
#endif //TERRAIN_H