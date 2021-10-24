/// Ben, Itz
///
///
///
/// 
/// 
///  

#pragma once
#include <iostream>
#include <deque>
#include "input.h"
#include <iomanip>

class Card {
private:
	int value = int();
	char suite = char();
	string name = string();
	int mECode = int(0);
public:
	Card() {}
	//error codes are all negative or 0
	Card(int errorCode) :mECode(errorCode) {}

	// 1 <= pValu >= 14
	Card(size_t pValue) {

	}

	Card(const Card& COPY) {
		this->value = COPY.value;
		this->suite = COPY.suite;
		this->name = COPY.name;
	}
	Card(Card& COPY) {
		this->value = COPY.value;
		this->suite = COPY.suite;
		this->name = COPY.name;
	}



	Card(int pValue, char pSuite) : value(pValue), suite(pSuite) {
		switch (pValue) {
		case(1): name = "Ace";
			break;
		case(2): name = "Two";

			break;
		case(3): name = "Three";

			break;
		case(4): name = "Four";

			break;
		case(5): name = "Five";

			break;
		case(6): name = "Six";

			break;
		case(7): name = "Seven";

			break;
		case(8): name = "Eight";

			break;
		case(9): name = "Nine";

			break;
		case(10): name = "Ten";

			break;
		case(11): name = "Jack";//jack

			break;
		case(12):name = "Queen";//queen

			break;
		case(13):name = "King";//king

			break;
		case(14): name = "Joker";//joker
		default:
			name = to_string(value);
			break;
		}

		if (pSuite == char(003) || pSuite == char(004) || pSuite == char(005) || pSuite == char(006)) {
			switch (pSuite) {
			case(char(003)):name += " of Hearts"; break;	//heart
			case(char(004)):name += " of Diamonds"; break;	//diamond
			case(char(005)):name += " of Clovers"; break;	//clover
			case(char(006)):name += " of Spades"; break;	//spade
			}
		}

	}

	string getError() {
		switch (mECode) {
		case(0):return "No Error";
		case(-1):return "Empty";
		case(-2):return "Bad value";
		case(-3):return "Bad Suite";
		case(-4):return "Debugging";
		default:
			return "Invalid Error code";
			break;
		}
	}

	int getErrorCode() {
		return this->mECode;
	}

	void draw() const {
		std::cout << "\t\t" << char(201) << string(19, char(205)) << char(187) << "\n"
			<< "\t\t" << char(186) << setw(19) << string(value, suite) << char(186) << "\n"
			<< "\t\t" << char(186) << setw(19) << value << char(186) << "\n"
			<< "\t\t" << char(186) << setw(20) << right << char(186) << "\n"
			<< "\t\t" << char(186) << setw(20) << right << char(186) << "\n"
			<< "\t\t" << char(186) << setw(20) << right << char(186) << "\n"
			<< "\t\t" << char(186) << setw(19) << left << this->name << right << char(186) << "\n"
			<< "\t\t" << char(200) << string(19, char(205)) << char(188) << "\n";
	}

	int getValue() {
		return this->value;
	}
	int getValue() const {
		return this->value;
	}

	char getSuite() {
		return this->suite;
	}

	char getSuite() const {
		return this->suite;
	}

	string getName() const {
		return this->name;
	}
	void operator = (Card& rhs) {
		this->value = rhs.value;
		this->suite = rhs.suite;
		this->name = rhs.name;
	}

	bool operator ==(const Card& rhs) const {
		return value == rhs.value;
	}
	bool operator ==(Card& rhs) {
		return this->value == rhs.value;
	}

	bool operator <(const Card& RHS) {
		return this->value < RHS.value;
	}

	bool operator <(const Card& RHS) const {
		return this->value < RHS.value;
	}

	bool operator >(const Card& RHS) {
		return this->value > RHS.value;
	}

	bool operator >(const Card& RHS) const {
		return this->value > RHS.value;
	}

	bool operator <=(const Card& RHS) {
		return this->value <= RHS.value;
	}

