#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <set>
#include <sstream>
#include <map>

// 1. Создать шаблонную функцию, которая принимает итераторы на начало и конец
// последовательности слов, и выводящую в консоль список уникальных слов
// (если слово повторяется больше 1 раза, то вывести его надо один раз).
// Продемонстрировать работу функции, передав итераторы различных типов.

template <typename T>
void printUniqWords(T& begin, T& end) {
    // множество для хранения уникальных имен (std::set)
    std::stringstream myStream;  
    std::set <std::string> uniqWords;

    // Отправим все в поток чтобы разбить потом все на слова
    std::for_each(begin, end, [&](auto oneWord) {myStream << oneWord;});
    
    // выполним функцию добавления в множество (std::set)
    std::string oneWord;
    while (!myStream.eof()) {
        myStream >> oneWord;
        uniqWords.insert(oneWord);
    }
    
    // выведем на экран получившееся множество (std::set)
    std::copy(uniqWords.begin(), uniqWords.end(), std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;
}


// 2. Используя ассоциативный контейнер, напишите программу, которая будет считывать данные
// введенные пользователем из стандартного потока ввода и разбивать их на предложения.
// Далее программа должна вывести пользователю все предложения, а также количество слов в
// них, отсортировав предложения по количеству слов.




int main()
{
    /////////// TASK 1 ////////////////
    std::string stringToTest = "Hello, my name start on V. Name my friend start on S. And name A.";
    std::string::iterator myItBegin = stringToTest.begin();
    std::string::iterator myItEnd = stringToTest.end();

    printUniqWords(myItBegin, myItEnd);
    ///////////////////////////////////
    
    /////////// TASK 2 ////////////////
    std::map<std::string, int> mySentenses; // ключ - предложение, значение - количество слов в предложении (по нему будет сортировка)
    std::stringstream myStream, myStreamCountWord;
    std::getline(std::cin, stringToTest);
    
    //Пришлось использовать дополнительный поток, так как при использовании cin из цикла не выходит, ждет следцющую строку
    myStream << stringToTest;
    
    while (std::getline(myStream, stringToTest, '.')) {
        int countWord = 0;
        std::string temp;
        myStreamCountWord << stringToTest;
        while (!myStreamCountWord.eof()) {
            myStreamCountWord >> temp;
            countWord++;
        }
        mySentenses.insert(make_pair(stringToTest, countWord));
    }
    
    //вывод на экран получившегося списка 
    for (auto el : mySentenses){
        std::cout << el.first << std::endl;
    }
    ///////////////////////////////////

}

