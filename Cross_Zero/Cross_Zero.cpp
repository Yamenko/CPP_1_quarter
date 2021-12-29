/*
1. Создать и инициализировать переменные пройденных типов данных (short int, int, long long, char, bool, float, double).
2. Создать перечисление (enum) с возможными вариантами символов для игры в крестики-нолики.
3. Создать массив, способный содержать значения такого перечисления и инициализировать его.
4. *	Создать структуру (struct) данных «Поле для игры в крестики-нолики» и 
		снабдить его всеми необходимыми свойствами (подумайте что может понадобиться).
5. **	Создать структуру (struct MyVariant) объединяющую: union MyData (int, float, char) 
		и 3-и битовых поля (флага) указывающими какого типа значение в данный момент содержится в объединении (isInt, isFloat, isChar). 
		Продемонстрировать пример использования в коде этой структуры.
*/

//#include <typeinfo>
#include <iostream>


//Задание 1
// Объявление переменных

bool		bFlag = true;
char		Smb = 'A';
short int	sNumber1 = 0;
int			iNumber2 = 200;
long long	lNumber3 = 300;
float		fNumber4 = 22.44f;
double		dNumber5 = 33.44;

//Задание 2
//Перечисление

enum Symbol: unsigned char
{	
	smbEmpty,
	smbZero,
	smbCross
};

//Задание 3
//Массив

Symbol arrPlate[3][3] = {	{smbEmpty, smbEmpty, smbEmpty},
							{smbEmpty, smbEmpty, smbEmpty}, 
							{smbEmpty, smbEmpty, smbEmpty} 
						 };

//Задание 4
//Структура

struct GameInfo {
	uint16_t iGameID = 0;	// Игра по порядку
	uint8_t cFirst = 0;		// Кто первый ходит
	uint8_t cFirstSmb = 0;	// Какой символ первого игрока
	uint8_t arrStep[9];		// Массив ходов 
} GI;

//Задание 5
//Структура и Объединение

enum UseTypeUnion: uint8_t { isInt, isFloat, isChar };
struct MyVariant {
	union MyData {
		int iStep;
		float fTimeStep;
		char cSymb;
	} MD;
	UseTypeUnion TypeMyData;
	struct Flags
	{
		uint8_t Flag1 : 1;
		uint8_t Flag2 : 1;
		uint8_t Flag3 : 1;
	} FL;
} variant1;


// для тестов и проверок
int main(){

	std::cout << typeid(variant1.MD.iStep).name() << std::endl;

/*

	for (int n = 0; n < 3; n++)
	{
		for (int m = 0; m < 3; m++)
		{
			std::cout << (int)arrPlate[n][m] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << sizeof(Symbol) << std::endl;
	std::cout << sizeof(arrPlate) << std::endl;
*/
}