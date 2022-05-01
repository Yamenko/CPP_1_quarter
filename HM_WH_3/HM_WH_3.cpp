#include <iostream>
#include <list>
#include <vector>
#include <iterator>

//==============================================================================
// 1. Написать функцию, добавляющую в конец списка вещественных чисел элемент, 
// значение которого равно среднему арифметическому всех его элементов.
//==============================================================================

void PushAverageElement(std::list<double>& myList) {
    double sumEl = 0;
    for (auto el : myList) {
        sumEl += el;
    }
    myList.push_back(sumEl/myList.size());
}

void PrintList(std::list<double>& myList) {
    for (auto el : myList) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
}

//==============================================================================
// 2. Создать класс, представляющий матрицу.
// Реализовать в нем метод, вычисляющий определитель матрицы.
// Для реализации используйте контейнеры из STL.
//==============================================================================
 
class MyMatrix {
private:
    std::vector<std::vector<int>> matrix;
    int determinant;
    int length;

    // заполнение матрицы
    void FillMatrix() {
        // заполним рандомными числами
        for (size_t i = 0; i < this->length; i++) {
            for (size_t k = 0; k < this->length; k++) {
                matrix[i][k] = rand() % 100;
            }
        }

        // Добавим в конец векторов необходимые числа - (еще раз все столбцы кроме последнего)
        for (int i = 0; i < this->length; i++) {
            for (int k = 0; k < this->length - 1; k++) {
                this->matrix[i][k + length] = this->matrix[i][k];
            }
        }
    }
public:
    // создаем квадратную матрицу (и заполняем), определитель можно расчитать только для квадратной марицы
    MyMatrix(int n) {
        this->length = n;
        while (n) { // пока N будет больше нуля то while будет истина
            matrix.push_back(std::vector<int>(length * 2 - 1)); // добавляем дополнительные пустые ячейки в которые потом заполним дополнительные данные (на 1 меньше исходной матрицы)
            n--;
        }
        FillMatrix();
    }

    void Determinant() {
        //======================
        // Расчет определителя
        //======================
        //----------------------
        // расчет слагаемых
        //----------------------
        int sum = 0, mult = 1;
        for (int i = 0; i < this->length; i++){ // количество слагаемых
            for (int k = 0; k < this->length; k++) { // Расчет индексов и множителей
                //расчет диагоналей с лева на право
                // (первый индекс только перебирает строки)
                // (второй индекс смещается на 1 элемент в право)
                mult *= this->matrix[k][i + k];
            }
            sum += mult;
            mult = 1;
        }

        //----------------------
        // расчет вычитаемых
        //----------------------
        int sub = 0;
        mult = 1;
        for (int i = 0; i < this->length; i++) { // количество вычитаемых
            for (int k = 0; k < this->length; k++) { // Расчет индексов и множителей
                // расчет диагоналей с права на лево
                mult *= this->matrix[k][(this->length-1) + i - k];
            }
            sub += mult;
            mult = 1;
        }
        //----------------------
        // Определитель равен
        //----------------------
        this->determinant = sum - sub;
        (determinant < 0) ? determinant = -determinant : determinant; // если получили отрицательное число тогда меняем знак (определитель всегда берется по модулю)
    }

    int GetDeterminant() {
        return this->determinant;
    }

    void PrintMatrix() {
        for (int i = 0; i < this->length; i++) {
            for (int k = 0; k < this->length; k++) {

               std::cout << this->matrix[k][i] << "\t";
            }
            std::cout << std::endl;
        }
    }

    void PrintMatrixCalculate() {
        for (auto row : matrix) {
            for (auto element : row) {
                std::cout << element << "\t";
            }
            std::cout << std::endl;
        }
    }
};

//==============================================================================
// 3. Реализовать собственный класс итератора, с помощью которого можно будет
// проитерироваться по диапазону целых чисел в цикле for - range - based.
//==============================================================================

class MyClass { //: public std::iterator<std::input_iterator_tag,  int>
private:
    const size_t size;
    std::unique_ptr<int[]> data;


    class MyClassIterator : public std::iterator<std::input_iterator_tag, int>
    {
        friend class MyClass;
    private:
        int* ptrMyClass;
        MyClassIterator(int* ptr) :ptrMyClass(ptr) {};
    public:
        MyClassIterator(const MyClassIterator& it) : ptrMyClass(it.ptrMyClass) {};

        bool operator!=(MyClassIterator const& other) { return ptrMyClass != other.ptrMyClass; };
        bool operator==(MyClassIterator const& other) { return ptrMyClass == other.ptrMyClass; };
        typename MyClassIterator::reference operator*() { return *ptrMyClass; };
        MyClassIterator& operator++() { ++ptrMyClass; return *this; };

    };

public:
    typedef MyClassIterator iterator;
    typedef MyClassIterator const_iterator;

    MyClass(std::initializer_list<int> values) : size(values.size()), data(new int[size]) {
        std::copy(values.begin(), values.end(), data.get());
    };

    MyClass::iterator begin() { return iterator(data.get()); };
    MyClass::iterator end() { return iterator(data.get() + size); };

    //MyClass::const_iterator begin() { return const_iterator(data.get()); };;
    //MyClass::const_iterator end() { return const_iterator(data.get() + size); };

};



//==============================================================================
//==============================================================================
//==============================================================================

int main()
{
    std::cout << "-----------Task 1-------------" << std::endl;
    std::list<double> myList = { 9.54, 10.66, 11.77, 5.2, 7.9 };
    //std::list<double> myList1 = { 10, 20 }; // для тестирования
    std::cout << "Before: ";
    PrintList(myList);
    
    PushAverageElement(myList);
    std::cout << "After: ";
    PrintList(myList);
    std::cout << "------------------------------" << std::endl;
    std::cout << "-----------Task 2-------------" << std::endl;

    MyMatrix testMatrix(3);

    testMatrix.PrintMatrix();
    testMatrix.PrintMatrixCalculate();
    testMatrix.Determinant();
    std::cout << "Determinant = " << testMatrix.GetDeterminant() << std::endl;;


    std::cout << "------------------------------" << std::endl;
    std::cout << "-----------Task 3-------------" << std::endl;

    MyClass myIT = {10, 20, 30, 40};

    for (auto el : myIT) {
        std::cout << el << " ";
    }
    std::cout << std::endl;

    std::cout << "------------------------------" << std::endl;


}