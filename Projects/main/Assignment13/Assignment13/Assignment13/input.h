// Input.h file
// Originally Authored by Professor Q
// Maintained by Ben Halpern
// 
// Version 2.13
// Last Updated: November 28, 2021 Itz

#pragma once	

#include <iostream>
#include <algorithm>
#include <string>
#include <conio.h>		//needed for _getch()
#include <type_traits>
#include <ctime>
#include <vector>
#include <fstream>
using namespace std;

char getOs()
{
#ifdef _WIN32
	return 'W';
#elif _WIN64
	return 'W';
#elif __APPLE__ || __MACH__
	return 'M';
#elif __linux__
	return 'L';
#else
	return 'O';
#endif
}

/// Precondition: N/A
/// Postcondition: clears the screen
///     clears the screen alternative of a system call. 
void clrScrn()
{
	switch (getOs())
	{
	case 'W':
	{
		system("cls");
		break;
	}
	case 'M':
	{
		system("clear");
		break;
	}
	case 'L':
	{
		system("clear");
		break;
	}
	case 'O':
	{
		cout << "\033[2J\033[1;1H";
		cout << string(175, '\n');
		break;
	}
	default:
		cout << "\033[2J\033[1;1H";
		cout << string(175, '\n');
		break;
	}
}//end clearScreen()


void sleep(size_t seconds) {
	time_t cur = time(0);
	cur += seconds;
	while ((cur - time(0)) != 0);
}

void sleep_ms(size_t ms) {
	time_t cur = (time(0) * 1000);
	cur += ms;
	while ((cur - (time(0) * 1000)) > 0);// { std::cout << (cur - (time(0) * 100)); }
	
}



// Precondition: outText (string) is a string that will be outputted/ appended to a file called ScoreSheet holding the ScoreSheet of the round
// postcondition: if file does not exist creates file, if exists appends to the file the outText
void outToFile(string fileName ,string outText) {
	fstream file = fstream();
	file.open(fileName, ios::app | ios::out);
	file << outText;
	file.close();
}


/// Precondition: N/A
/// Postcondition: prints "Please press any key to continue" and waits for user input of any value
///     pause function
void pause()
{
	cin.clear();
	char key = char();
	cout << "\n\tPlease press any key to continue ... ";
	//cin.ignore(99,'\n');
	key = _getch();
	//cin.ignore(99, '\n');
}

// Precondition: String of the title to be displayed passed to the function
// Postcondition: Displays the title with a title bar
void header(string title)
{
	cout << "\n\t" << title;
	cout << "\n\t" << string(100, char(205));
}//end header

// PreCondition: spaces (boolean true or false)
// PostCondition: returns a string including space character(s) or without space character 
string inputString(string prompt, bool spaces)
{
	string input = "";

	cout << prompt;
	if (spaces)
		getline(cin, input);
	else
	{
		cin >> input;
		cin.clear();
		cin.ignore(999, '\n');
	}
	cin.clear();
	return input;
}

// converts a string to a cstring pointer ( not a constant and with the null preminator
char* toC_Str(string str)
{
	char* temp = new char[(str.length() + 1)];                       // need to add null terminator
	//cout << boolalpha;                                             // prints out boolean values as text ( true or false )
	//cout << (temp == 0) << endl;                                   // debugging checks if pointer is to null

	for (int i = 0; i < str.length(); i++)
	{
		*(temp + i) = str.at(i);
	}//end for
	*(temp + str.length()) = '\0';										//add null terminator at the end
	return temp;
}//end toC_str()

/// Precondition: Takes a c-string ( which are passed by reference ) and a prompt and size of the c_string
/// Postcondition: The user is prompted to enter a c-string and the c-string is now populated
void inputC_string(char c_string[], string prompt, int size)
{
	//char* temp = new char[size];
	cout << prompt;
	cin.getline(c_string, size);
	cin.clear();
	//cin.ignore(99,'\n');
	//return temp;
}//end inputC_string

