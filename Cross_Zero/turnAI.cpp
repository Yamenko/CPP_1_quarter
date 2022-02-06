#include "header.h"
strCoord coord;

bool shearchPosToMove(strMyGame& str) {
	// �������� ���������� �������
	for (size_t y = 0; y < str.size_y; y++)
	{
		for (size_t x = 0; x < str.size_x; x++)
		{ 
			if (str.arrPlate[y][x] == EMPTY) {
				str.arrPlate[y][x] = str.ai;	// �������� ����� AI ��� ��������
				if (checkWinSituationLight(str, str.ai)) { // �������� �������� ��������
					return true; // ��������� ��� ��� ���� � ������� ���� ����� �������� ���
				}
				str.arrPlate[y][x] = str.human; // ��������� ����������� ��� ������ ��� ����� �� ����� HUMAN
				if (checkWinSituationLight(str, str.human)) { // �������� �������� ��������
					str.arrPlate[y][x] = str.ai; // ���� ������ ����������� ���, ������ ���� ����� AI
					return true; // � �������
				}
				str.arrPlate[y][x] = EMPTY; // ���� ������ �� ����� �� �������� ����� � ���� ������� � ����			
			}
		}
	}

	// ���� ����� �� ����� ����� ������ ���� ��� �������� �����, ������ ����� � ����
	for (size_t y = 0; y < str.size_y; y += (str.size_y - 1))
	{
		for (size_t x = 0; x < str.size_x; x += (str.size_x - 1))
		{
			if (str.arrPlate[y][x] == EMPTY) { // ��������� ����
				str.arrPlate[y][x] = str.ai;		// ���� ���� ����� ������ ���� ����� 
				return true;
			}
		}
	}

	// ���� ����� ��� ���, �� ������ ����� � ����� �����
	for (size_t y = 0; y < str.size_y; y++)
	{
		for (size_t x = 0; x < str.size_x; x++)
		{
			if (str.arrPlate[y][x] == EMPTY) {
				str.arrPlate[y][x] = str.ai;		// ���� ���� ����� ������ ���� ����� 
				return true;
			}
		}
	}
}

void turnAi(strMyGame& str) {
	
	if (str.step == 0) {
		str.arrPlate[1][1] = str.ai;
		str.step++;
	}
	else {
		if (shearchPosToMove(str)) {
			str.step++;
		}
	}
}