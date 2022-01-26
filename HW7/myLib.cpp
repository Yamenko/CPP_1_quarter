#include <iostream>
#include <random>
#define MIN_RAND 1.00
#define MAX_RAND 10.00
#define SWAP_INT(a, b, temp) (temp = a, a = b, b = temp)

namespace MyFunc {

	//инициализаци€ массива(типа float), через рандомы
	void initArr(float* myArr, const size_t SIZE) {
		std::default_random_engine generator;
		std::uniform_int_distribution<int> distribution(MIN_RAND, MAX_RAND);

		for (size_t i = 0; i < SIZE; i++)
		{
			myArr[i] = ((float)(distribution(generator) % 7) - MAX_RAND / 2) * 10 / 7 ; // тут делаем "не целые" числа.
		}
	}

	// печати массива на экран
	void printArr(float* myArr, const size_t SIZE) {
		std::cout << "My array: ";
		for (size_t i = 0; i < SIZE; i++)
		{
			std::cout << myArr[i] << " ";
		}
		std::cout << std::endl;
	}

	//подсчет количества отрицательных и положительных элементов
	void plusMinusCount(float* myArr, const size_t SIZE, int& plusCount, int& minusCount) {
		for (size_t i = 0; i < SIZE; i++)
		{
			myArr[i] > 0 ? plusCount++ : minusCount++;
		}
	}

	//«аполнение массива с клавиатуры
	void userEnterArr(int* myArr, const size_t SIZE) {
		std::cout << "Enter " << SIZE << " number: ";
		for (size_t i = 0; i < SIZE; i++)
		{
			std::cin >> myArr[i];
		}
	}

	//—ортировка массива ѕузырьком
	void sortArr(int* myArr, const size_t SIZE) {
		int temp;
		for (size_t j = 0; j < SIZE - 1; j++)
		{
			for (size_t i = 0; i < SIZE - 1; i++)
			{
				if (myArr[i] > myArr[i + 1]) {
					SWAP_INT(myArr[i], myArr[i + 1], temp);
				}
			}
		}
	}
}