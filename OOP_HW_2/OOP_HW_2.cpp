#include <iostream>
#include <string>

//1. Создать класс Person(человек) с полями : имя, возраст, пол и вес.
//Определить методы переназначения имени, изменения возраста и веса.
//Создать производный класс Student(студент), имеющий поле года обучения.
//Определить методы переназначения и увеличения этого значения.
//Создать счетчик количества созданных студентов.
//В функции main() создать несколько(не больше трёх) студентов.
//Вывести информацию о них.

//================================
//         Task 1
//================================

class Person
{
	static int countCreation;
public:
	void setAge(const int& age) {
		this->age = age;
	};
	void setWeight(const float& weight) {
		this->weight = weight;
	};
	void setSex(const bool& sex) {
		this->sex = sex;
	};
	void setName(const std::string& name) {
		this->name = name;
	};
	void getCountCreation() {
		std::cout << "Count creation = " << countCreation << std::endl;
	}
	void setAddCountCreation() {
		this->countCreation++;
	};
	void setDecCountCreation() {
		this->countCreation--;
	};
	void getInformation() {
		std::cout << "Name: " << this->name << " , age - " << this->age;
		if (this->sex) {
			std::cout << " , sex - man" ;
		}
		else {
			std::cout << " , sex - woman";
		}
		std::cout << ", weight - " << this->weight << std::endl;
	};

private:
	std::string name = "";
	
	int age = 0;
	float weight = 0.00f;
	bool sex = 1; // 1 - man, 0 - woman
};
int Person::countCreation = 0;

class Student : public virtual Person 
{

public:
	Student	()	{	setAddCountCreation();	};
	~Student()	{	setDecCountCreation();	};
	Student	(const std::string& name, const int& age, const int& year, const bool& sex, const float& weight) {
		setName(name);
		setAge(age);
		setSex(sex);
		setWeight(weight);
		setYearStudie(year);
		Student();
	};
	void setYearStudie(const int& year) {
		this->yearStudie = year;
	};

private:
	int yearStudie = 0;
};

//2. Создать классы Apple(яблоко) и Banana(банан), которые наследуют класс Fruit(фрукт).
//У Fruit есть две переменные - члена: name(имя) и color(цвет).
//Добавить новый класс GrannySmith, который наследует класс Apple.

//================================
//         Task 2
//================================

class Fruit
{
public:
	void setName(std::string name) {
		this->name = name;
	};
	void setColor(std::string color) {
		this->color = color;
	};
	std::string getName() {
		return this->name;
	};
	std::string getColor() {
		return this->color;
	};

private:
	std::string name = "";
	std::string color = "";
};

class Apple : virtual public Fruit
{
public:
	Apple(std::string color = "green") {
		setColor(color);
		setName("apple");
	};
};

class Banana : virtual public Fruit
{
public:
	Banana(std::string color = "yelow") {
		setColor(color);
		setName("banana");
	};
};

class GrannySmith : virtual public Apple
{
public:
	GrannySmith() {
		setName("GrannySmith");
	};
};

//================================
//         Task 3
//================================
//1. Создадим класс Карта (2 переменных (Название и Значение), 4 функции (2 геттера и 2 сеттера))
//2. Создать массив классов карт размером 52 
// (в колоде 52 карты (9 карт со значениями (2-10) по 4 масти) + 3 картинки со Значением "10" по 4 масти + 1 картинка со Значением "11" по 4 масти)
//3. Создать цикл заполнения массива.
//4. (2 и 3 можно объединить в класс Колода) + добавить 2 переменные для хранения кол-ва карт и 1/3 этого значения 
// 4.1 Создать класс игрок (в мейне создать 2 игрока компьютер и человек) класс должен содержать 2 переменные
// компьютер будет одну скрывать.
// а человеку на всякий случай если будет нужен сплит.
//
//5. для игры необходимо несколько колод, создадим несколько объектов класса Колода, поместим их в массив колод.
//6. В бесконечном цикле (while (функция "условие победы или проигрыша") ) рандомайземом выбираем колоду и карту из нее, поочереди выкладываем карты "диллеру" (одну можно спрятать в переменной) и игроку по 2 карты
// карты в колодах заменяем на 0. (чтобы больше их не выбирать) уменьшаем переменную хранения карт.
//7. ждем ответ игрока на продолжение/сплит/достаточно
//8. в каждом случае будет разная методика.
// - продолжение: добавляем карту игроку и отправляем на проверку (если < 21 спрашиваем еще одну карту)
// - сплит: как бы добавляем еще одно "игрока" и разбиваем по одной карте каждому раздаем по карте каждому "игроку" и возвращаемся к вопросу "еще?"
// - достаточно: если у "дилера" < 17 или < чем у одного из "игроков" (если сплит) добираем карту из колоды
//9. Сообщение о победе или проигрыше.
//10. "сыграть еще раз?" (проверяем перемунные кол-ва карт и если в стопке меньше 1/3, обновляем колоду. )  
//


int main()
{
	//Task 1
	Student stud1("Anton", 22, 2010, 1, 72.1);
	Student stud2("Marina", 19, 2015, 0, 64.2);
	Student stud3("Evgenia", 20, 2016, 0, 63.5);
	stud1.getInformation();
	stud2.getInformation();
	stud3.getInformation();
	stud1.getCountCreation(); // Будет 0 так как все копии разрушились и сработал деструктор. Если закомментировать деструктор то выведет 3

	//Task 2 

	Apple a("red");
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
}
