//1. Выделить в памяти динамический одномерный массив типа int.
// Размер массива запросить у пользователя.
// Инициализировать его числами степенями двойки : 1, 2, 4, 8, 16, 32, 64, 128 ... 
// Вывести массив на экран.
// Не забыть освободить память. = ) Разбить программу на функции.
//2. Динамически выделить матрицу 4х4 типа int.
// Инициализировать ее псевдослучайными числами через функцию rand.
// Вывести на экран.Разбейте вашу программу на функции которые вызываются из main.
//3. Написать программу, которая создаст два текстовых файла(*.txt), 
// примерно по 50 - 100 символов в каждом(особого значения не имеет с каким именно содержимым).
// Имена файлов запросить у польлзователя.
//4. * Написать функцию, «склеивающую» эти файлы в третий текстовый файл(имя файлов спросить у пользователя).
//5. * Написать программу, которая проверяет присутствует ли указанное пользователем при запуске программы слово в указанном пользователем файле
// (для простоты работаем только с латиницей).Используем функцию find которая есть в строках std::string.

#include <iostream>
#include <filesystem>
#include <fstream>
namespace fs = std::filesystem;

enum myAction
{
    ADD_ELEM, PRINT_ELEM, SEARCH_TEXT
};

std::string nameFile, textFile1, textFile2, textFile3, textToSearch, fileWhereSearch, buf; // для задания 3, 4, 5

void myUtilitiesArr(int * arrElem, const int n, myAction choose = PRINT_ELEM) { // заполнение массива
    for (size_t i = 0; i < n; i++)
    {
        switch (choose) {
        case ADD_ELEM:
            arrElem[i] = std::pow(2, i);
            break;
        case PRINT_ELEM:
            std::cout << arrElem[i] << " ";
            break;
        }
        
    }
    std::cout << std::endl;
}


void myUtilitiesArr2(int** arrElem, const int n, const int m, myAction choose = PRINT_ELEM) { // заполнение массива
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            switch (choose)
            {
            case ADD_ELEM:
                arrElem[i][j] = std::rand();
                break;
            case PRINT_ELEM:
                std::cout << arrElem[i][j] << " ";
            } 
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

std::string askFile(int num)
{
    std::cout << "Enter file " << ++num << ": ";
    std::cin >> nameFile;
    std::cout << std::endl;
    return nameFile;

}

void enteringDataToFile(std::string nameFile, std::string textToFile)
{
    std::ofstream fout(nameFile, std::ios::app); // открываем и находим конец файла.
    fout << textToFile;
    fout << std::endl;
    fout.close();
}
void glueText(std::string nameFileFrom, std::string nameFileTo) {
    std::ifstream fin(nameFileFrom);
    if (fin.is_open()) {
        while (!fin.eof()) {
            std::getline(fin, buf);
            enteringDataToFile(nameFileTo, buf);
        }
    }
}

void myUtilitiesText(std::string nameFile, myAction choise = PRINT_ELEM, std::string textSearch = "") {
    std::ifstream fin(nameFile);
    if (fin.is_open()) {
        int line = 0;
        while (!fin.eof()) {
            std::getline(fin, buf);
            line++;

            switch (choise)
            {
            case PRINT_ELEM:
                std::cout << buf;
                break;
            case SEARCH_TEXT:
                int foundPos = buf.find(textSearch);
                if (foundPos != buf.npos) {
                    std::cout << "Found - line: " << line << " Pos: " << foundPos << std::endl;
                }
                else {
                    std::cout << "Found nothing!";
                }
                break;
            }
            
        }
    }
}




int main()
{
    //1. Задание
    int n;
    std::cout << "TASK1: ";
    std::cout << "Enter the number of elements in array: ";
    std::cin >> n;

    int* myArrTask1 = new (std::nothrow) int[n];
    myUtilitiesArr(myArrTask1, n, ADD_ELEM);
    myUtilitiesArr(myArrTask1, n, PRINT_ELEM);
    delete[] myArrTask1;

    //2. Задание
    int MY_COLUMN_ARR = 4;
    int MY_ROW_ARR = 4;

    int** myArrPointer = new (std::nothrow) int*[MY_COLUMN_ARR];
    for (size_t i = 0; i < 4; i++)
    {
        myArrPointer[i] = new (std::nothrow) int[MY_ROW_ARR];
    }
    std::cout << "TASK2: ";
    myUtilitiesArr2(myArrPointer, MY_COLUMN_ARR, MY_ROW_ARR, ADD_ELEM);
    myUtilitiesArr2(myArrPointer, MY_COLUMN_ARR, MY_ROW_ARR, PRINT_ELEM);

    for (size_t i = 0; i < 4; i++)
    {
        delete[] myArrPointer[i];
    }
    delete[] myArrPointer;

    //3. Задание 
    
    const int COUNT_OF_FILE = 2;
    std::string textFile[COUNT_OF_FILE] = { "It goes without saying, books are our teachers and friends. They teach us to be kind, clever, polite, hardworking, friendly." ,
                                            "Books help us to learn more about nature, the world around us and many other interesting things." };

    
    for (size_t i = 0; i < COUNT_OF_FILE; i++)
    {
        enteringDataToFile(askFile(i), textFile[i]);
    }
    
    ////4. Задание
    std::cout << "Enter other file to glue: ";
    std::cin >> textFile3;
    glueText("1.txt", textFile3);
    glueText("2.txt", textFile3);

    myUtilitiesText(textFile3, PRINT_ELEM);

    // 5. задание
    std::cout << "Enter text to search: ";
    std::cin >> textToSearch;
    std::cout << "Enter the file name: ";
    std::cin >> fileWhereSearch;

    myUtilitiesText(fileWhereSearch, SEARCH_TEXT, textToSearch);
}
