/*
1. Написать программу, проверяющую что сумма двух(введенных с клавиатуры) чисел лежит в пределах от 10 до 20 (включительно), 
если да – вывести строку "true", в противном случае – "false";
2. Написать программу, выводящую на экран строку “true”, если две целочисленные константы, 
объявленные в её начале либо обе равны десяти сами по себе, либо их сумма равна десяти.Иначе "false".
3. Написать программу которая выводит на экран список всех нечетных чисел он 1 до 50. 
Например: "Your numbers: 1 3 5 7 9 11 13 ...".Для решения используйте любой С++ цикл.
4. Со звёздочкой.Написать программу, проверяющую, является ли некоторое число - простым.
Простое число — это целое положительное число, которое делится без остатка только на единицу и себя само.
5. Со звёздочкой.Пользователь вводит с клавиатуры число(год) : от 1 до 3000. 
Написать программу, которая определяет является ли этот год високосным.
Каждый 4 - й год является високосным, кроме каждого 100 - го, при этом каждый 400 - й – високосный.
Вывести результаты работы программы в консоль.
*/
#include <iostream>
int entered_num1;
int entered_num2;

int main()
{
    // 1. Занадие
    
    std::cout << "Enter 2 numbers: ";
    std::cin >> entered_num1 >> entered_num2;
    int my_sum = entered_num1 + entered_num2;
    if (my_sum >= 10 && my_sum <= 20) { std::cout << "true" << std::endl; }
    else { std::cout << "false" << std::endl; }
    
    // 2. Задание
    const int x = 8;
    const int y = 2;

    if (((x + y) == 10) || ((x == 10) && (y  == 10))) { std::cout << "true" << std::endl; }
    else { std::cout << "false" << std::endl; }

    // 3. Задание
    for (int i = 1; i <= 50; i++) {
        if (i % 2 != 0) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;

    // 4. Задание
    std::cout << "Enter \"simpl\" number: ";
    std::cin >> entered_num1;
    // Если это 1 или 2 делаем проверку и заканчиваем, если это другое число то уходим в перебор значений.
    if (entered_num1 == 1 || entered_num1 == 2) {
        std::cout << entered_num1<< " IS \"simpl\"" << std::endl;
    }
    else {
        // Предел измерения должен быть на 1 меньше чем само число так как оно в любом случае разделиться само на себя
        // использовал (entered_num - 1) чтобы было реально видно что мы берем на единицу меньше, можно i < entered_num 
        // от 2 - так как на 1 делятся все простые числа.
        for (int i = 2; i <= (entered_num1 - 1); i++) {  

            if (entered_num1 % i == 0) {
                std::cout << entered_num1 << " NOT \"simpl\"" << std::endl;
                break;
            }
            else { 
                std::cout << entered_num1 << " IS \"simpl\"" << std::endl;
                break;
            }
        }
    }

//5. Со звёздочкой.Пользователь вводит с клавиатуры число(год) : от 1 до 3000. 
//Написать программу, которая определяет является ли этот год високосным.
//Каждый 4 - й год является високосным, кроме каждого 100 - го, при этом каждый 400 - й – високосный.
//Вывести результаты работы программы в консоль.

    do {
        std::cout << "Enter year (round 1 - 3000): ";
        std::cin >> entered_num1;
    } while ((entered_num1 < 1) || (entered_num1 > 3000)); // тута проверка ввода. не нашел как в cin сразу проверить
    if ((entered_num1 % 4 == 0) && (!(entered_num1 % 100 == 0) || entered_num1 % 400 == 0)) {
        // Логика такая: 
        // 1. проверяем остаток от деления на 4 -> OK (если нет, то сразу переходим в else)
        // 2. проверяем остаток от деления на 100 и переворачиваем.
        // Всегда когда у нас эта операция будет false мы ее переворачиваем в true
        // оба true дают нам високосный год и как только год будет делится ровно на 100 
        // мы получим true и перевернем его в false и перейдем к else!!! 
        // 3. Но если нам надо добавить 400 годы добавляем ИЛИ к проверке.
        // Получается, что во второй скобке будет true когда будем делить на 400
        std::cout << entered_num1 << " Visokosnyi!";
    }
    else {
        std::cout << entered_num1<< " Oby4nyi.";
    }
}
