
//2. Дан вектор чисел, требуется выяснить, сколько среди них различных.Постараться использовать максимально быстрый алгоритм.
//3. Реализовать класс Hand, который представляет собой коллекцию карт.В классе будет одно поле : вектор указателей карт(удобно использовать вектор, т.к.это по сути динамический массив, а тип его элементов должен быть - указатель на объекты класса Card).Также в классе Hand должно быть 3 метода :
//    • метод Add, который добавляет в коллекцию карт новую карту, соответственно он принимает в качестве параметра указатель на новую карту
//    • метод Clear, который очищает руку от карт
//    • метод GetValue, который возвращает сумму очков карт руки(здесь предусмотреть возможность того, что туз может быть равен 11).
#include <iostream>
#include <vector>

enum Mast : char { BUBY, CHERVY, KRESTY, PIKY };
enum CostCard : int { ACE = 1, TWO = 2, TREE = 3, FOUR = 4, FIVE = 5, SIX = 6, SEVEN = 7, EIGHT = 8, NINE = 9, TEN = 10, JACK = 10, QUEEN = 10, KING = 10 };
std::vector<Mast> arrMast = { BUBY, CHERVY, KRESTY, PIKY};
std::vector<CostCard> arrCard = { ACE, TWO, TREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};

class Card
{
private:
	static int countClasses;
	Mast mast = BUBY;
	CostCard cost = ACE;
	bool crap = true;
public:
	Card(){};
	~Card() { };
	void Flip() { crap = !crap; };
	void SetMast(Mast& mast) { this->mast = mast; };
	void SetCostCard(CostCard& cost) { this->cost = cost; };

	CostCard	GetCost() { return this->cost; };
	Mast		GetMast() { return this->mast; };
	bool		GetCrap() { return this->crap; };
};

int Card::countClasses = 0;
//===========================
//         Task 1
//===========================
//1. Добавить в контейнерный класс, который был написан в этом уроке, методы:
//• для удаления последнего элемента массива(аналог функции pop_back() в векторах)
//• для удаления первого элемента массива(аналог pop_front() в векторах)
//• для сортировки массива
//• для вывода на экран элементов.

class MyContArrCard
{
private:
	int myLeight = 51;
	int firstElement = 0;
	int lastElement;
	Card* myDeck;

public:
	MyContArrCard() : lastElement(myLeight), myDeck(nullptr) {};
	~MyContArrCard() { delete [] myDeck; };

	void makeDeckOfCard() {	
		myDeck = new Card[this->myLeight];
		int nextElement = 0;
		for (int i = 0; i < arrMast.size(); i++)
		{
			for (int j = 0; j < arrCard.size(); j++)
			{
				Card myCard;
				myCard.SetMast(arrMast[i]);
				myCard.SetCostCard(arrCard[j]);

				myDeck[nextElement++] = myCard;
			}
			this->firstElement = nextElement;
		}
	};

	void clearDeck() {
		if (myDeck != nullptr) {
			this->~MyContArrCard();
		}
	};

	void clearLast() {
		if (myDeck != nullptr) {
			lastElement--;
		}
	};

	void clearFirst() {
		if (myDeck != nullptr) {
			for (int i = 0; i < lastElement; i++)
			{
				myDeck[i] = myDeck[i + 1];
			}
			this->clearLast();
		}
	};



	void printElement(int& element) {
		
		std::cout << "Number of card: " << element << ", Cost = " << myDeck[element].GetCost() << ", Mast = "<< myDeck[element].GetMast() << std::endl;
	};

	void printMyContArrCard() {
		if (myDeck != nullptr) {
			std::cout << "Deck of card has:" << std::endl;
			for (int i = 0; i <= lastElement; i++)
			{
				printElement(i);
			}
		}
		else {
			std::cout << "Nothing to print!" << std::endl;
		}
	};

};

int main()
{
	// Task 1
	MyContArrCard deck;
	deck.makeDeckOfCard();
	deck.printMyContArrCard();
	//deck.clearFirst();
	//deck.clearLast();
	//deck.printMyContArrCard();
	//deck.clearDeck();
	//deck.printMyContArrCard();


}