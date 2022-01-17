#include <iostream>
#include "windows.h"

int main() {
	HINSTANCE my_load;
	typedef int (*sum)(int, int);
	typedef bool (*task2)(int, int);
	typedef int (*task3)(int, int*);
	
	// 1. Задание
	my_load = LoadLibrary(L"My_Dll_HW3.dll");
	sum my_func1_dll = (sum)GetProcAddress(my_load, "Sum");
	
	int entered_num1;
	int entered_num2;

	std::cout << "Sum two numbers!" << std::endl << "Enter first number: ";
	std::cin >> entered_num1;
	std::cout << "Enter second number: ";
	std::cin >> entered_num2;
	std::cout << my_func1_dll(entered_num1, entered_num2) << std::endl;

	// 2. Задание
	task2 my_func2_dll = (task2)GetProcAddress(my_load, "Task2");
	const int x = 8;
	const int y = 2;

	std::cout << "Task2: number1 = " << x << " number2 = " << y << ", reshenie is ";
	std::cout << std::boolalpha << my_func2_dll(x, y);
	std::cout << std::endl;

	//3. Задание
	task3 my_func3_dll = (task3)GetProcAddress(my_load, "Task3");
	int arrNechet[25] = { 0 };
	std::cout << "Enter number: " << std::endl;
	std::cin >> entered_num1;

	my_func3_dll(entered_num1, &arrNechet[0]);
	
	for (auto elem : arrNechet) {
		std::cout << elem << " ";
	}

	FreeLibrary(my_load);
}