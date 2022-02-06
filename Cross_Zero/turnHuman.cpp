#include <iostream>
#include "header.h"
using namespace std;
extern strCoord coord;

void turnHuman(strMyGame& str) {
	drawPlate(str);

	do { // Проверка на занятость точки другим символом

		cout << "Your turn!" << endl << "Enter X: ";
		do { // Проверка выбранной точки Х лежит ли она в заданных пределах
			cin >> coord.x;
			coord.x--;
		} while (!(checkRange(coord.x, 0, str.size_x - 1)));

		cout << "Enter Y: ";
		do { // Проверка выбранной точки Y в заданных пределах
			cin >> coord.y;
			coord.y--;
		} while (!(checkRange(coord.y, 0, str.size_y - 1)));
	} while (!checkEmpty(str, coord));

	str.arrPlate[coord.y][coord.x] = str.human;
	str.step++;
}