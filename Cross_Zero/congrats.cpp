#include <iostream>
#include "header.h"
using namespace std;

void congrat(strMyGame& str) {
	if (str.status == WON_AI) {
		cout << "Your oponent`s WIN! Congrats AI" << endl;
	}
	if (str.status == WON_HUMAN) {
		cout << "You WIN! Congrats HUMAN" << endl;
	}
	if (str.status == DRAW) {
		cout << "Have no WINER!" << endl;
	}

	//очистим массив
	delete[] str.arrPlate;
}