	bool operator <=(const Card& RHS) const {
		return this->value <= RHS.value;
	}

	bool operator >=(const Card& RHS) {
		return this->value >= RHS.value;
	}

	bool operator >=(const Card& RHS) const {
		return this->value >= RHS.value;
	}


	bool operator <(Card& RHS) {
		return this->value < RHS.value;
	}

	bool operator >(Card& RHS) {
		return this->value > RHS.value;
	}

	bool operator <=(Card& RHS) {
		return this->value <= RHS.value;
	}

	bool operator >=(Card& RHS) {
		return this->value >= RHS.value;
	}

};


class CardDeck {
private:					//heart,    diamond,   clover,    spade
	const char SUITES[4] = { char(003), char(004), char(005), char(006) };
	deque<Card> deck;
public:
	CardDeck() {
		deck = deque<Card>();
	}

	CardDeck(int count) {
		deck = deque<Card>();
		srand(time(0));
		for (int i = 0; i < count; i++) {
			deck.push_back(Card(((i % 13) + 1), SUITES[(i % 4)]));
		}


	}

	CardDeck(const CardDeck& copy) {
		for (deque<Card>::const_iterator i = copy.deck.begin(); i != copy.deck.end(); ++i) {
			placeOnBottom(*i);
		}
	}

	CardDeck& operator = (const CardDeck& RHS) {
		for (deque<Card>::const_iterator i = RHS.deck.begin(); i != RHS.deck.end(); ++i) {
			this->placeOnBottom(*i);
		}
		return *this;
	}



	const Card& getTop() {
		if (!deck.empty())
			return deck.front();
		return Card(-1);
	}

	const Card& getBottom() {
		if (!deck.empty())
			return deck.back();
		return Card(-1);
	}

	void placeOnBottom(const Card& pasCard) {
		deck.push_back(pasCard);
	}
	void placeOnBottom(Card& pasCard) {
		deck.push_back(pasCard);
	}

	Card passTop() {
		if (!deck.empty()) {
			Card pass = deck.front();
			deck.pop_front();
			return pass;
		}
		return Card(-1);

	}

	Card passBottom() {
		if (!deck.empty()) {
			Card pass = deck.back();
			deck.pop_back();
			return pass;
		}
		return Card(-1);
	}

	void showDeck() {

		if (deck.empty())
			return;
		for (int i = 0; i < deck.size(); i++) {
			deck[i].draw();
		}
	}


	/// Precondition: the deck must not be empty.
	/// Postcondition: shuffles the deck randomly, seeded by srand() in the constructor
	void shuffle() {

		for (int i = 0; i < deck.size(); i++) {
			size_t pos = static_cast<size_t>(rand() % deck.size());
			Card temp = deck[i];
			deck[i] = deck[pos];
			deck[pos] = temp;
		}//end for

	}//end shuffle

	 /// Precondition: the deck must not be empty.
	/// Postcondition: shuffles the deck randomly, seeded by srand() in the constructor
	void shuffle(int count) {
		for (int j = 0; j < count; j++)
			for (int i = 0; i < deck.size(); i++) {
				size_t pos = static_cast<size_t>(rand() % deck.size());
				Card temp = deck[i];
				deck[i] = deck[pos];
				deck[pos] = temp;
			}//end for

	}//end shuffle

	bool empty() {
		return deck.empty();
	}

	int size() {
		return this->deck.size();
	}

	void clear() {
		deck.clear();
	}
};





