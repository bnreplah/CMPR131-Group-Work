#pragma once
#include <iostream>
#include <list>
#include <vector>
#include "input.h"

//prototypes
/**
*
*/
class intContainer {
private:
	list<vector<int>> list_vector = list<vector<int>>();
public:
	intContainer() {}

	/// Precondition:
	/// Postcondition:
	void addNumber() {

		int num = inputInteger("Add an integer: ");
		if (list_vector.size() == 0) {
			vector<int> freq;
			freq.push_back(num);			//adding the value
			freq.push_back(1);				//adding the frequency
			list_vector.push_back(freq);
		}
		else {
			bool newAdd = false;
			for (list<vector<int>>::iterator itt = list_vector.begin(); itt != list_vector.end(); ++itt) {//cycle through the list
				if (itt->at(0) == num) {
					++(itt->at(1));
					std::cout << "\nNew frequency : " << itt->at(1);
					newAdd = true;
					break;
				}
				for (int i = 0; i < 2; i++) {
					std::cout << "\n\tindex " << i << ": " << itt->at(i);
				}
			}
			if (!newAdd) {
				vector<int> freq;
				freq.push_back(num);			//adding the value
				freq.push_back(1);				//adding the frequency
				list_vector.push_back(freq);
			}
		}

	}

	/// Precondition:
	/// Postcondition:
	void removeNumber() {
		bool found = false;
		int num = inputInteger("Delete number: ");
		for (list<vector<int>>::iterator itt = list_vector.begin(); itt != list_vector.end(); ++itt) {
			if (itt->at(0) == num) {
				--(itt->at(1));
				std::cout << "\nNew frequency : " << itt->at(1);
				if (itt->at(1) <= 0) {
					list_vector.erase(itt);
				}
				found = true;
				break;
			}
			
		}//end for
		if (!found) {
			std::cout << "\nThe value is not contained in the container\n";
		}
	}

	/// Precondition:
	/// Postcondition:
	void displaySet() {
		std::cout << "\n\t\tContainer: ";
		for (list<vector<int>>::iterator itt = list_vector.begin(); itt != list_vector.end(); ++itt) {
			std::cout << itt->at(0) << " ";
			if (itt->at(0) > 1) {
				for (int i = 0; i < itt->at(1); i++) {
					std::cout << itt->at(0) << " ";//prints the value out if frequency greater than 1
				}
			}
		}//end for
		std::cout << "\n";
	}

	/// Precondition:
	/// Postcondition:
	void displayFrequencies() {
		std::cout << "\nFrequencies\n";
		for (list<vector<int>>::iterator itt = list_vector.begin(); itt != list_vector.end(); ++itt) {
			std::cout << "\n" << itt->at(0) << " : " << itt->at(1);

		}//end for
	}

};

/// Precondition:
/// Postcondition:
char appMenuOption(){
	std::cout << "\t\t"; header("\t\t3 > Application using Vectorand /or List container");
	string options[] = { "\n\t\tA> Add an integer",
						 "\n\t\tB> Delete an integer",
						 "\n\t\tC> Display input integers",
						 "\n\t\tD> Display Frequencies of integers",
						"\n\t\t" + string(100 , char(196)) +
						"\n\t\t0> return "
						"\n\t\t" + string(100, char(205))
	};
	for (string option : options)
		cout << option;

	char optionChar = inputChar("\n\t\tOption: ", string("abcd0"));
	clrScrn();

	return optionChar;
}

/// Precondition:
/// Postcondition:
void runApplication() {
	intContainer container = intContainer();
	while(true){
		switch (appMenuOption()) {
		case('0'):return;
		case('A'):container.addNumber(); break;
		case('B'):container.removeNumber(); break;
		case('C'):container.displaySet(); break;
		case('D'):container.displayFrequencies(); break;
		default:
			std::cout << "\nInvalid option";
		}
	
	}
}
