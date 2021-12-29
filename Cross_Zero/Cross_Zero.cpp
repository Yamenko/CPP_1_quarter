/*
1. ������� � ���������������� ���������� ���������� ����� ������ (short int, int, long long, char, bool, float, double).
2. ������� ������������ (enum) � ���������� ���������� �������� ��� ���� � ��������-������.
3. ������� ������, ��������� ��������� �������� ������ ������������ � ���������������� ���.
4. *	������� ��������� (struct) ������ ����� ��� ���� � ��������-������ � 
		�������� ��� ����� ������������ ���������� (��������� ��� ����� ������������).
5. **	������� ��������� (struct MyVariant) ������������: union MyData (int, float, char) 
		� 3-� ������� ���� (�����) ������������ ������ ���� �������� � ������ ������ ���������� � ����������� (isInt, isFloat, isChar). 
		������������������ ������ ������������� � ���� ���� ���������.
*/

//#include <typeinfo>
#include <iostream>


//������� 1
// ���������� ����������

bool		bFlag = true;
char		Smb = 'A';
short int	sNumber1 = 0;
int			iNumber2 = 200;
long long	lNumber3 = 300;
float		fNumber4 = 22.44f;
double		dNumber5 = 33.44;

//������� 2
//������������

enum Symbol: unsigned char
{	
	smbEmpty,
	smbZero,
	smbCross
};

//������� 3
//������

Symbol arrPlate[3][3] = {	{smbEmpty, smbEmpty, smbEmpty},
							{smbEmpty, smbEmpty, smbEmpty}, 
							{smbEmpty, smbEmpty, smbEmpty} 
						 };

//������� 4
//���������

struct GameInfo {
	uint16_t iGameID = 0;	// ���� �� �������
	uint8_t cFirst = 0;		// ��� ������ �����
	uint8_t cFirstSmb = 0;	// ����� ������ ������� ������
	uint8_t arrStep[9];		// ������ ����� 
} GI;

//������� 5
//��������� � �����������

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


// ��� ������ � ��������
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