/// Precondition: Takes a string prompt, a c-string with space for a null terminator (11), and a delimeter to seperate the date
/// Postcondition: input validation for a date, a string is returned containing the date. A c-string is also populated with the date
///		Also validates for leap years and eveyr month for its accurate amount of days
string inputDate(string prompt, char c_string[11], const char DELIM)
{
	string strInput = string();
	string month = string();
	string day = string();
	string year = string();
	int numMonth = int();
	int numDay = int();
	int numYear = int();
	bool error = false;

	while (month.length() != 2 && day.length() != 2 && year.length() != 4 || error)
	{// loops as long as the inputed date is too long or an error was triggered
		error = false;

		do
		{
			do
			{
				if (!strInput.empty())
					cout << "\n\tMake sure the inputted string is in the format MM" << DELIM << "DD" << DELIM << "YYYY with the \'" << DELIM << "\' as a delimeter";
				cout << prompt;
				getline(cin, strInput);
			} while (strInput.find(DELIM, 0) > 10);
			error = false;
			//prompts, validates, and gets the date from the user

			month = strInput.substr(0, 2);
			numMonth = atoi(month.c_str());  //converts the month to an int (first two characters) (atoi takes an argument of a const char* )
			day = strInput.substr(strInput.find(DELIM, 0) + 1, 2);
			numDay = atoi(day.c_str());      //converts the day to an int (next two characters after the '/')
			year = strInput.substr(strInput.find(DELIM, (strInput.find(DELIM, 0) + 1)) + 1);
			numYear = atoi(year.c_str());    //converts the year to an int (last 4 characters)

			// valid month-date range validation
			// checking for leap years and that the day is a valid value within the month
			if (numMonth <= 7 && (numMonth % 2) == 0)
			{
				if (!(numDay <= 30))
				{
					cout << "\n\tERROR: The inputted day is past the amount of days in the inputted month";
					error = true;
				}//end if

				if (numMonth == 02)
				{
					if ((numYear % 4 == 0) && (numYear % 100 != 0) || (numYear % 400 == 0))
					{
						if (!(numDay <= 29))
						{
							cout << "\n\tERROR: The inputted day is past the amount of days in the inputted month. The year inputted is a leap year.";
							error = true;
						}//end if
					}//end if
					else if (!(numDay <= 28))
					{
						cout << "\n\tERROR: The inputted day is past the amount of days in the inputted month. February has 28 days.";
						error = true;
					}//end if
				}//end if
			}//end
			else if (numMonth > 7 && (numMonth % 2) == 1)
			{
				if (!(numDay <= 30))
				{
					cout << "\n\tERROR: The inputted day is past the amount of days in the inputted month";
					error = true;
				}//end if
			}//end else if

			cout << "\n";                               //blank line for visibility

		} while (error);

		//getline(cin, month, DELIM);
		//getline(cin, day, DELIM);
		//getline(cin, year, DELIM);

		//date validation
		//checks to make sure that the inputted values are of valid length and within valid bounds (of all possible days in a month, not specific months )
		if (month.length() != 2 || (atoi(month.c_str()) > 12 || atoi(month.c_str()) < 01))
		{
			cout << "\n\tERROR: Invalid Input. The month has to be an integer of the length 2 between 01...12";
			error = true;
		}//end if
		else if (day.length() != 2 || (atoi(day.c_str()) > 31 || atoi(day.c_str()) < 1))
		{
			cout << "\n\tERROR: Invalid Input. The day has to be an integer of the length 2 between 01...31";
			error = true;
		}//end else if
		else if (year.length() != 4 || (atoi(year.c_str()) > 9999 || atoi(year.c_str()) < 0001))
		{
			cout << "\n\tERROR: Invalid Input. The year has to be an integer of the length 2 between 01...12";
			error = true;
		}//end else if
		else if (atoi(month.c_str()) == 0 || atoi(day.c_str()) == 0 || atoi(year.c_str()) == 0)
		{//if a non integer was inputted
			cout << "\n\tERROR: Invalid Input. The date must be in the folloing format: MM/DD/YYYY";
			error = true;
		}//end else if
	}//end while
	strncpy_s(c_string, 11, toC_Str(month.append(1, DELIM) + day.append(1, DELIM) + year), 11);	  // 11 to include the terminating character
	return month.append(1, DELIM) + day.append(1, DELIM) + year;
}//end getDate()