void runWar() {

	header("\t1> War the card game..");
			string rules = "\n\tTHE RULES: The game of war is played with 2 decks. Each deck is shuffled, and the players then begin flipping the top card of the deck.\n\t If the value of one card is greater than the player with the greater card gets both of the cards that were in play and those cards are placed\n\t on the bottom of the deck. If both cards are the same, then the next 3 cards are put into a buffer, and the next card after the 3 determine who won.\n\t If either play runs out of cards, the game is over.";
			std::cout << "\n" << rules;
			pause();
			size_t numberOfCards = size_t();

			std::cout << "\n\n\t1> simulation of war (card game) using STL deque\n";

			numberOfCards = inputInteger("\n\tEnter the number of cards for each side: ", true);
			CardDeck computer = CardDeck(numberOfCards);
			CardDeck player = CardDeck(numberOfCards);
			CardDeck buffer = CardDeck();
			const int BUFFER_SIZE = 3;
			std::cout << "\n\tCreating the decks....\n";
			computer.shuffle();
			player.shuffle(2);
			std::cout << "\n\tShuffling the decks...\n";
			pause();
			while (!computer.empty() && !player.empty()) {
				if (buffer.empty()) clrScrn();
				if (computer.size() == player.size() && BUFFER_SIZE >= computer.size()) {
					computer.shuffle(2);
					player.shuffle(static_cast<int>(rand() % 10) + 1);
				}//end if

				std::cout << setw(50) << right << "\n\tComputer Score:" << "\tPlayer Score:\n"
					<< "\t\t" << computer.size() << "\t\t" << player.size();
				std::cout << "\n\tThe computer plays a " << computer.getTop().getName() << "\n";
				computer.getTop().draw();
				std::cout << "\n\tThe next card for the player is a " << player.getTop().getName() << "\n";
				player.getTop().draw();
				std::cout << "\n\t\t" << setw(30) << computer.getTop().getName() << " :    : " << player.getTop().getName();


				if (computer.empty() && player.empty())
					break;

				if (computer.getTop() < player.getTop()) {//player wins

					std::cout << "\n\t\t" << setw(30) << "" << "   <  :";
					buffer.placeOnBottom(computer.passTop());
					buffer.placeOnBottom(player.passTop());
					std::cout << "\n\n\tThe player wins...\n";

					player = buffer;//adds buffer to bottom of players deck
					buffer.clear();
				}
				else if (computer.getTop() > player.getTop()) {//computer wins
					std::cout << "\n\t\t" << setw(30) << "" << " :  > ";
					buffer.placeOnBottom(computer.passTop());
					buffer.placeOnBottom(player.passTop());
					std::cout << "\n\n\tThe computer wins...\n";
					computer = buffer;
					buffer.clear();
				}
				else if (computer.getTop() == player.getTop()) {//draw

					std::cout << "\n\t\t" << setw(30) << "" << " : == : ";
					std::cout << "\n\tDraw, each draw cards and put it into the buffer...\n";

					if (!computer.empty() && !player.empty()) {
						buffer.placeOnBottom(computer.passTop());
						buffer.placeOnBottom(player.passTop());
						if (computer.empty() || player.empty()) {
							if (computer.empty())
								player = buffer;
							else if (player.empty())
								computer = buffer;
							continue;
						}//end if
						for (int i = 0; i < BUFFER_SIZE && !computer.empty() && !player.empty(); i++) {//
							buffer.placeOnBottom(computer.passTop());
							buffer.placeOnBottom(player.passTop());
							if (computer.empty() || player.empty()) {
								if (computer.empty())
									player = buffer;
								else if (player.empty())
									computer = buffer;
								break;
							}//end if
						}//end for
					}//end else
					std::cout << "\n\tCards in the buffer, continue to flip the next card... \n";
					//pause();
					//if (computer.getTop() < player.getTop()) {//player wins
					//	player = buffer;//place buffer at the bottom of the player deck
					//}
					//else if (computer.getTop() > player.getTop()) {//computer wins
					//	computer = buffer; //place buffer at the bottom of the computer deck
					//}
					//delete buffer;

				}
				pause();

			}//end while
			if (!computer.empty() && player.empty()) {
				std::cout << "\n\tThe computer won!!! " << computer.size() << " Cards\n";

			}//end if
			else if (!player.empty() && computer.empty()) {
				std::cout << "\n\tYou won!!! " << player.size() << " Cards";
			}//end if
			else {
				std::cout << "\n\tDraw... Both ran out of cards";
			}//end if
		
				
			pause();
}