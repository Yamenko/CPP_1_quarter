#include <iostream>
#include <string>

// ==========================
//          Task1
// ==========================
// 1. Создать программу, которая считывает целое число типа int.
// И поставить «защиту от дурака» : если пользователь вводит что - то кроме одного целочисленного значения, 
// нужно вывести сообщение об ошибке и предложить ввести число еще раз.Пример неправильных введенных строк :
//rbtrb
//nj34njkn
//1n

// ==========================
//          Task2
// ==========================
//2. Создать собственный манипулятор endll для стандартного потока вывода, который выводит два перевода строки и сбрасывает буфер.

std::ostream& endll (std::ostream& out) {
    out << std::endl << std::endl;
    return out;
};


int main()
{
    //Task 1
    std::cout << "Task 1." << std::endl;
    std::string myLine = "";
    bool hasAlpha = false;
    do {
        hasAlpha = false;
        std::cout << "Enter number: ";
        std::cin >> myLine;

        for (auto oneElement : myLine) {
            if (!isdigit(oneElement)) {
                system("cls");
                std::cout << "U entered not a number!!!" << std::endl;
                hasAlpha = true;
                break;
            }
        }
    } while (hasAlpha);  
    std::cout << std::endl << "Tanks. Ur number: " << myLine << std::endl;

    //Task 2
    std::cout << "Task 2." << std::endl;
    std::cout << "Line 1." << endll << "Line 2." << std::endl << "Line 3.";
}