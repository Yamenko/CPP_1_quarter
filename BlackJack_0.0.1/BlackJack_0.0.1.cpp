#include <iostream>
#include <vector>

class Card
{
private:
	enum Mast : char { CHERVY = 3, BUBY = 4, KRESTY = 5, PIKY = 6 };
	enum CostCard : int { ACE = 1, TWO = 2, TREE = 3, FOUR = 4, FIVE = 5, SIX = 6, SEVEN = 7, EIGHT = 8, NINE = 9, TEN = 10, JACK = 10, QUEEN = 10, KING = 10 };
	Mast mast = BUBY;
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
	virtual bool const IsHitting();
	bool IsBoosted() { GetValue() > 21 ? true : false; };
	void Bust() { std::cout << this->name << "Has a bust!" << std::endl; };
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
//• virtual bool IsHitting() const - метод указывает, нужна ли дилеру еще одна карта.Если у дилера не больше 16 очков, то он берет еще одну карту.
//• void FlipFirstCard() - метод переворачивает первую карту дилера.
class House : public GenericPlayer {
public:
	bool const IsHitting() override {
		if (GetValue() <= 16) { return true; }
	};
	void FlipFirstCard() {	
		if (GetCrap()) { Flip(); };	
	};
};

int main()
{

}
