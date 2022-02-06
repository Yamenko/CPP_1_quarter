#include <iostream>
#include "header.h"

using namespace std;

bool checkRange(size_t checked, size_t minRange, size_t maxRange) {
	if (checked >= minRange && checked <= maxRange) {
		return true;
	}
	else return false;
}

bool checkEmpty(strMyGame& str, strCoord& coord) { // проверка пустых ячеек для хода пользователя
	if (str.arrPlate[coord.y][coord.x] == EMPTY) {
		return true;
	}
	else return false;
}

bool checkWinSituationLight(strMyGame& str, symbGame symb) {
	int countHor = 0;
	int countVert = 0;
	int countDiag1 = 0;
	int countDiag2 = 0;
	int noEmpty = 0;
	for (size_t i = 0; i < str.size_y; i++)
	{
		for (size_t j = 0; j < str.size_x; j++)
		{
			if (str.arrPlate[i][j] == symb) {
				countHor++;
			}
			if (str.arrPlate[j][i] == symb) {
				countVert++;
			}
			if (str.arrPlate[i][j] == symb && i == j) {
				countDiag1++;
			}
			if (	(i == 0 && j == 2 && str.arrPlate[i][j] == symb)
				||	(i == 1 && j == 1 && str.arrPlate[i][j] == symb) 
				||	(i == 2 && j == 0 && str.arrPlate[i][j] == symb)) {
				countDiag2++;	
			}
			if (str.arrPlate[i][j] == EMPTY) {
				noEmpty++;
			}

		}
		if (countHor == 3 || countDiag1 == 3 || countDiag2 == 3 || countVert == 3) {
			return true;
		}
		else {
			countHor = 0;
			countVert = 0;
		}
	}
	if (noEmpty == 0) {
		str.status = DRAW;
	}
	return false;
}