#include <iostream>

//===========================
//			Task 1
//===========================
class Power {
private:
	float m_number_1;
	float m_number_2;

public:
	Power() {
		m_number_1 = 1.01f;
		m_number_2 = 2.02f;
	}

	void setPower(float num_1, float num_2) {
		m_number_1 = num_1;
		m_number_2 = num_2;
	}

	float calculate() {
		return pow(m_number_1, m_number_2);
	}
};

//===========================
//			Task 2
//===========================

class RGBA
{
private:
	uint8_t m_red ;
	uint8_t m_green;
	uint8_t m_blue;
	uint8_t m_alpha;

public:
	RGBA() : m_red (0), m_green (0), m_blue (0), m_alpha (255) {};
	void setRGBA(uint8_t m_red, uint8_t m_green, uint8_t m_blue, uint8_t m_alpha) {
		this->m_red = m_red;
		this->m_green = m_green;
		this->m_blue = m_blue;
		this->m_alpha = m_alpha;
	};
	void print() {
		std::cout << "Red: " << static_cast<int>(m_red) << std::endl;
		std::cout << "Green: " << static_cast<int>(m_green) << std::endl;
		std::cout << "Blue: " << static_cast<int>(m_blue) << std::endl;
		std::cout << "Alpha: " << static_cast<int>(m_alpha) << std::endl;
	}
};

//===========================
//			Task 3
//===========================

class Stack
{
private:
	int arr[10];
	int length;

public:
	void reset() {
		for (int i = 0; i < length; i++)
		{
			arr[i] = 0;
		}
		length = 0;
	};

	bool push(int number) { // добавляем число в массив 
		if (length >= std::size(arr) - 1) { // если переменная length больше или равна (длина массива - 1), то массив уже полный. 
			return false;
		}
		else {
			arr[length++] = number;
			//length++;
			return true;
		}
	};
	void pop() {
		if (length > 0) {
			arr[length--] = 0;
			//length--;
		}
		else {
			std::cout << "Nothing to drop." << std::endl;
		}
	}
	void print() {
		std::cout << "( ";
		for (int i = 0; i < length; i++)
		{
			std::cout << arr[i] << " ";
		}
		std::cout << ")" << std::endl;
	}
};


int main()
{
	//Task 1
	Power lesson1;
	std::cout << "Task 1. Default: " <<lesson1.calculate() << std::endl;
	lesson1.setPower(5.33, 3.22);
	std::cout << "Task 1. Changed (5.33 ^ 3.22): " <<lesson1.calculate() << std::endl << std::endl;

	//Task 2 
	RGBA rgba;
	std::cout << "Task 2. Default: " << std::endl;
	rgba.print();
	rgba.setRGBA(100,20,50,125);
	std::cout << "Task 2. Changed: " << std::endl;
	rgba.print();
	std::cout << std::endl;

	//Task 3

	std::cout << "Task 3." << std::endl;

	Stack stack;
	stack.reset();
	stack.print();

	stack.push(3);
	stack.push(7);
	stack.push(5);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();
	stack.print();

}