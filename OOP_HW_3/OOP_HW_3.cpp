#include <iostream>
const double PI = 3.141592653589793238463;

//================================
//         Task 1
//================================
// 1. Создать абстрактный класс Figure(фигура).
// Его наследниками являются классы Parallelogram(параллелограмм) и Circle(круг).
// Класс Parallelogram — базовый для классов Rectangle(прямоугольник), Square(квадрат), Rhombus(ромб).
// Для всех классов создать конструкторы.
// Для класса Figure добавить чисто виртуальную функцию area() (площадь).
// Во всех остальных классах переопределить эту функцию, исходя из геометрических формул нахождения площади.
class Figure
{
public:
	virtual float area() = 0;
};

class Circle : public Figure
{
public:
	Circle() {};
	Circle(float r) : r(r) {	};
	Circle(double d) : r(d / 2) {	};

	float area() {
		return PI * pow(this->r, 2);
	};

private:
	float r = 0;
};

class Parallelogram : public Figure
{
public:
	Parallelogram() {};
	Parallelogram(float a, float h) : a_side (a), h_side(h) {};
	Parallelogram(float a, float b, float alfa) {
		this->a_side = a;
		this->h_side = b * sin(alfa * PI / 180);
	};
	float area() override {	return a_side * h_side;	};
	void setA_side(float a) { this->a_side = a;	};
	void setH_side(float h) { this->h_side = h; };
private:
	float a_side = 0;
	float h_side = 0;
};

class Rectangle : public Parallelogram
{
public:
	Rectangle() {};
	Rectangle(float a, float h) : Parallelogram(a, h) {	};
};

class Square : public Parallelogram
{
public:
	Square(){};
	Square(float a) : Parallelogram(a, a) {};
};

class Rhombus : public Parallelogram
{
public:
	Rhombus(){};
	Rhombus(float a, float h) : Parallelogram(a, h) {};
	Rhombus(float a, float b, float alfa) : Parallelogram(a, b, alfa) {};
};

//================================
//         Task 2
//================================
// 2. Создать класс Car(автомобиль) с полями company(компания) и model(модель).
// Классы - наследники: PassengerCar(легковой автомобиль) и Bus(автобус).
// От этих классов наследует класс Minivan(минивэн).
// Создать конструкторы для каждого из классов, чтобы они выводили данные о классах.
// Создать объекты для каждого из классов и посмотреть, в какой последовательности выполняются конструкторы.
// Обратить внимание на проблему «алмаз смерти».
// Примечание : если использовать виртуальный базовый класс, то объект самого "верхнего" базового класса создает самый "дочерний" класс.

class  Car
{
public:
	Car(){
		std::cout << "1. Make a Car class" << std::endl;
	};
	~Car() {
		std::cout << "1. Destroy a Car class" << std::endl;
	};

private:
	std::string company = "";
	std::string model = "";

};

class PassengerCar : virtual public Car
{
public:
	PassengerCar() {
		std::cout << "2. Make a PassengerCar class" << std::endl;
	};
	~PassengerCar() {
		std::cout << "2. Destroy a PassengerCar class" << std::endl;
	};

private:

};

class Bus : virtual public Car
{
public:
	Bus() {
		std::cout << "3. Make a Bus class" << std::endl;
	};
	~Bus() {
		std::cout << "3. Destroy a Bus class" << std::endl;
	};

private:

};

class Minivan : public PassengerCar, Bus
{
public:
	Minivan() {
		std::cout << "4. Make a Minivan class" << std::endl;
	};
	~Minivan() {
		std::cout << "4. Destroy a Minivan class" << std::endl;
	};

private:

};

//================================
//         Task 3
//================================
// 3. Создать класс : Fraction(дробь).Дробь имеет числитель и знаменатель(например, 3 / 7 или 9 / 2).
// Предусмотреть, чтобы знаменатель не был равен 0. 
// Перегрузить :
//    математические бинарные операторы(+, -, *, / ) для выполнения действий с дробями
//    унарный оператор(-)
//    логические операторы сравнения двух дробей(== , != , <, >, <= , >= ).
// Примечание : Поскольку операторы < и >= , > и <= — это логические противоположности, попробуйте перегрузить один через другой.
// Продемонстрировать использование перегруженных операторов.

class Fraction
{
public:
	Fraction(){};
	Fraction(int num, int denom) {
		this->numerat = num;
		if (denom == 0) {
			this->denominat = 1;
			this->numerat = std::numeric_limits<int>::max();
		}
		else {
			this->denominat = denom;
		}
	};
	void print() {
		std::cout << this->numerat << "/" << this->denominat << std::endl;
	};

	Fraction& Shorten(Fraction& other) {
		for (int i = other.numerat; i >= 2 ; i--)
		{
			if (other.numerat % i == 0 && other.denominat % i == 0) {
				other.numerat /= i;
				other.denominat /= i;
			}
		}
		return other;
	};
	
