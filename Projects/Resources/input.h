#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

//return an input char
char inputChar(string prompt, string listChars)
{
	char input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR-1A: Invalid input. Must be a character type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		bool bfound = false;
		for (unsigned c = 0; c < listChars.length(); c++)
			if (toupper(listChars[c]) == toupper(input))
			{
				bfound = true;
				break;
			}
		if (!bfound)
		{
			cout << "ERROR-2A: Invalid input. Must be a character from the list of '";
			for (unsigned c = 0; c < listChars.length() - 1; c++)
				cout << "'" << static_cast<char>(toupper(listChars[c])) << "', ";
			cout << "or '" << static_cast<char>(toupper(listChars.back())) << "'.\n";
		}
		else
			break;
	} while (true);
	return input;
}

//return an input char of y or n
char inputChar(string prompt, char yes, char no)
{
	char input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR-1A: Invalid input. Must be a character type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (tolower(input) != tolower(yes) && tolower(input) != tolower(no))
			cout << "ERROR-2A: Invalid input. Must be a '" << static_cast<char>(toupper(yes)) << "' or '" << static_cast<char>(toupper(no)) << "' character.\n";
		else
			break;
	} while (true);
	return input;
}

//return an input char
char inputChar(string prompt, bool alphaOrDigit)
{
	char input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR-1A: Invalid input. Must be a character type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (alphaOrDigit && !isalpha(input))
			cout << "ERROR-2A: Invalid input. Must be an alphabet character.\n";
		else if (!alphaOrDigit && !isdigit(input))
			cout << "ERROR-2A: Invalid input. Must be a digit character.\n";
		else
			break;
	} while (true);
	return input;
}

//return an input char
char inputChar(string prompt)
{
	char input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR-1A: Invalid input. Must be a character type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else
			break;
	} while (true);
	return input;
}

//return an input interger
int inputInteger(string prompt)
{
	int input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR-1A: Invalid input. Must be an integer type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else
			break;
	} while (true);
	return input;
}

//return an integer where posNeg is positive (true) or negative (false)
int inputInteger(string prompt, bool posNeg)
{
	int input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR-2A: Invalid input. Must be an integer type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (posNeg && input < 0)
			cout << "ERROR-2A: Invalid input. Must be a positive number.\n";
		else if (!posNeg && input >= 0)
			cout << "ERROR-2A: Invalid input. Must be a negative number.\n";
		else
			break;
	} while (true);
	return input;
}

//return an input integer within range ,start and end
int inputInteger(string prompt, int startRange, int endRange)
{

	int input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR-3A: Invalid input. Must be an integer type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (!(input >= min(startRange, endRange) && input <= max(startRange, endRange)))
			cout << "ERROR-3A: Invalid input. Must be from " << startRange << ".." << endRange << ".\n";
		else
			break;
	} while (true);
	return input;
}

//return an input double
double inputDouble(string prompt)
{
	double input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR-1B: Invalid input. Must be a double type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else
			break;
	} while (true);
	return input;
}

//return a double where posNeg is positive (true) or negative (false)
double inputDouble(string prompt, bool posNeg)
{
	double input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR-2B: Invalid input. Must be a double type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (posNeg && input < 0.0)
			cout << "ERROR-2B: Invalid input. Must be a positive number.\n";
		else if (!posNeg && input >= 0.0)
			cout << "ERROR-2B: Invalid input. Must be a negative number.\n";
		else
			break;
	} while (true);
	return input;
}

//return a double where greaterEqual is (true) or (false) of startValue
double inputDouble(int test, string prompt, double startValue, bool greater, bool equal)
{
	double input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR-3B: Invalid input. Must be a double type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (greater && equal && input < startValue)
			cout << "ERROR-3B: Invalid input. Must be greater than or equal to " << startValue << ".\n";
		else if (!greater && !equal && input >= startValue)
			cout << "ERROR-3B: Invalid input. Must be lesser than " << startValue << ".\n";
		else
			break;
	} while (true);
	return input;
}

//return an input double within range ,start and end
double inputDouble(string prompt, double startRange, double endRange)
{
	double input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR-4B: Invalid input. Must be a double type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (!(input >= min(startRange, endRange) && input <= max(startRange, endRange)))
			cout << "ERROR-4B: Invalid input. Must be from " << startRange << ".." << endRange << ".\n";
		else
			break;
	} while (true);
	return input;
}