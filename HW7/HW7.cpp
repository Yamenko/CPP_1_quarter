//1. Создайте проект из 2х cpp файлов и заголовочного(main.cpp, mylib.cpp, mylib.h) 
// во втором модуле mylib объявить 3 функции: для инициализации массива(типа float), 
// печати его на экран и подсчета количества отрицательных и положительных элементов.
// Вызывайте эти 3 - и функции из main для работы с массивом.
//2. Описать макрокоманду(через директиву define), проверяющую, 
// входит ли переданное ей число(введенное с клавиатуры) в диапазон 
// от нуля(включительно) до переданного ей второго аргумента(исключительно) 
// и возвращает true или false, вывести на экран «true» или «false».
//3. Задайте массив типа int. Пусть его размер задается через директиву препроцессора #define.
// Инициализируйте его через ввод с клавиатуры.
// Напишите для него свою функцию сортировки(например Пузырьком).
// Реализуйте перестановку элементов как макрокоманду SwapINT(a, b).
// Вызывайте ее из цикла сортировки.
//4. * Объявить структуру Сотрудник с различными полями.
// Сделайте для нее побайтовое выравнивание с помощью директивы pragma pack.
// Выделите динамически переменную этого типа.
// Инициализируйте ее.Выведите ее на экран и ее размер с помощью sizeof.
// Сохраните эту структуру в текстовый файл.
//5. * Сделайте задание 1 добавив свой неймспейс во втором модуле.


#include <iostream>
#include <fstream>
#include "myLib.h"

#define SIZE 5
#define MACROS_BETWEEN(a, b) (a>=0 && a<b) ? 1 : 0

int main()
{
//1. Создайте проект из 2х cpp файлов и заголовочного(main.cpp, mylib.cpp, mylib.h) 
// во втором модуле mylib объявить 3 функции: для инициализации массива(типа float), 
// печати его на экран и подсчета количества отрицательных и положительных элементов.
// Вызывайте эти 3 - и функции из main для работы с массивом.
	int plus = 0, minus = 0;
	float myNewArr[SIZE];
	MyFunc::initArr(myNewArr, SIZE);
	MyFunc::printArr(myNewArr, SIZE);
	MyFunc::plusMinusCount(myNewArr, SIZE, plus, minus);
	std::cout << "Array got a positiv: " << plus << " and negativ: " << minus << std::endl;

//2. Описать макрокоманду(через директиву define), проверяющую, 
// входит ли переданное ей число(введенное с клавиатуры) в диапазон 
// от нуля(включительно) до переданного ей второго аргумента(исключительно) 
// и возвращает true или false, вывести на экран «true» или «false».

	int firstEnter, secondEnter;
	std::cout << "Enter number 1:";
	std::cin >> firstEnter;
	std::cout << "Enter number 2:";
	std::cin >> secondEnter;
	if (MACROS_BETWEEN(firstEnter, secondEnter)) {
		std::cout << "True";
	}
	else {
		std::cout << "False";
	}

//3. Задайте массив типа int. Пусть его размер задается через директиву препроцессора #define.
// Инициализируйте его через ввод с клавиатуры.
// Напишите для него свою функцию сортировки(например Пузырьком).
// Реализуйте перестановку элементов как макрокоманду SwapINT(a, b).
// Вызывайте ее из цикла сортировки.
	int myNewArr2[SIZE] = {0};
	MyFunc::userEnterArr(myNewArr2, SIZE);
	MyFunc::sortArr(myNewArr2, SIZE);
	
	std::cout << "U entered: ";
	for (size_t i = 0; i < SIZE; i++)
	{
		std::cout << myNewArr2[i] << " ";
	}

	//4. * Объявить структуру Сотрудник с различными полями.
// Сделайте для нее побайтовое выравнивание с помощью директивы pragma pack.
// Выделите динамически переменную этого типа.
// Инициализируйте ее.Выведите ее на экран и ее размер с помощью sizeof.
// Сохраните эту структуру в текстовый файл.

	enum Departments
	{
		OFICE, SHOP, FACTORY, REMOTE
	};
	std::string nameDep[4] = { "OFICE", "SHOP", "FACTORY", "EMOTE" };

	#pragma pack (push, 1)
	struct Emploer
	{
		int id;
		std::string name;
		Departments dep;
		float salary;
	};
	#pragma pack (pop)

	Emploer* firstEmp = new Emploer;

	firstEmp->id = 1;
	firstEmp->name = "Mike";
	firstEmp->dep = OFICE;
	firstEmp->salary = 50000;

	std::cout << "ID: " << firstEmp->id << std::endl;
	std::cout << "Name: " << firstEmp->name << std::endl;
	std::cout << "Department: " << nameDep[firstEmp->dep] << std::endl;
	std::cout << "Salary: " << firstEmp->salary << std::endl;
	std::cout << "Size of: " << sizeof(firstEmp) << std::endl;


	std::ofstream myFile("Emploers.txt");
	myFile << "ID: " << firstEmp->id << std::endl;
	myFile << "Name: " << firstEmp->name << std::endl;
	myFile << "Department: " << nameDep[firstEmp->dep] << std::endl;
	myFile << "Salary: " << firstEmp->salary << std::endl;
	myFile << "Size of: " << sizeof(firstEmp) << std::endl;
	myFile.close();

	delete firstEmp;

}