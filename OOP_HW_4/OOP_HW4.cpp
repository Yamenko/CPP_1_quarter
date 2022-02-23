#include <iostream>
#include <vector>
#include <cassert> // для assert()
#include <algorithm>

/// =========================
/// Для задания #3
/// =========================
enum Mast : char { BUBY, CHERVY, KRESTY, PIKY };
enum CostCard : int { ACE = 1, TWO = 2, TREE = 3, FOUR = 4, FIVE = 5, SIX = 6, SEVEN = 7, EIGHT = 8, NINE = 9, TEN = 10, JACK = 10, QUEEN = 10, KING = 10 };
std::vector<Mast> arrMast = { BUBY, CHERVY, KRESTY, PIKY };
std::vector<CostCard> arrCard = { ACE, TWO, TREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };

class Card
{
private:
	static int countClasses;
	Mast mast = BUBY;
	CostCard cost = ACE;
	bool crap = true;
public:
	Card() {};
	~Card() { };
	void Flip() { crap = !crap; };
	void SetMast(Mast& mast) { this->mast = mast; };
	void SetCostCard(CostCard& cost) { this->cost = cost; };

	CostCard	GetCost() { return this->cost; };
	Mast		GetMast() { return this->mast; };
	bool		GetCrap() { return this->crap; };
};
 

//===========================
//         Task 1
//===========================
//1. Добавить в контейнерный класс, который был написан в этом уроке, методы:
//• для удаления последнего элемента массива(аналог функции pop_back() в векторах)
//• для удаления первого элемента массива(аналог pop_front() в векторах)
//• для сортировки массива
//• для вывода на экран элементов.

class ArrayInt
{
private:
	int m_length;
	int* m_data;

public:
	ArrayInt() : m_length(0), m_data(nullptr) { };

	ArrayInt(int length) : m_length(length) {
		assert(length >= 0);

		if (length > 0)
			m_data = new int[length];
		else
			m_data = nullptr;
	};

	~ArrayInt()
	{
		delete[] m_data;
	};
	int getLength() { return m_length; }
	int& operator[](int index)
	{
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}


	void removeLast() {
		if (m_data != nullptr) {
			m_length-- ;
		}
		else {
			std::cout << "Nothing to remove" << std::endl;
		}
	};

	void removeFirst() {
		if (m_data != nullptr) {
			for (int i = 0; i < m_length; i++)
			{
				m_data[i] = m_data[i + 1];
			}
			m_length--;
		}
		else {
			std::cout << "Nothing to remove" << std::endl;
		}
	};

	void sortArr() {
		std::sort(m_data, m_data + m_length);
	};
	
	void printArr() {
		for (int i = 0; i < m_length; i++)
		{
			std::cout << m_data[i] << " ";
		}
		std::cout << std::endl;
	};

};

//===========================
//         Task 2
//===========================
//2. Дан вектор чисел, требуется выяснить, сколько среди них различных.Постараться использовать максимально быстрый алгоритм.
std::vector<int> chDif = {20, 60, 40, 20, 10, 60, 30, 10, 20};

//===========================
//         Task 3
//===========================
//3. Реализовать класс Hand, который представляет собой коллекцию карт.В классе будет одно поле : вектор указателей карт(удобно использовать вектор, 
//	 т.к.это по сути динамический массив, а тип его элементов должен быть - указатель на объекты класса Card).Также в классе Hand должно быть 3 метода :
//    • метод Add, который добавляет в коллекцию карт новую карту, соответственно он принимает в качестве параметра указатель на новую карту
//    • метод Clear, который очищает руку от карт
//    • метод GetValue, который возвращает сумму очков карт руки(здесь предусмотреть возможность того, что туз может быть равен 11).

class Hand : public Card
{
private:
	std::vector<Card*> cardOnHand;
public:
	void addCard(Card* card) {
		cardOnHand.push_back(card);
	};
	void clearHand() {
		cardOnHand.clear();
	};
	int GetValue() {
		int sumHand = 0;
		for (auto i : cardOnHand) {
			if (i->GetCost() == 1 && (sumHand + i->GetCost() + 10) <= 21) {
				sumHand += i->GetCost() + 10;
			}
			else {
				sumHand += i->GetCost();
			}
		}
		return sumHand;
	};
};


int main()
{
	// Task 1
	std::cout << "Task 1." << std::endl;
	int size = 5;
	ArrayInt myArr (size);
	for (int i = 0; i < size; i++)
	{
		myArr[i] = 100 + 20 * (i % 2 - 1) * i + 30 * i;
	}
	myArr.printArr();
	myArr.sortArr();
	myArr.printArr();

	//Task 2
	int difElemVek = 1; // так как если есть массив то один элемет точно будет.
	std::sort(chDif.begin(), chDif.end());
	for (size_t i = 0; i < chDif.size() - 1; i++) {
		if (chDif[i] != chDif[i + 1]) {
			difElemVek++;
		}
	}
	std::cout <<"Task 2. Vektor."<< std::endl;
	for (int i = 0; i < chDif.size(); i++)
	{
		std::cout << chDif[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Diferent element in vektor: " << difElemVek << std::endl;


	//Task 3
	std::cout << "Task 3." << std::endl;
	Hand hand1;
	Card card1;
	Card card2;
	Card card3;
	card1.SetCostCard(arrCard[11]);
	card2.SetCostCard(arrCard[0]);
	card3.SetCostCard(arrCard[5]);
	hand1.addCard(&card1);
	hand1.addCard(&card2);
	hand1.addCard(&card3);

	std::cout << hand1.GetValue();
}