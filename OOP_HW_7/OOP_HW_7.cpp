#include <iostream>
#include <memory>

//=======================
//			Task 1
//=======================

// 1. Создайте класс Date с полями день, месяц, год и методами доступа к этим полям.
// Перегрузите оператор вывода для данного класса.
// Создайте два "умных" указателя today и date.
// Первому присвойте значение сегодняшней даты.
// Для него вызовите по отдельности методы доступа к полям класса Date, 
// а также выведите на экран данные всего объекта с помощью перегруженного оператора вывода.
// Затем переместите ресурс, которым владеет указатель today в указатель date.
// Проверьте, являются ли нулевыми указатели today и date и выведите соответствующую информацию об этом в консоль.

class Date {
private:
	unsigned int day;
	unsigned int month;
	unsigned int year;
public:
	Date() {};
	Date(int day, int month, int year) {
		setFullDate(day, month, year);
	};

	void setDay(unsigned int const day) { this->day = day; };
	void setMonth(unsigned int const month) { this->month = month; };
	void setYear(unsigned int const year) { this->year = year; };
	void setFullDate(unsigned int const day, unsigned int const month, unsigned int const year) {
		this->setDay(day);
		this->setMonth(month);
		this->setYear(year);
	};
	unsigned int getDay() const { return this->day; };
	unsigned int getMonth() const { return this->month; };
	unsigned int getYear() const { return this->year; };

	friend std::ostream& operator<< (std::ostream& out, Date date) {
		out << date.day << "/" << date.month << "/" << date.year;
		return out;
	};
};
 
//=======================
//			Task 2
//======================= 
// 2. По условию предыдущей задачи создайте два умных указателя date1 и date2.
//• Создайте функцию, которая принимает в качестве параметра два умных указателя типа Date 
// и сравнивает их между собой(сравнение происходит по датам).Функция должна вернуть более позднюю дату.
//• Создайте функцию, которая обменивает ресурсами(датами) два умных указателя, переданных в функцию в качестве параметров.
//
//Примечание: обратите внимание, что первая функция не должна уничтожать объекты, переданные ей в качестве параметров.

std::shared_ptr<Date> latestDate(std::shared_ptr<Date> date1, std::shared_ptr<Date> date2) {
	Date d1 = *date1;
	Date d2 = *date2;
	// Сравниваем годы
	if (d1.getYear() != d2.getYear()) {	
		return (d1.getYear() > d2.getYear()) ? date1 : date2;
	}
	// Сравниваем месяцы
	if (d1.getMonth() != d2.getMonth()) {
		return (d1.getMonth() > d2.getMonth()) ? date1 : date2;
	}
	//Сравниваем дни
	if (d1.getDay() != d2.getDay()) { 
		return (d1.getDay() > d2.getDay()) ? date1 : date2;
	}
	//Если вдруг даты равны
	if ((d1.getYear() == d2.getYear()) && (d1.getMonth() == d2.getMonth()) && (d1.getDay() == d2.getDay())) {
		return date1;
	}
};

int main()
{
	//Task 1 
	std::cout << "Task 1." << std::endl;
	Date d1, d2;
	
	d1.setDay(15);
	d1.setMonth(11);
	d1.setYear(2021);

	d2.setFullDate(10, 8, 2020);
	
	Date d3(7, 10, 2015);

	std::cout << d1 << std::endl;
	std::cout << d2 << std::endl;
	std::cout << d3 << std::endl;
	
	std::shared_ptr<Date> date(new Date(10, 10, 2010));
	std::shared_ptr<Date> today(new Date(07, 03, 2022));
	std::cout << "My date: " << *date << std::endl;
	std::cout << "Today: " << *today << std::endl;
	date = today;
	std::cout << "New ptr date: " << date << " New ptr today: " << today << std::endl;

	//Task 2
	std::cout << "Task 2." << std::endl;
	std::shared_ptr<Date> date1(new Date(11, 11, 2011));
	std::shared_ptr<Date> date2(new Date(12, 12, 2012));
	std::cout << "Date 1: " << *date1 << std::endl;
	std::cout << "Date 2: " << *date2 << std::endl;
	std::cout << "Latest date: " << *latestDate(date1, date2) << std::endl;


}

