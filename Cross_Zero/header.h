#pragma once
enum symbGame : char { CROSS = 'X', ZERO = '0', EMPTY = '_'};
enum gameStatus { IN_PROGRESS, WON_AI, WON_HUMAN, DRAW};

extern struct strMyGame
{
	symbGame** arrPlate = nullptr;

	symbGame human = CROSS;
	symbGame ai = ZERO;

	size_t size_x = 3; // Размер поля по Х
	size_t size_y = 3; // Размер поля по Y
	size_t step = 0;

	gameStatus status = IN_PROGRESS;
	bool agan = true;
};

extern struct strCoord
{
	size_t x;
	size_t y;
};

//=============================
// Для мини версии игры 3Х3
//=============================
void drawPlate(strMyGame&);
void makePlateLight(strMyGame&);
void congrat(strMyGame&);
void askAgan(strMyGame&);
void turnHuman(strMyGame&);
void turnAi(strMyGame&);

bool shearchPosToMove(strMyGame&);
bool checkWinSituationLight(strMyGame&, symbGame);
bool checkRange(size_t, size_t, size_t);
bool checkEmpty(strMyGame&, strCoord&);