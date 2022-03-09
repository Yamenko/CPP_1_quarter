#include <iostream>
#include <string>
#include <conio.h>

//============================
//          Task 1
//============================
//1. Написать шаблонную функцию div, которая должна вычислять результат деления двух параметров и запускать исключение DivisionByZero, 
//если второй параметр равен 0. 
//В функции main выводить результат вызова функции div в консоль, а также ловить исключения.

class DivisionByZero : public std::invalid_argument {
private:

public:
	DivisionByZero(std::string msg) : invalid_argument(msg) {};
};

template <typename T>
T division(T in1, T in2) {
	if (in2 == 0) {	throw DivisionByZero("Division by zero!"); }
	return in1 / in2;
};

//============================
//          Task 2
//============================
// 2. Написать класс Ex, хранящий вещественное число x и имеющий конструктор по вещественному числу, 
// инициализирующий x значением параметра.
// Написать класс Bar, хранящий вещественное число y
// (конструктор по умолчанию инициализирует его нулем) и 
//имеющий метод set с единственным вещественным параметром a.
// Если y + a > 100, возбуждается исключение типа Ex с данными a* y, иначе в y заносится значение a.
//В функции main завести переменную класса Bar и в цикле в блоке try вводить с клавиатуры целое n.
//Использовать его в качестве параметра метода set до тех пор, пока не будет введено 0. 
//В обработчике исключения выводить сообщение об ошибке, содержащее данные объекта исключения.

class Ex {
private:
	int x;
public:
	Ex(const int& x) : x(x) {
		std::cout << "Catched: "<< x;
	};
};

class Bar {
private:
	int y;
public:
	Bar() : y(0) {};
	void setY(int& a) {
		if ((y + a) > 100) { 
			//int ex = a * y;
			throw Ex(a * this->y);
		}
		this->y = a;
	};
};


//============================
//          Task 3
//============================
//3. Написать класс «робот», моделирующий перемещения робота по сетке 10x10, 
//у которого есть метод, означающий задание переместиться на соседнюю позицию.
//Эти методы должны запускать классы - исключения OffTheField, если робот должен уйти с сетки, и IllegalCommand, 
//если подана неверная команда(направление не находится в нужном диапазоне).
//Объект исключения должен содержать всю необходимую информацию — текущую позицию и направление движения.
//Написать функцию main, пользующуюся этим классом и перехватывающую все исключения от его методов, 
//а также выводящую подробную информацию о всех возникающих ошибках.

class Robot {
private:
	int x, y, y_End{10}, x_End{10};
	char robot = 01; // символ смайлика, будет вместо робота
	void setLine(const int& y) {
		for (size_t i = 0; i < y; i++)
		{
			std::cout << std::endl; // смещаем каретку вниз
		}
	};
	void setRow(const int& x) {
		for (size_t i = 0; i < x; i++)
		{
			std::cout << " "; // смещаем каретку вправо
		}
	};
	void endPos() { // позиция каретки после движения робота
		for (size_t i = 0; i <= (y_End - y); i++)
		{
			std::cout << std::endl;  // смещаем каретку вниз после вывода робота на экран, и вывода дальнейшего текста
		}
	};
	void setPos(const int& x, const int& y) {
		setLine(y);
		setRow(x);
		std::cout << this->robot;
		endPos();
	};

public:
	Robot() : x(5), y(5) {}; //стартовая позийия будет в центре.

	void draw() { this->setPos(this->x, this->y); };
	void set_X(const int& x) { 	this->x = x; };
	void set_Y(const int& y) { 	this->y = y; };

	int get_X() { return this->x; };
	int get_Y() { return this->y; };
};

class IllegalCommand {
public:
	IllegalCommand(Robot& fail) {
		std::cout << "Try to move negativ position! Your pos: " << fail.get_X() << " X " << fail.get_Y();
	}
};

class OffTheField {
public:
	OffTheField(Robot& fail) {
		std::cout << "You leav field! Your pos: " << fail.get_X() << " X " << fail.get_Y();
	}
};

int main()
{
	//Task 1
	std::cout << "Task 1." << std::endl;
	try {
		double z = division(10, 2);
		std::cout << "Z = " << z << std::endl;
		z = division(20, 0);
	}
	catch (const DivisionByZero& failure)
	{
		std::cout << failure.what() << std::endl;
		std::cout << "Can`t division by zero" << std::endl;
	}

	//Task 2
	std::cout << "Task 2." << std::endl;
	Bar b;
	int enteredNum;
	do {
		try {
			std::cout << "Enter number (1-99, 0 - exit, 100 - exception)";
			std::cin >> enteredNum;
			b.setY(enteredNum);
		}
		catch (Ex&) {}
	} while (enteredNum);

	//Task 3
	std::cout << "Task 3." << std::endl;
	enum wayToRobot { KB_UP = 72, KB_LEFT = 75, KB_RIGHT = 77, KB_DOWN = 80 };
	char answer;
	std::cout << "Start the game? (y/n):";
	std::cin >> answer;
	Robot rob;
	
	
	while (answer != 'q' && answer != 'n'){
		try {	
			std::system("cls");
			rob.draw();

			std::cout << "Use arrow button to move. q/n - for exit.";
			answer = _getch();

			switch (answer)
			{
			case KB_UP:
				((rob.get_Y() - 1) < 0) ? throw IllegalCommand(rob) : rob.set_Y(rob.get_Y() - 1); // если получим меньше 0 - кидаем исключение "не верное направление"
				break;
			case KB_DOWN:
				((rob.get_Y() + 1) > 10) ? throw OffTheField(rob) : rob.set_Y(rob.get_Y() + 1); // если получим больше 10 - кидаем "выход за пределы поля" 
				break;
			case KB_LEFT:
				((rob.get_X() - 1) < 0) ? throw IllegalCommand(rob) : rob.set_X(rob.get_X() - 1); // если получим меньше 0 - кидаем исключение "не верное направление";
				break;
			case KB_RIGHT:
				((rob.get_X() + 1) > 10) ? throw OffTheField(rob) : rob.set_X(rob.get_X() + 1); // если получим больше 10 - кидаем "выход за пределы поля"
				break;
			}
		}
		catch (IllegalCommand&) { answer = _getch(); }
		catch (OffTheField&) { answer = _getch(); }
	}
	
}