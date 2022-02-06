#include <iostream>
#include "header.h"
using namespace std;

void drawPlate(strMyGame& str) {
	system("cls"); // очистка экрана
	cout << " ";
	for (size_t i = 0; i < str.size_x;)
	{
		cout << "   " << ++i;
	}
	cout << endl;
	int y = 0;
	for (size_t i = 0; i < str.size_y; i++)
	{
		cout << ++y;
		for (size_t j = 0; j < str.size_x; j++)
		{
			
			cout << " | " << str.arrPlate[i][j];
		}
		cout << endl;
	}

	cout << "Human plays - " << str.human << endl;
	cout << "AI plays - " << str.ai << endl;
}

void askAgan(strMyGame& str) {
	char answer;
	cout << " Play Agan?? (y/n):";
	cin >> answer;
	if (answer == 'y') {
		str.agan = true;
		str.status = IN_PROGRESS;
	}
	else { 
		str.agan = false; 
	}
}