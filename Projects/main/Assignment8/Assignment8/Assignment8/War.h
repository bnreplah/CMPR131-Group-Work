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
	//Precondition: None
	//Postcondition: will Initialize the object with no values
	Card() {}

	//error codes are all negative or 0
	//Precondition: None
	//Postcondition:will initialize the card with the given error code
	Card(int errorCode) :mECode(errorCode) {}

	// 1 <= pValu >= 14
	//Precondition: None
	//Postcondition:
	Card(size_t pValue) {

	}

	//const
	//Precondition: None
	//Postcondition: will copy the values of one object to the other
	Card(const Card& COPY) {
		this->value = COPY.value;
		this->suite = COPY.suite;
		this->name = COPY.name;
	}
	
	//Precondition: None
	//Postcondition: will copy the values of one object to the other
	Card(Card& COPY) {
		this->value = COPY.value;
		this->suite = COPY.suite;
		this->name = COPY.name;
	}

	//Precondition: None  
	//Postcondition: will assign the values of the value and the suite of the card object
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

	//Precondition: Object must ne initialized
	//Postcondition: Will return a string value related to the type of error or debugging
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

	//Precondition: Object must be initialized
	//Postcondition: will return the value of the mECode
	int getErrorCode() {
		return this->mECode;
	}

	//Precondition: Object must be initialized
	//Postcondition: will output a graphical represetation of the card object with the values
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

	//Precondition: Object must be initialized
	//Postcondition: Will return the value of value
	int getValue() {
		return this->value;
	}
	//const
	//Precondition: Object must be initialized
	//Postcondition: Will return the value of value
	int getValue() const {
		return this->value;
	}

	//Precondition: Object must be initialized
	//Postcondition: Will return the value of suite
	char getSuite() {
		return this->suite;
	}
	//const
	//Precondition: Object must be initialized
	//Postcondition: Will return the value of suite
	char getSuite() const {
		return this->suite;
	}

	//const
	//Precondition: Object must be initialized 
	//Postcondition: will return the value of name
	string getName() const {
		return this->name;
	}

	//Precondition: Both objects must be initialized
	//Postcondition: will set the values of the right to the object to the left of the assignment operator (=)
	void operator = (Card& rhs) {
		this->value = rhs.value;
		this->suite = rhs.suite;
		this->name = rhs.name;
	}

	//const
	//Precondition: Both objects must be initialized
	//Postcondition: will compare the values of the two objects and will return true if so
	bool operator ==(const Card& rhs) const {
		return value == rhs.value;
	}
	
	//Precondition: Both objects must be initialized
	//Postcondition: will compare the values of the two objects and will return true if equeal
	bool operator ==(Card& rhs) {
		return this->value == rhs.value;
	}

	//Precondition: Both objects must be initialized
	//Postcondition: will compare the values of the two objects and will return true if left object is less than right object
	
	bool operator <(const Card& RHS) {
		return this->value < RHS.value;
	}
	//const
	//Precondition: Both objects must be initialized
	//Postcondition: will compare the values of the two objects and will return true if left object is less than right object
	bool operator <(const Card& RHS) const {
		return this->value < RHS.value;
	}

	//Precondition: Both objects must be initialized
	//Postcondition: will compare the values of the two objects and will return true if left object is greater than right object
	bool operator >(const Card& RHS) {
		return this->value > RHS.value;
	}
	//const
	//Precondition: Both objects must be initialized
	//Postcondition: will compare the values of the two objects and will return true if left object is greater than right object
	bool operator >(const Card& RHS) const {
		return this->value > RHS.value;
	}
	//Precondition: Both objects must be initialized
	//Postcondition: will compare the values of the two objects and will return true if left object is less than or equal to right object
	bool operator <=(const Card& RHS) {
		return this->value <= RHS.value;
	}

	//const
	//Precondition: Both objects must be initialized
	//Postcondition: will compare the values of the two objects and will return true if left object is less than or equal to right object
	bool operator <=(const Card& RHS) const {
		return this->value <= RHS.value;
	}

	//const
	//Precondition: Both objects must be initialized
	//Postcondition: will compare the values of the two objects and will return true if left object is greater than or equal to right object
	bool operator >=(const Card& RHS) {
		return this->value >= RHS.value;
	}

	//Precondition: Both objects must be initialized
	//Postcondition: will compare the values of the two objects and will return true if left object is greater than or equal to right object
	bool operator >=(const Card& RHS) const {
		return this->value >= RHS.value;
	}

	//Precondition: Both objects must be initialized
	//Postcondition: will compare the values of the two objects and will return true if left object is less than right object
	bool operator <(Card& RHS) {
		return this->value < RHS.value;
	}

	//Precondition: Both objects must be initialized
	//Postcondition: will compare the values of the two objects and will return true if left object is greater than right object
	bool operator >(Card& RHS) {
		return this->value > RHS.value;
	}

	//Precondition: Both objects must be initialized
	//Postcondition: will compare the values of the two objects and will return true if left object is less than or equal to right object
	bool operator <=(Card& RHS) {
		return this->value <= RHS.value;
	}
		
	//Precondition: Both objects must be initialized
	//Postcondition: will compare the values of the two objects and will return true if left object is greater than or equal to right object
	bool operator >=(Card& RHS) {
		return this->value >= RHS.value;
	}

};


class CardDeck {
private:					//heart,    diamond,   clover,    spade
	const char SUITES[4] = { char(003), char(004), char(005), char(006) };
	deque<Card> deck;
public:
	