	//унарный оператор(-)
	Fraction& operator - () { 
		this->numerat = -this->numerat;
		return *this;
	};
	// Математические функции
	Fraction& operator + (const Fraction& other) { // Сложение
		Fraction tmp;
		tmp.numerat = this->numerat * other.denominat + other.numerat * this->denominat;
		tmp.denominat = this->denominat * other.denominat;
		Shorten(tmp);
		return tmp;
	};
	Fraction& operator - (const Fraction& other) { // Вычитание
		Fraction tmp;
		tmp.numerat = this->numerat * other.denominat - other.numerat * this->denominat;
		tmp.denominat = this->denominat * other.denominat;
		Shorten(tmp);
		return tmp;
	};
	Fraction& operator * (const Fraction& other) { // Умножение
		Fraction tmp;
		tmp.numerat = this->numerat * other.numerat;
		tmp.denominat = this->denominat * other.denominat;
		Shorten(tmp);
		return tmp;
	};
	Fraction& operator / (const Fraction& other) { // Деление
		Fraction tmp;
		tmp.numerat = this->numerat * other.denominat;
		tmp.denominat = this->denominat * other.numerat;
		Shorten(tmp);
		return tmp;
	};

	//логические операторы
	bool operator == (Fraction& other) { // Точное сравнение
		Fraction tmp1 = Shorten(*this), tmp2 = Shorten(other);
		if (tmp1.numerat == tmp2.numerat && tmp1.denominat == tmp2.denominat) {
			return true;
		}
		else {
			return false;
		}		
	};
	bool operator > (Fraction& other) { // Больше
		Fraction tmp1 = Shorten(*this), tmp2 = Shorten(other);
		if ((tmp1.numerat * tmp2.denominat) > (tmp2.numerat * tmp1.denominat)) {
			return true;
		}
		else {
			return false;
		}
	};
	bool operator < (Fraction& other) { // Меньше
		Fraction tmp1 = Shorten(*this), tmp2 = Shorten(other);
		if ((tmp1.numerat * tmp2.denominat) < (tmp2.numerat * tmp1.denominat)) {
			return true;
		}
		else {
			return false;
		}
	};
	bool operator >= (Fraction& other) { // Больше или равно
		return !this->operator<(other);
	};
	bool operator <= (Fraction& other) { // Меньше или равно
		return !this->operator>(other);
	};

private:
	int numerat = 0, denominat = 1;
};

//================================
//         Task 4
//================================
// 4. Создать класс Card, описывающий карту в игре БлэкДжек.
// У этого класса должно быть три поля : масть, значение карты и положение карты(вверх лицом или рубашкой).
// Сделать поля масть и значение карты типом перечисления(enum).Положение карты - тип bool.
// Также в этом классе должно быть два метода :
// метод Flip(), который переворачивает карту, т.е.если она была рубашкой вверх, то он ее поворачивает лицом вверх, и наоборот.
// метод GetValue(), который возвращает значение карты, пока можно считать, что туз = 1.

class Card
{
private:
	enum Mast { BUBY, CHERVY, KRESTY, PIKY };
	enum CostCard : int { ACE = 1, TWO = 2, TREE = 3, FOUR = 4, FIVE = 5, SIX = 6, SEVEN = 7, EIGHT = 8, NINE = 9, TEN = 10, JACK = 10, QUEEN = 10, KING = 10 };
	Mast mast = CHERVY;
	CostCard cost = QUEEN;
	bool crap = true;
public:

	void Flip() { crap = !crap; };
	CostCard GetValue() {
		return this->cost;
	}
};


int main()
{
	// Task 1
	std::cout << "Task 1 " << std::endl;
	Rectangle ret(10.0, 20.5); // прямоугольник
	std::cout << "Area of Rectangle (10.0, 20.5) = " << ret.area() << std::endl;
	Circle cir(20.0); // double
	std::cout << "Area of Circle (20) = " << cir.area() << std::endl;
	Square sqr(4);
	std::cout << "Area of Square (4) = " << sqr.area() << std::endl;
	Rhombus rmb(10, 10, 30);
	std::cout << "Area of Rhombus (10, 10, 30`) = " << rmb.area() << std::endl;

	//Task 2
	std::cout << std::endl << "Task 2 " << std::endl;
	Car car;
	std::cout << std::endl;
	PassengerCar pasCar;
	std::cout << std::endl;
	Bus bus;
	std::cout << std::endl;
	Minivan minV; // Создает только 1 класс Car

	//Task 3
	std::cout << std::endl << "Task 3 " << std::endl;
	Fraction m(1, 4);
	Fraction n(2, 5);
	Fraction funcMN = m + n;
	funcMN.print();
	
	funcMN = n - m;
	funcMN.print();
	std::cout << "look Biger: " << (funcMN > m) << std::endl;

	funcMN = n * m;
	funcMN.print();
	std::cout << "look Smaller: " << (funcMN < m) << std::endl;

	funcMN = n / m;
	funcMN.print();
	std::cout << "look Equal: " << (funcMN == m) << std::endl;
	m = -m;
	m.print();
	std::cout << "look Biger or Equal: " << (funcMN >= m) << std::endl;
	std::cout << "look Smaller or Equal: " << (funcMN <= m) << std::endl;


	Card myCard;
	std::cout << std::endl << "Card: " << myCard.GetValue() << std::endl;

	std::cout << std::endl << "Task 2 (Destructors) " << std::endl;

}