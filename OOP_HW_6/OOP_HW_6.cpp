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

// ==========================
//          Task3
// ==========================
//3. Реализовать класс Player, который наследует от класса GenericPlayer.У этого класса будет 4 метода:
//• virtual bool IsHitting() const - реализация чисто виртуальной функции базового класса.
// Метод спрашивает у пользователя, нужна ли ему еще одна карта и возвращает ответ пользователя в виде true или false.
//• void Win() const - выводит на экран имя игрока и сообщение, что он выиграл.
//• void Lose() const - выводит на экран имя игрока и сообщение, что он проиграл.
//• void Push() const - выводит на экран имя игрока и сообщение, что он сыграл вничью.


class GenericPlayer{//заглушка
public:
    virtual bool const IsHitting();
    std::string  getName() const { return name; };
private:
    std::string name = "";
};

class Player : public GenericPlayer {
public:
    bool const IsHitting() override {
        std::string answer = "";
        answer.resize(1);
        bool repit = true;
        do {
            std::cout << "Do U need a card more? (y/n)";
            std::cin >> answer;
            if (answer == "y") { return true; };
            if (answer == "n") { return false; };
            system("cls");
        } while (true);
    };
    void Win() const { std::cout << getName() << " is Winer!";  };
    void Lose() const { std::cout << getName() << " is Looser!"; };
    void Push() const { std::cout << "Have no winer!"; };
};
 

// ==========================
//          Task4
// ==========================
// 4. Реализовать класс House, который представляет дилера.Этот класс наследует от класса GenericPlayer.
// У него есть 2 метода:
//• virtual bool IsHitting() const - метод указывает, нужна ли дилеру еще одна карта.Если у дилера не больше 16 очков, то он берет еще одну карту.
//• void FlipFirstCard() - метод переворачивает первую карту дилера.

class House : public GenericPlayer {
    bool const IsHitting() override {

    }
    void FlipFirstCard() {
        
    };
};

// ==========================
//          Task5
// ==========================
//5. Написать перегрузку оператора вывода для класса Card.
//Если карта перевернута рубашкой вверх(мы ее не видим), вывести ХХ, если мы ее видим, 
//вывести масть и номинал карты.Также для класса GenericPlayer написать перегрузку оператора вывода, 
//который должен отображать имя игрока и его карты, а также общую сумму очков его карт.

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