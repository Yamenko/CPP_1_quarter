#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <random>

enum Mast : char { CHERVY = 3, BUBY = 4, KRESTY = 5, PIKY = 6 };
enum CostCard : char { ACE = 1, TWO = 2, TREE = 3, FOUR = 4, FIVE = 5, SIX = 6, SEVEN = 7, EIGHT = 8, NINE = 9, TEN = 10, JACK = 10, QUEEN = 10, KING = 10 };
std::vector<Mast> arrMast = { CHERVY, BUBY,  KRESTY, PIKY };
std::vector<CostCard> arrCard = { ACE, TWO, TREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };

class Card
{
private:
	Mast mast = CHERVY;
	CostCard cost = ACE;
	bool crap = false;
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

class Hand : public Card
{
private:
	std::vector<Card*> cardOnHand;
public:
	void addCard(Card* card) { cardOnHand.push_back(card); };
	void clearHand() {	cardOnHand.clear();	};
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

class GenericPlayer : public Hand {
private:
	std::string name = "";
public:
	virtual bool const IsHitting() = 0;
	bool IsBoosted() { GetValue() > 21 ? true : false; };
	void Bust() { std::cout << this->name << "Has a bust!" << std::endl; };
	void setName(std::string& name) { this->name = name; };
	std::string  getName() const { return name; };
	
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
		} while (true);
	};
	void Win() const { std::cout << getName() << " is Winer!"; };
	void Lose() const { std::cout << getName() << " is Looser!"; };
	void Push() const { std::cout << "Have no winer!"; };
};

class House : public GenericPlayer {
public:
	bool const IsHitting() override {
		if (GetValue() <= 16) { return true; }
	};
	void FlipFirstCard() {	
		if (GetCrap()) { Flip(); };	
	};
};

//3. Создать класс Deck, который наследует от класса Hand и представляет собой колоду карт.Класс Deck имеет 4 метода:
//• vold Populate() - Создает стандартную колоду из 52 карт, вызывается из конструктора.
//• void Shuffle() - Метод, который тасует карты, можно использовать функцию из алгоритмов STL random_shuffle
//• vold Deal(Hand& aHand) - метод, который раздает в руку одну карту
//• void AddltionalCards(GenericPlayer& aGenerlcPlayer) - раздает игроку дополнительные карты до тех пор, пока он может и хочет их получать
//
//Обратите внимание на применение полиморфизма.В каких методах применяется этот принцип ООП ?

class Deck : public Hand {
private:
	int myLeight = 51;
	int firstElement = 0;
	int lastElement;
	std::vector<Card*> myDeck;
public:

	Deck() { Populate(); };
	void Populate() {
		//myDeck = new Card[this->myLeight];
		int nextElement = 0;
		for (int i = 0; i < arrMast.size(); i++)
		{
			for (int j = 0; j < arrCard.size(); j++)
			{
				Card myCard;
				myCard.SetMast(arrMast[i]);
				myCard.SetCostCard(arrCard[j]);

				myDeck.push_back(&myCard);
				//myDeck[nextElement++] = myCard;
			}
			this->firstElement = nextElement;
		}
	};

	void Shuffle(){
		auto rnd = std::default_random_engine{};
		std::shuffle(std::begin(myDeck), std::end(myDeck), rnd);
	};

	void Deal(Hand& aHand) {
		aHand.addCard(*myDeck.end());
		myDeck.pop_back();
	};

	void AddItionalCards(GenericPlayer& aGenericPlayer) {
		if (aGenericPlayer.IsHitting()){
			Deal(aGenericPlayer);
		}
	};
		
};
 

//4. Реализовать класс Game, который представляет собой основной процесс игры.У этого класса будет 3 поля :
//	• колода карт
//	• рука дилера
//	• вектор игроков.
//	Конструктор класса принимает в качестве параметра вектор имен игроков и создает объекты самих игроков.
// В конструкторе создается колода карт и затем перемешивается.
//	Также класс имеет один метод play().В этом методе раздаются каждому игроку по две стартовые карты, а первая карта дилера прячется.
//Далее выводится на экран информация о картах каждого игра, в т.ч.и для дилера.
//Затем раздаются игрокам дополнительные карты.
// Потом показывается первая карта дилера и дилер набирает карты, если ему надо.
//После этого выводится сообщение, кто победил, а кто проиграл.В конце руки всех игроков очищаются.

class Game {
private:
	std::vector<Player> player;
	Deck deck;
	House house;
public:
	Game() {};
	Game(std::vector<std::string> plr) {
		for (auto element : plr) {
			Player p;
			p.setName(element);
			player.push_back(p);
		}
		deck.Shuffle();
	};

	void play() {
		for (size_t i = 0; i < 2; i++)
		{
			for (auto element : player) {
				deck.Deal(element);
			}
			deck.Deal(house);
			if (i == 0) { house.Flip(); }
		}
		

	
	};


};




//	5. 5. Написать функцию main() к игре Блекджек.
//В этой функции вводятся имена игроков.
//Создается объект класса Game и запускается игровой процесс.
//Предусмотреть возможность повторной игры.

int main()
{

}
