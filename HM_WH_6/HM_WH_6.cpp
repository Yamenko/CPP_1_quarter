#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <algorithm>


std::vector<int> bankOfThings;
std::mutex myMutex1;
std::mutex myMutex2;
std::condition_variable condThing;

//====================================================
// Создайте потокобезопасную оболочку для объекта cout.
// Назовите ее pcout.
// Необходимо, чтобы несколько потоков могли обращаться к pcout и информация выводилась в консоль.
// Продемонстрируйте работу pcout.
//====================================================

class Pcout {
public:
    // Шаблон принимает один параметр который необходимо вывести в консоль
    template<typename T>
    Pcout& operator<<(T& tmp) {
        std::scoped_lock<std::mutex> sclMutex{ myMutex1 };
        std::cout << tmp;
        return *this;
    };
    // Перегруженный оператор для использования std::endl и других стандартных выражений
    Pcout& operator<<(std::ostream& (*os)(std::ostream&)) {
        std::cout << os;
        return *this;
    }

};

//====================================================
// Реализовать функцию, возвращающую i-ое простое число 
// (например, миллионное простое число равно 15485863).
// Вычисления реализовать во вторичном потоке.
// В консоли отображать прогресс вычисления(в основном потоке).
//====================================================

int myCalculation(int& num) {
    return num = num * num * num;
}

//====================================================
// Есть два человека (2 потока): хозяин и вор. 
// Хозяин приносит домой вещи(функция добавляющая случайное число в вектор 
// с периодичностью 1 раз в секунду).
// При этом у каждой вещи есть своя ценность.
// Вор забирает вещи(функция, которая находит наибольшее число и удаляет из вектора 
// с периодичностью 1 раз в 0.5 секунд), 
// каждый раз забирает вещь с наибольшей ценностью.
//====================================================

void owner() {
    int cnt = 0;
    while (cnt < 20) {
        int thing = rand() % 1000;      //создаем (вещь)
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::lock_guard<std::mutex> sclMutex(myMutex1); // блокируем поток чтобы добавить данные в вектор
        bankOfThings.push_back(thing);
        std::cout << "add thing = " << thing << std::endl;
        cnt++;
        condThing.notify_all();
    }
};

void thief() {
    while (true) {
        std::unique_lock<std::mutex> sclMutex(myMutex1);
        condThing.wait(sclMutex, []() {return !bankOfThings.empty();});

        // находим максимальный элемент и через stl algoritm и его удаляем его через итератор
        const int maxCostOfThing = *std::max_element(bankOfThings.begin(), bankOfThings.end());
        std::vector<int>::iterator it = std::find(bankOfThings.begin(), bankOfThings.end(), maxCostOfThing);

        //замираем на пол секунды перед удалением
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::cout << "thief thing = " << *it << std::endl;
        bankOfThings.erase(it);
        sclMutex.unlock();
    }
}


int main(){
    //=====================
    // Начальные данные
    //=====================
    Pcout pcout;
    std::setlocale(LC_ALL, "Russian");
    int a = 1111111;
    int b = 9999999;
    int k = 0;
    //---------------------

    std::cout << "====================="    << std::endl;
    std::cout << "      Задание 1"          << std::endl;
    std::cout << "====================="    << std::endl;

    std::thread t1([&]() {pcout << a << " " << a << " " << a << " " << a << " " << a << " | " << std::endl; });
    std::thread t2([&]() {pcout << b << " " << b << " " << b << " " << b << " " << b << " | " << std::endl; });
    t1.join();
    t2.join();
    //---------------------

    std::cout << "====================="    << std::endl;
    std::cout << "      Задание 2"          << std::endl;
    std::cout << "====================="    << std::endl;
    
    std::thread t3([&k, &a]() {k = myCalculation(a);});
    std::thread t4([&]() {pcout << "num ^ 3 = " << k << std::endl;});
    t3.join();
    t4.join();
    //---------------------

    std::cout << "====================="    << std::endl;
    std::cout << "      Задание 3"          << std::endl;
    std::cout << "====================="    << std::endl;
    std::thread t5(owner); // поток для хозяина и добавления новых вещей
    std::thread t6(thief); // поток для вора и удаления вещей
    t5.join();
    t6.join();
    //---------------------


}