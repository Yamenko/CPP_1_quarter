#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <string>
#include <regex>

//============================================================================================
// 1.Реализуйте шаблонную функцию Swap, которая принимает два указателя и обменивает
// местами значения, на которые указывают эти указатели(нужно обменивать именно сами
// указатели, переменные должны оставаться в тех же адресах памяти).
//============================================================================================
template<typename T>
void Swap(T &ptrVar1, T &ptrVar2) {
    std::swap(ptrVar1, ptrVar2);
};


//============================================================================================
// 2.Реализуйте шаблонную функцию SortPointers, которая принимает вектор указателей и
// сортирует указатели по значениям, на которые они указывают.
//============================================================================================

void SortPointers(std::vector<int*> &vector) {
    std::sort(vector.begin(), vector.end());
}

void PrintVector(std::vector<int*>& vector) {
    for (auto el : vector){
        std::cout << el << ", el = " << *el <<std::endl;
    }
    std::cout << std::endl;
}


//============================================================================================
// 3.Подсчитайте количество гласных букв в книге “Война и мир”.
// Для подсчета используйте 4 способа:
//  - count_if и find
//  - count_if и цикл for
//  - цикл for и find
//  - 2 цикла for
//Замерьте время каждого способа подсчета и сделайте выводы.
//============================================================================================

//объявим глобально чтобы не передавать по ссылкам
std::vector<char> vFindSymbol = { 'а','е','ё','и','о','у','э','ю','я','А','Е','Ё','И','О','У','Э','Ю','Я' };
int countSymb = 0;

int FindCount_if_regex(std::string& line) {
    return std::count_if(line.begin(), line.end(), [](char c, std::string s = "")->bool {return regex_match(s += c, std::regex("[аеёиоуэюяАЕЁИОУЭЮЯ]"));});
}

int FindCount_if_find(std::string& line) {
    return std::count_if(line.begin(), line.end(), [](char c)->bool {return vFindSymbol.end() != std::find(vFindSymbol.begin(), vFindSymbol.end(), c);});
}

int FindCount_if_for(std::string& line) {
    return std::count_if(line.begin(), line.end(), [](char c)->bool {
        for (int i = 0; i < vFindSymbol.size(); i++) {
            if (vFindSymbol[i] == c) return true;
        }
        return false;});
}

int FindFor_find(std::string& line) {
    for (int i = 0; i < line.size(); i++) {
        auto element = std::find(vFindSymbol.begin(), vFindSymbol.end(), line[i]);
        if (element != vFindSymbol.end()) {
            countSymb++;
        }
    }
    return countSymb;
}

int FindFor_For(std::string& line) {
    for (int i = 0; i < line.size(); i++) {
        for (int j = 0; j < vFindSymbol.size(); j++) {
            if (vFindSymbol[j] == line[i]) {
                countSymb++;
            }
        }
    }
    return countSymb;
}

//Справка :
//    count_if - это алгоритмическая функция из STL, которая принимает 3 параметра : итератор на
//    начало, итератор на конец и унарный предикат(функцию, принимающую один параметр и
//        возвращающую тип bool).
//    find - это метод класса string, который возвращает позицию символа(строки), переданного в
//    качестве параметра, в исходной строке.Если символ не найден, то метод возвращает
//    string::npos.


