#include "header.h"
#include <iostream>
#include <random>
using namespace std;

void makePlateLight(strMyGame& str) {
	// ================================================================
	// янгдюел онке 3у3
	// ================================================================
	str.arrPlate = new symbGame * [str.size_y];

	for (size_t i = 0; i < str.size_y; i++)
	{
		str.arrPlate[i] = new symbGame[str.size_x];
	}

	for (size_t i = 0; i < str.size_y; i++)
	{
		for (size_t j = 0; j < str.size_x; j++)
		{
			str.arrPlate[i][j] = EMPTY;
		}
	}
	// ================================================================
	// бшахпюел йрн ундхр оепбшл х йюйни тхцспни
	// ================================================================
	std::random_device rd;
	std::mt19937 randomNumb(rd());

	str.step = randomNumb() % 2;

	if (randomNumb() % 2 == 1) {
		str.ai = CROSS;
		str.human = ZERO;
	}
	drawPlate(str);
}