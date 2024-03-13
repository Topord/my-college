#include "terrain.h"
#include "point.h"
#include "tools.h"
#include "snake.h"
#include<vector>


void Terrain::TerrInform(int x)
{
	 if (x == 1) {
		for (int i = 2; i <= 15; i++) {
			tertext.emplace_back(Point(i, 22));
		}
		for (int i = 2; i <= 15; i++) {
			tertext.emplace_back(Point(9, i));
		}

		for (int i = 1; i <= 13; i++) {
			tertext.emplace_back(Point(30 - i, 9));
		}
		for (int i = 1; i <= 13; i++) {
			tertext.emplace_back(Point(21, 30 - i));
		}
			
	}
	//map2
	else if (x == 2) {
		 for (int i = 2; i <= 29; i++) {
			 tertext.emplace_back(Point(i, 15));
		 }
		 for (int i = 2; i <= 29; i++) {
			 tertext.emplace_back(Point(15, i));
		 }
	}
	//map3
	else if (x == 3) {
		 for (int i = 2; i <= 29; i++) {
			 tertext.emplace_back(Point(i, 20));
		 }
		 for (int i = 20; i <= 29; i++) {
			 tertext.emplace_back(Point(18, i));
		 }
		 for (int i = 2; i <= 14; i++) {
			 tertext.emplace_back(Point(i, 10));
		 }
		 for (int i = 2; i <= 10; i++) {
			 tertext.emplace_back(Point(14, i));
		 }
		 for (int i = 9; i <= 25; i++) {
			 tertext.emplace_back(Point(i, 2));
		 }
		 for (int i = 18; i <= 29; i++) {
			 tertext.emplace_back(Point(i, 10));
		 }
		 tertext.emplace_back(Point(2, 2));
		 tertext.emplace_back(Point(3, 2));
		 tertext.emplace_back(Point(4, 2));
		 tertext.emplace_back(Point(5, 2));
		 tertext.emplace_back(Point(2, 3));
		 tertext.emplace_back(Point(2, 4));
	}
}

void Terrain::PrintTerrain()
{
	SetColor(2);
	for (auto& point : tertext) {
		point.Print();
	}
}