/// Precondition: Takes a string prompt and a delimeter to seperate the date
/// Postcondition: input validation for a date, a string is returned containing the date.
///		Also validates for leap years and eveyr month for its accurate amount of days
/// [overloaded]
string inputDate(string prompt, const char DELIM)
{
	string strInput = string();
	string month = string();
	string day = string();
	string year = string();
	int numMonth = int();
	int numDay = int();
	int numYear = int();
	bool error = false;

	while (month.length() != 2 && day.length() != 2 && year.length() != 4 || error)
	{//loops as long as the inputed date is too long or an error was triggered
		error = false;

		do
		{
			do
			{
				if (!strInput.empty())
					cout << "\n\tMake sure the inputted string is in the format MM" << DELIM << "DD" << DELIM << "YYYY with the \'" << DELIM << "\' as a delimeter";
				cout << prompt;
				getline(cin, strInput);
			} while (strInput.find(DELIM, 0) > 10);
			error = false;
			//prompts, validates, and gets the date from the user

			month = strInput.substr(0, 2);
			numMonth = atoi(month.c_str());   //converts the month to an int (first two characters) (atoi takes an argument of a const char* )
			day = strInput.substr(strInput.find(DELIM, 0) + 1, 2);
			numDay = atoi(day.c_str());       //converts the day to an int (next two characters after the '/')
			year = strInput.substr(strInput.find(DELIM, (strInput.find(DELIM, 0) + 1)) + 1);
			numYear = atoi(year.c_str());     //converts the year to an int (last 4 characters)

			//valid month-date range validation
			//checking for leap years and that the day is a valid value within the month
			if (numMonth <= 7 && (numMonth % 2) == 0)
			{
				if (!(numDay <= 30))
				{
					cout << "\n\tERROR: The inputted day is past the amount of days in the inputted month";
					error = true;
				}//end if

				if (numMonth == 02)
				{
					if ((numYear % 4 == 0) && (numYear % 100 != 0) || (numYear % 400 == 0))
					{
						if (!(numDay <= 29))
						{
							cout << "\n\tERROR: The inputted day is past the amount of days in the inputted month. The year inputted is a leap year.";
							error = true;
						}//end if
					}//end if
					else if (!(numDay <= 28))
					{
						cout << "\n\tERROR: The inputted day is past the amount of days in the inputted month. February has 28 days.";
						error = true;
					}//end if
				}//end if
			}//end
			else if (numMonth > 7 && (numMonth % 2) == 1)
			{
				if (!(numDay <= 30))
				{
					cout << "\n\tERROR: The inputted day is past the amount of days in the inputted month";
					error = true;
				}//end if
			}//end else if

			cout << "\n";                                  //blank line for visibility

		} while (error);

		//getline(cin, month, DELIM);
		//getline(cin, day, DELIM);
		//getline(cin, year, DELIM);

		//date validation
		//checks to make sure that the inputted values are of valid length and within valid bounds (of all possible days in a month, not specific months )
		if (month.length() != 2 || (atoi(month.c_str()) > 12 || atoi(month.c_str()) < 01))
		{
			cout << "\n\tERROR: Invalid Input. The month has to be an integer of the length 2 between 01...12";
			error = true;
		}//end if
		else if (day.length() != 2 || (atoi(day.c_str()) > 31 || atoi(day.c_str()) < 1))
		{
			cout << "\n\tERROR: Invalid Input. The day has to be an integer of the length 2 between 01...31";
			error = true;
		}//end else if
		else if (year.length() != 4 || (atoi(year.c_str()) > 9999 || atoi(year.c_str()) < 0001))
		{
			cout << "\n\tERROR: Invalid Input. The year has to be an integer of the length 2 between 01...12";
			error = true;
		}//end else if
		else if (atoi(month.c_str()) == 0 || atoi(day.c_str()) == 0 || atoi(year.c_str()) == 0)
		{//if a non integer was inputted
			cout << "\n\tERROR: Invalid Input. The date must be in the folloing format: MM/DD/YYYY";
			error = true;
		}//end else if

	}//end while
	return month.append(1, DELIM) + day.append(1, DELIM) + year;
}//end getDate()

// PreCondition: valid yes (char) or no (char)
// PostCondition: returns an uppercase  yes (char) or no (char) 
char inputChar(string prompt, char yes, char no)
{
	char input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "\tERROR: Invalid input. Must be a character type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (tolower(input) != tolower(yes) && tolower(input) != tolower(no))
			cout << "\tERROR: Invalid input. Must be a '" << static_cast<char>(toupper(yes)) << "' or '" << static_cast<char>(toupper(no)) << "' character.\n";
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return toupper(input);
}