int main(){
    std::cout << "-------------------TASK1----------------------" << std::endl;
    
    // Переменные
    int a = 5;
    int b = 10;
    int* ptrA = new int;
    int* ptrB = new int;

    *ptrA = a;
    *ptrB = b;

    // Вывод до
    std::cout << "Before swap: " << std::endl;
    std::cout << "a = " << a << ", ptrA = " << ptrA << ", *ptrA = " << *ptrA << std::endl;
    std::cout << "b = " << b << ", ptrB = " << ptrB << ", *ptrB = " << *ptrB << std::endl;

    //обмен указателей
    Swap(ptrA, ptrB);

    //вывод после
    std::cout << "After swap: " << std::endl;
    std::cout << "a = " << a << ", ptrA = " << ptrA << ", *ptrA = " << *ptrA << std::endl;
    std::cout << "b = " << b << ", ptrB = " << ptrB << ", *ptrB = " << *ptrB << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "-------------------TASK2----------------------" << std::endl;
    
    //переменные для второй задачи
    std::vector<int*> vc;
    int c = 30, d = 15, e = 25;
    int* ptrC = new int;
    int* ptrD = new int;
    int* ptrE = new int;
    *ptrC = c; *ptrD = d; *ptrE = e;
    vc = { ptrA, ptrB, ptrC, ptrD, ptrE };

    //вывод до
    std::cout << "Before sort: " << std::endl;
    PrintVector(vc);
    
    //сортировка
    SortPointers(vc);

    // вывод после
    std::cout << "After sort: " << std::endl;
    PrintVector(vc);

    //чмстим память
    delete ptrA, ptrB, ptrC, ptrD, ptrE;
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "-------------------TASK3----------------------" << std::endl;

    // переменные
    std::string line = "";
    
    //открываем файл и берем строки
    std::ifstream fileOpen("voynaimirtom1.txt"); //test.txt, voynaimirtom1.txt;

    if (fileOpen) {
        
        // 1. Подсчет через count_if и regex
        auto start = std::chrono::high_resolution_clock::now();
        while (!fileOpen.eof()) {
            std::getline(fileOpen, line);
            countSymb += FindCount_if_regex(line);
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto int_s = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        std::cout << "count_if needs " << int_s.count() << " milliseconds" << std::endl;
        std::cout << "Symbols found =  " << countSymb << std::endl;
        
        // В начало файла
        fileOpen.clear();
        fileOpen.seekg(0, fileOpen.beg);
        countSymb = 0;

        // 2. Подсчет через count_if и find
        start = std::chrono::high_resolution_clock::now();       
        while (!fileOpen.eof()) {
            std::getline(fileOpen, line);
            countSymb += FindCount_if_find(line);
        }

        end = std::chrono::high_resolution_clock::now();
        int_s = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        std::cout << "count_if needs " << int_s.count() << " milliseconds" << std::endl;
        std::cout << "Symbols found =  " << countSymb << std::endl;


        // В начало файла
        fileOpen.clear();
        fileOpen.seekg(0, fileOpen.beg);
        countSymb = 0;

        // 3. Подсчет через count_if и for
        while (!fileOpen.eof()) {
            std::getline(fileOpen, line);
            countSymb += FindCount_if_for(line);
        }

        end = std::chrono::high_resolution_clock::now();
        int_s = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        std::cout << "count_if needs " << int_s.count() << " milliseconds" << std::endl;
        std::cout << "Symbols found =  " << countSymb << std::endl;

        // В начало файла
        fileOpen.clear();
        fileOpen.seekg(0, fileOpen.beg);
        countSymb = 0;

        // 4. Подсчет через for и Find
        while (!fileOpen.eof()) {
            std::getline(fileOpen, line);
            countSymb = FindFor_find(line);
        }

        end = std::chrono::high_resolution_clock::now();
        int_s = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        std::cout << "count_if needs " << int_s.count() << " milliseconds" << std::endl;
        std::cout << "Symbols found =  " << countSymb << std::endl;
        
        // В начало файла
        fileOpen.clear();
        fileOpen.seekg(0, fileOpen.beg);
        countSymb = 0;

        // 5. Подсчет через for и for
        while (!fileOpen.eof()) {
            std::getline(fileOpen, line);
            countSymb = FindFor_For(line);
        }

        end = std::chrono::high_resolution_clock::now();
        int_s = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        std::cout << "count_if needs " << int_s.count() << " milliseconds" << std::endl;
        std::cout << "Symbols found =  " << countSymb << std::endl;
    }
    fileOpen.close();
    std::cout << "----------------------------------------------" << std::endl;
}