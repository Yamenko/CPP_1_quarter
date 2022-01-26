#include <iostream>
#include <fstream>

std::string nameFile, textToFile;

std::string askFile()
{
    std::cout << "Enter file: ";
    std::cin >> nameFile;
    std::cout << std::endl;
    return nameFile;
}

void enteringDataToFile(std::string textToFile)
{
    std::ofstream fout(askFile(), std::ios::app); // открываем и находим конец файла.
    fout << textToFile;
    fout << std::endl;
    std::cout << "ADD TEXT: " << textToFile << std::endl; // это для проверки
    fout.close();
}



int main()
{
    enteringDataToFile("Text for add to first");
    enteringDataToFile("Text for add to second");
}

