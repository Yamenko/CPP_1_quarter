#include <iostream>;

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

unsigned char arrPlate[3][3] = { {smbEmpty, smbEmpty, smbEmpty}, 
								 {smbEmpty, smbEmpty, smbEmpty}, 
								 {smbEmpty, smbEmpty, smbEmpty} 
							   };

struct GameInfo { // тут можно разбить байт, надо подумать что еще добавить.
	//unsigned int iGameID = 0; //Игра по порядку
	unsigned char cFirst = 0; // Кто первый ходит
	// 



};
int main(){

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

}