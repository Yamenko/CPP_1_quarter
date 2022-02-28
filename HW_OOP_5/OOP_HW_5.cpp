#include <iostream>

//===========================
//           Task 1
//===========================
// Реализовать шаблон класса Pair1, который позволяет пользователю передавать данные одного типа парами.
// Следующий код :
//
// int main()
// {
//    Pair1<int> p1(6, 9);
//    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';
//
//    const Pair1<double> p2(3.4, 7.8);
//    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
//
//    return 0;
// }
// … должен производить результат :
// Pair: 6 9
// Pair : 3.4 7.8

template <class T>
class Pair1{
private:
    T first;
    T second;
public:

    Pair1(T first, T second) {
        this->first = first;
        this->second = second;
    };

    T getFirst() const { return this->first; };
    T getSecond() const { return this->second; };
};

//===========================
//           Task 2
//===========================
//2. Реализовать класс Pair, который позволяет использовать разные типы данных в передаваемых парах.
//Следующий код :
//
//int main()
//{
//    Pair<int, double> p1(6, 7.8);
//    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';
//
//    const Pair<double, int> p2(3.4, 5);
//    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
//
//    return 0;
//}
//
//… должен производить следующий результат :
//Pair: 6 7.8
//Pair : 3.4 5
//
//Подсказка : чтобы определить шаблон с использованием двух разных типов, просто разделите параметры типа шаблона запятой.
template <class T1, class T2>
class Pair {
private:
    T1 first;
    T2 second;
public:
    Pair(T1 first, T2 second) {
        this->first = first;
        this->second = second;
    };
    //T getFirst();
    //T getSecond();
    T1 getFirst() { return this->first; };
    T2 getSecond() { return this->second; };
};

//===========================
//           Task 3
//===========================
// 3. Написать шаблон класса StringValuePair, в котором первое значение всегда типа string, а второе — любого типа.
// Этот шаблон класса должен наследовать частично специализированный класс Pair, в котором первый параметр — string, а второй — любого типа данных.
// Следующий код :
//
// int main()
// {
//    StringValuePair<int> svp("Amazing", 7);
//    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
//    return 0;
// }
//
// … должен производить следующий результат :
// Pair: Amazing 7
//
// Подсказка : при вызове конструктора класса * *Pair * из конструктора класса StringValuePair не забудьте указать, что параметры относятся к классу Pair. *

template <class T>
class StringValuePair : public Pair <std::string, T> {
public:
    StringValuePair(std::string s, T value) : Pair<std::string, T>(s, value) {  }; // если явно не указать Pair<std::string, T>, ругается, что нет базовокго конструктора для Pair
};
  

//===========================
//           Task 4
//===========================
// 4. Согласно иерархии классов, которая представлена в методичке к уроку 3, от класса Hand наследует класс GenericPlayer, 
// который обобщенно представляет игрока, ведь у нас будет два типа игроков - человек и компьютер.
// Создать класс GenericPlayer, в который добавить поле name - имя игрока.Также добавить 3 метода :
//    • IsHitting() - чисто виртуальная функция, возвращает информацию, нужна ли игроку еще одна карта.
//    • IsBoosted() - возвращает bool значение, есть ли у игрока перебор
//    • Bust() - выводит на экран имя игрока и объявляет, что у него перебор.

// чтобы программа собралась. оставим заготовку.
class Hand {
public:
    int GetValue() {};
}; 

class GenericPlayer : public Hand {
private:
    std::string name = "";
public:
    virtual bool IsHitting() { };
    bool IsBoosted() { GetValue() > 21 ? true : false; };
    void Bust() { std::cout << this->name << "has a bust!" << std::endl; };
};





int main()
{
// Task 1
    std::cout << "Task 1:" << std::endl;
    Pair1<int> p1(6, 9);

    std::cout << "Pair: " << p1.getFirst() << " " << p1.getSecond() << std::endl;

    const Pair1<double> p2(3.4, 7.8);
    std::cout << "Pair: " << p2.getFirst() << " " << p2.getSecond() << std::endl;

    std::cout << std::endl;

// Task 2
    std::cout << "Task 2:" << std::endl;
    
    Pair<int, double> p3(6, 7.8);
    std::cout << "Pair: " << p3.getFirst() << " " << p3.getSecond() << std::endl;

    Pair<double, int> p4(3.4, 5);
    std::cout << "Pair: " << p4.getFirst() << " " << p4.getSecond() << std::endl;

    std::cout << std::endl;

// Task 3
    std::cout << "Task 2:" << std::endl;
    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.getFirst() << " " << svp.getSecond() << std::endl;

    std::cout << std::endl;
    return 0;
}