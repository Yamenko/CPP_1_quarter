#include <iostream>
#include "header.h"
using namespace std;
extern strCoord coord;

void turnHuman(strMyGame& str) {
	drawPlate(str);

	do { // �������� �� ��������� ����� ������ ��������

		cout << "Your turn!" << endl << "Enter X: ";
		do { // �������� ��������� ����� � ����� �� ��� � �������� ��������
			cin >> coord.x;
			coord.x--;
		} while (!(checkRange(coord.x, 0, str.size_x - 1)));

		cout << "Enter Y: ";
		do { // �������� ��������� ����� Y � �������� ��������
			cin >> coord.y;
			coord.y--;
		} while (!(checkRange(coord.y, 0, str.size_y - 1)));
	} while (!checkEmpty(str, coord));

	str.arrPlate[coord.y][coord.x] = str.human;
	str.step++;
}