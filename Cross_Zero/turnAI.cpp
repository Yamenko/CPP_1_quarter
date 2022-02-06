#include "header.h"
strCoord coord;

bool shearchPosToMove(strMyGame& str) {
	// проверка выигрышных позиций
	for (size_t y = 0; y < str.size_y; y++)
	{
		for (size_t x = 0; x < str.size_x; x++)
		{ 
			if (str.arrPlate[y][x] == EMPTY) {
				str.arrPlate[y][x] = str.ai;	// поставим точку AI для проверки
				if (checkWinSituationLight(str, str.ai)) { // запустим проверку ситуаций
					return true; // оставляем все как есть и выходим если нашли победный ход
				}
				str.arrPlate[y][x] = str.human; // проверяем проигрышный ход меняем эту точку на точку HUMAN
				if (checkWinSituationLight(str, str.human)) { // запустим проверку ситуаций
					str.arrPlate[y][x] = str.ai; // если найден проигрышный ход, ставим туда точку AI
					return true; // и выходим
				}
				str.arrPlate[y][x] = EMPTY; // если ничего не нашли то обнуляем точку и идем обратно в цикл			
			}
		}
	}

	// Если дошли до этого места значит пока нет победных ходов, ставим точку в угол
	for (size_t y = 0; y < str.size_y; y += (str.size_y - 1))
	{
		for (size_t x = 0; x < str.size_x; x += (str.size_x - 1))
		{
			if (str.arrPlate[y][x] == EMPTY) { // проверили угол
				str.arrPlate[y][x] = str.ai;		// если есть место ставим туда точку 
				return true;
			}
		}
	}

	// Если ходов уже нет, то ставим точку в любое место
	for (size_t y = 0; y < str.size_y; y++)
	{
		for (size_t x = 0; x < str.size_x; x++)
		{
			if (str.arrPlate[y][x] == EMPTY) {
				str.arrPlate[y][x] = str.ai;		// если есть место ставим туда точку 
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