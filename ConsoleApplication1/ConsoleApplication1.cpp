#include <iostream>
//#include <fstream>
//
//std::string nameFile, textToFile;
//
//std::string askFile()
//{
//    std::cout << "Enter file: ";
//    std::cin >> nameFile;
//    std::cout << std::endl;
//    return nameFile;
//}
//
//void enteringDataToFile(std::string textToFile)
//{
//    std::ofstream fout(askFile(), std::ios::app); // открываем и находим конец файла.
//    fout << textToFile;
//    fout << std::endl;
//    std::cout << "ADD TEXT: " << textToFile << std::endl; // это для проверки
//    fout.close();
//}
//


//int main()
//{
//    //enteringDataToFile("Text for add to first");
//    //enteringDataToFile("Text for add to second");
//}

#include <iostream>

unsigned int PRNG()
{
    // наше начальное число - 5323
    static unsigned int seed{ 5323 };

    // Берём текущее порождающее значение и генерируем из него новое значение
    // Из-за того, что мы используем большие константы и переполнение,
    // будет сложно случайно предсказать, какое получится следующее число
    // из предыдущего.
    seed = 8253729 * seed + 2396403;

    // Берём число и возвращаем значение от 0 до 32767
    return (seed % 5)%2;
}

int main()
{
    // Напечатать 100 случайных чисел
    for (int count{ 1 }; count <= 100; ++count)
    {
        std::cout << PRNG() << '\t';

        // Если мы напечатали 5 чисел, начинаем новую строку
        if (count % 5 == 0)
            std::cout << '\n';
    }

    return 0;
}