// PreCondition: valid alpah numerical option
// PostCondition: returns an uppercase  option selected 
char inputChar(string prompt, string option)
{
	bool found = bool();
	char input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "\tERROR: Invalid input. Must be a character type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else {
			found = false;
			if (input == '0')
				break;
			for (int i = 0; i < option.length(); i++) {
				if ((toupper(option.at(i)) == toupper(input))) {
					found = true;
					break;
				}//end for

			}//end for
			if (found) //if breaks out of the loop 
			{
				break;
			}
			else //error condition
			{
				cout << "\tERROR: Invalid input. Must be one of the following '" << option << "' character.\n";
				cin.clear();
				cin.ignore(999, '\n');
			}//end else

		}//end else

	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return toupper(input);
}

// PreCondition: alphaOrDigit (boolean true or false)
// PostCondition: returns an alphabet or a digit character
char inputChar(string prompt, bool alphaOrDigit)
{
	char input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "\tERROR: Invalid input. Must be a character type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (alphaOrDigit && !isalpha(input))
			cout << "\tERROR: Invalid input. Must be an alphabet character.\n";
		else if (!alphaOrDigit && !isdigit(input))
			cout << "\tERROR: Invalid input. Must be a digit character.\n";
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}

// PreCondition: NA
// PostCondition: returns valid character
char inputChar(string prompt)
{
	char input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "\tERROR: Invalid input. Must be a character type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return toupper(input);
}