	//Precondition: None
	//Postcondition: Will initialize a container with no elements
	CardDeck() {
		deck = deque<Card>();
	}

	//Precondition: None
	//Postcondition: Will initialized a dequeue with cards
	CardDeck(int count) {
		deck = deque<Card>();
		srand(time(0));
		for (int i = 0; i < count; i++) {
			deck.push_back(Card(((i % 13) + 1), SUITES[(i % 4)]));
		}
	}

	//Precondition: None
	//Postcondition: Will copy the values of the object to the other
	CardDeck(const CardDeck& copy) {
		for (deque<Card>::const_iterator i = copy.deck.begin(); i != copy.deck.end(); ++i) {
			placeOnBottom(*i);
		}
	}

	//Precondition: Both objects must be initialized and must have values
	//Postcondition: will set the values of the right to the object to the left of the assignment operator (=)
	CardDeck& operator = (const CardDeck& RHS) {
		for (deque<Card>::const_iterator i = RHS.deck.begin(); i != RHS.deck.end(); ++i) {
			this->placeOnBottom(*i);
		}
		return *this;
	}

	//Precondition: Dequeue must be initialized and must have elements 
	//Postcondition: Will return the card element on the top
	const Card& getTop() {
		if (!deck.empty())
			return deck.front();
		return Card(-1);
	}

	//Precondition: Dequeue must be initialized and must have elements 
	//Postcondition: Will return the card element on the bottom
	const Card& getBottom() {
		if (!deck.empty())
			return deck.back();
		return Card(-1);
	}

	//Precondition: Dequeue must be initialized 
	//Postcondition: Will store the card element on the bottom
	void placeOnBottom(const Card& pasCard) {
		deck.push_back(pasCard);
	}
	//Precondition: Dequeue must be initialized 
	//Postcondition: Will store the card element on the top
	void placeOnBottom(Card& pasCard) {
		deck.push_back(pasCard);
	}

	//Precondition: Object must be initialized and must have elements
	//Postcondition: will return the value of the card in the front and pops it off the deck
	Card passTop() {
		if (!deck.empty()) {
			Card pass = deck.front();
			deck.pop_front();
			return pass;
		}
		return Card(-1);

	}
	//Precondition: Object must be initialized and must have elements
	//Postcondition: will return the value of the card in the bottom and pops it off the deck 
	Card passBottom() {
		if (!deck.empty()) {
			Card pass = deck.back();
			deck.pop_back();
			return pass;
		}
		return Card(-1);
	}
	//Precondition: object must be initialized and must have elements
	//Postcondition: will output the the deck graphically
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

	//Precondition: object must initialized 
	//Postcondition: will return true if deck has no elements
	bool empty() {
		return deck.empty();
	}
	//Precondition: object must initialized 
	//Postcondition: will return the number of elements in the deck
	int size() {
		return this->deck.size();
	}
	//Precondition: object must initialized
	//Postcondition: will clear the deck
	void clear() {
		deck.clear();
	}
};


//////////////////////////
// MAIN DRIVER FUNCTION //
//////////////////////////
void runWar() {

	header("\t1> War the card game..");
			string rules = "\n\tTHE RULES: The game of war is played with 2 decks. Each deck is shuffled, and the players then begin flipping the top card of the deck.\n\t If the value of one card is greater than the player with the greater card gets both of the cards that were in play and those cards are placed\n\t on the bottom of the deck. If both cards are the same, then the next 3 cards are put into a buffer, and the next card after the 3 determine who won.\n\t If either play runs out of cards, the game is over.";
			size_t numberOfCards = size_t();
			CardDeck buffer = CardDeck();
			const int BUFFER_SIZE = 3;
			int mulliganCount = int();
			const int MAXMULLIGAN = 6;
			int secondLastScore = int();
			int lastScore = int();
			std::cout << "\n" << rules;
			//pause();
			

			std::cout << "\n\n\t1> simulation of war (card game) using STL deque\n";

			numberOfCards = inputInteger("\n\tEnter the number of cards for each side: ", true);
			CardDeck computer = CardDeck(numberOfCards);
			CardDeck player = CardDeck(numberOfCards);
			
			
			std::cout << "\n\tCreating the decks....\n";
			
			int shuffleCount = inputInteger("\n\tHow many times would you like to shuffle the computer's deck ?: ", true);
			computer.shuffle(shuffleCount);
			shuffleCount = inputInteger("\n\tHow many times would you like to shuffle the player's deck ?: ", true);
			player.shuffle(shuffleCount);
			
			std::cout << "\n\tShuffling the decks...\n";
			pause();

			while (!computer.empty() && !player.empty()) {
				if (lastScore != 0) {
					
					if (secondLastScore == player.size() || secondLastScore == computer.size())
						++mulliganCount;
					
					if (mulliganCount >= MAXMULLIGAN) {//if stuck in a loop where no one is advancing shuffle
						//std::cout << "\nMulligan\b";
						//pause();
						srand(time(0));
						computer.shuffle();
						player.shuffle();
					}

				}
				if (buffer.empty()) clrScrn();
				if (computer.size() == player.size() && BUFFER_SIZE >= computer.size()) {
					computer.shuffle(2);
					player.shuffle(static_cast<int>(rand() % 10) + 1);
				}//end if
				//std::cout << lastScore << "\t" << secondLastScore << "\t" << mulliganCount <<"\n";

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
				secondLastScore = lastScore;
				lastScore = player.size();
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