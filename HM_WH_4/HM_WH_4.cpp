#include <iostream>
#include <vector>
#include <random>

//=========================================================================================
// 1. Имеется отсортированный массив целых чисел.Необходимо разработать функцию
// insert_sorted, которая принимает вектор и новое число и вставляет новое число в
// определенную позицию в векторе, чтобы упорядоченность контейнера сохранялась.
// Реализуйте шаблонную функцию insert_sorted, которая сможет аналогично работать с любым
// контейнером, содержащим любой тип значения.
//=========================================================================================

template<typename T>
void insert_sorted(std::vector<T>& vector, T& element) {
    auto pos = std::find_if(vector.begin(), vector.end(), [&element](T oneEl) {return element < oneEl;});
    vector.insert(pos, element);
}

// для печати любых других не стандартных типов должен быть перегружен оператор "<<" !!!
template<typename T>
void PrintVector(std::vector<T>& vector) {
    for (auto it : vector) {
        std::cout << it << " ";
    }
    std::cout << std::endl;
}

//=========================================================================================
// 2. Сгенерируйте вектор a, состоящий из 100 вещественный чисел, представляющий собой
// значения аналогового сигнала.
// На основе этого массива чисел создайте другой вектор целых чисел b, 
// представляющий цифровой сигнал, в котором будут откинуты дробные части чисел.
// Выведите получившиеся массивы чисел.
// Посчитайте ошибку, которой обладает цифровой сигнал по сравнению с аналоговым.
//=========================================================================================

double difVectors(std::vector<double>& v1, std::vector<int>& v2) {
    double sumDif = 0;
    for (int i = 0; i < v1.size(); i++)
    {
        sumDif += v1[i] - v2[i];
    }
    return sumDif;
}



int main()
{
    std::cout << "----------------Task 1--------------------" << std::endl;
    std::vector<int> v1 = { 10, 20, 20, 30, 30, 40, 50 };
    std::cout << "Before: ";
    PrintVector(v1);
    
    int a = 55;
    insert_sorted(v1, a);
    std::cout << "After1: ";
    PrintVector(v1);
   
    int b = 30;
    insert_sorted(v1, b);
    std::cout << "After2: ";
    PrintVector(v1);
    
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "----------------Task 2--------------------" << std::endl;
    std::vector<double> v2;
    std::vector<int> v3;

    std::random_device rd;
    std::mt19937 gen(rd());
    double num = 0.01;
    std::exponential_distribution<double> distribution(num);
    for (int i = 0; i < 100; i++){
        v2.push_back(distribution(gen));
        v3.push_back(v2[i]);
    }
    PrintVector(v2);
    PrintVector(v3);

    double dif = difVectors(v2, v3);
    std::cout << "Diferent beetwen vectors = "<< dif << std::endl;
    std::cout << "------------------------------------------" << std::endl;
}