// PreCondition: NA
// PostCondition: returns any integer value
int inputInteger(string prompt)
{
	int input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "\tERROR: Invalid input. Must be an integer type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}

// PreCondition: posNeg (boolean true or false)
// PostCondition: returns a positive integer value (posNeg = true) or a negative integer value (poseNeg = false)
int inputInteger(string prompt, bool posNeg)
{
	int input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "\tERROR: Invalid input. Must be an integer type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (posNeg && input <= 0)
			cout << "\tERROR: Invalid input. Must be a positive number.\n";
		else if (!posNeg && input >= 0)
			cout << "\tERROR: Invalid input. Must be a negative number.\n";
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}

// PreCondition: start (integer) and greater (boolean true or false)
// PostCondition: returns an integer value greater than start or lesser than start
int inputInteger(string prompt, int start, bool greater)
{
	int input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "\tERROR: Invalid input. Must be an integer type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (greater && input <= start)
			cout << "\tERROR: Invalid input. Must be a greater than or equal to " << start << ".\n";
		else if (!greater && input >= start)
			cout << "\tERROR: Invalid input. Must be a lesser than or equal to " << start << ".\n";
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}

// PreCondition: startRange (integer) and endRange (integer)
// PostCondition: returns an integer value within range (startRannge and endRange)
int inputInteger(string prompt, int startRange, int endRange)
{
	int input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "\tERROR: Invalid input. Must be an integer type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (!(input >= min(startRange, endRange) && input <= max(startRange, endRange)))
			cout << "\tERROR: Invalid input. Must be from " << startRange << ".." << endRange << ".\n";
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}

// PreCondition: NA
// PostCondition: returns any double value
double inputDouble(string prompt)
{
	double input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "\tERROR: Invalid input. Must be a double type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}

// PreCondition: posNeg (boolean true or false)
// PostCondition: returns a positive double value (posNeg = true) or a negative double value (poseNeg = false)
double inputDouble(string prompt, bool posNeg)
{
	double input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "\tERROR: Invalid input. Must be a double type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (posNeg && input <= 0.0)
			cout << "\tERROR: Invalid input. Must be a positive number.\n";
		else if (!posNeg && input >= 0.0)
			cout << "\tERROR: Invalid input. Must be a negative number.\n";
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}

// PreCondition: start(integer) and greater(boolean true or false)
// PostCondition: returns an integer value greater than start or lesser than start
double inputDouble(string prompt, double start, bool posNeg)
{
	double input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "\tERROR: Invalid input. Must be a double type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (posNeg && input <= start)
			cout << "\tERROR: Invalid input. Must be greater than or equal to " << start << ".\n";
		else if (!posNeg && input >= start)
			cout << "\tERROR: Invalid input. Must be lesser than or equal to " << start << ".\n";
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}

// PreCondition: startRange (integer) and endRange (integer)
// PostCondition: returns an integer value within range (startRannge and endRange)
double inputDouble(string prompt, double startRange, double endRange)
{
	double input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "\tERROR: Invalid input. Must be a double type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (!(input >= min(startRange, endRange) && input <= max(startRange, endRange)))
			cout << "\tERROR: Invalid input. Must be from " << startRange << "..." << endRange << ".\n";
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}


/// Precondition: fileName is the name of the file to append or create, outText is a string to be written out to the file
/// Postcondition: writes the string to the file name specified by fileName
void outFile(string fileName, string outText) {
	fstream file = fstream();
	file.open(fileName, ios::app | ios::out);

	file << outText;

	file.close();
}//end outFile

//
///// Precondition: fileName is the name of the file to append or create, outText is a vector with a type T which must have an overloaded output operator to a file
///// Postcondition: writes the contents of outText to the file
//template <class T>
//void outFile(string fileName, vector<T> outText) {
//	fstream file = fstream();
//	file.open(fileName, ios::app | ios::out);
//	for (int i = 0; i < outText.size() && file.good(); i++) {
//		file << outText[i];
//	}//end for
//	file.close();
//}


///// Precondition: fileName is the name of the file to append or create, outText is a string to be written out to the file
///// Postcondition: writes the string to the file name specified by fileName
//void outFile(string fileName, string outText) {
//	fstream file = fstream();
//	file.open(fileName, ios::app | ios::out);
//	
//	file << outText;
//	
//	file.close();
//}//end outFile

/// Precondition: fileName is the name of the file to append or create, outText is a vector with a type T which must have an overloaded output operator to a file
/// Postcondition: writes the contents of outText to the file
template <class T>
void outFile(string fileName, vector<T> outText) {
	fstream file = fstream();
	file.open(fileName, ios::out);
	for (int i = 0; i < outText.size() && file.good(); i++) {
		file << outText[i]<<endl;
	}//end for
	file.close();
}

	
template <class T>
class Searches {

public:

	Searches() {

	}
	
	//precondition: SortedArray must be initialized
	//postcondition: Recursive serial search
	bool linearSearch(vector<T> sorted, T searchValue, typename vector<T>::iterator begin, typename vector<T>::iterator end) {
		//linear search
	
		
		if (begin == end) { //if at the last index and not found return false

			return false;
		}

		if (*begin == searchValue) { // once found returns true
			return true;
		}

		else
			return linearSearch(sorted, searchValue, ++begin, end); //calls recursively
	}

//precondition: SortedArray must be initialized
//postcondition: will recursively binary search for the ID given
bool binarySearch(T* sorted,T value, size_t first, size_t pSize, size_t& pos, int depth, int opCount = 0) {
	bool found = false;
	size_t middle = size_t();
	if (depth < 0 || pSize == 0)
		return false;
	else {
		middle = first + pSize / 2;
		if (value == sorted[middle]) {
			pos = middle;
			return true;
		}
		else if (value < sorted[middle])
		{
			return binarySearch(sorted,value, first, pSize / 2, pos, depth / 2, opCount + 1);
		}
		else {
			return binarySearch(sorted,value, middle + 1, (pSize - 1) / 2, pos, depth / 2, opCount + 1);
		}
	}
}
//precondition: SortedArray must be initialized
//postcondition: Recursive serial search
bool linearSearch(T*sorted,T searchValue, int index, size_t size) {
	//linear search
	if (sorted[index] == searchValue) { // once found returns true
		return true;
	}

	if (index == size - 1 && sorted[index] != searchValue) { //if at the last index and not found return false

		return false;
	}
	else
		return searchElement(sorted,searchValue, ++index, size); //calls recursively
}

////precondition: SortedArray must be initialized
////postcondition: Recursive serial search
//bool linearSearch(vector<T> sorted, T searchValue, typename vector<T>::iterator begin) {
//	//linear search
//	if ( begin == sorted.end()) { //if at the last index and not found return false
//
//		return false;
//	}
//
//	if (*begin == searchValue) { // once found returns true
//		return true;
//	}
//	
//	else
//		return searchElement(sorted,searchValue, ++begin); //calls recursively
//}


};




