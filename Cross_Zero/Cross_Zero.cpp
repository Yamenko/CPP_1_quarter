#include <iostream>;

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

unsigned char arrPlate[3][3] = { {smbEmpty, smbEmpty, smbEmpty}, 
								 {smbEmpty, smbEmpty, smbEmpty}, 
								 {smbEmpty, smbEmpty, smbEmpty} 
							   };

struct GameInfo { // ��� ����� ������� ����, ���� �������� ��� ��� ��������.
	//unsigned int iGameID = 0; //���� �� �������
	unsigned char cFirst = 0; // ��� ������ �����
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