#pragma once		
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


/// <summary>
/// PreCondition: spaces (boolean true or false)
/// PostCondition: returns a string including space character(s) or without space character
/// 
/// </summary>
/// <param name="prompt"></param>
/// <param name="spaces"></param>
/// <returns>string value inputed by the user</returns>
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
	return input;
}


/// <summary>
/// PreCondition: spaces (boolean true or false)
/// PostCondition: returns a string including space character(s) or without space character
/// overloaded function used in loops, 
/// [overloaded]
/// </summary>
/// <param name="prompt">: (string) prompt the user</param>
/// <param name="spaces">: (bool) Whether to accept spaces</param>
/// <param name="count">: (bool) Whether to inclue the count or not</param>
/// <param name="value">: (int) count value</param>
/// <returns>string value inputed by the user</returns>
string inputString(string prompt, bool spaces, bool count, int value)
{
	string input = "";
	if (count)
		prompt += "[" + to_string(value) + "]: ";
	else
		prompt += ":";
	cout << prompt;
	if (spaces)
		getline(cin, input);
	else
	{
		cin >> input;
		cin.clear();
		cin.ignore(999, '\n');
	}
	return input;
}//end inputString


/// <summary>
//PreCondition: valid yes (char) or no (char)
//PostCondition: returns an uppercase  yes (char) or no (char) 
/// </summary>
/// <param name="prompt">: A string value to prompt the user</param>
/// <param name="yes">: the char value for yes to ask the user for</param>
/// <param name="no">: the char value for no to ask the user for</param>
/// <returns> The char value option the user picked (yes or no)</returns>
char inputChar(string prompt, char yes, char no)
{
	char input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be a character type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (tolower(input) != tolower(yes) && tolower(input) != tolower(no))
			cout << "ERROR: Invalid input. Must be a '" << static_cast<char>(toupper(yes)) << "' or '" << static_cast<char>(toupper(no)) << "' character.\n";
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');

	return toupper(input);
}


/// <summary>
/// PreCondition: alphaOrDigit (boolean true or false)
/// PostCondition: returns an alphabet or a digit character
/// </summary>
/// <param name="prompt">: The string to prompt the use</param>
/// <param name="alphaOrDigit">: Boolean value whether the input will accept alphanumerical values</param>
/// <returns></returns>
char inputChar(string prompt, bool alphaOrDigit)
{
	char input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be a character type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (alphaOrDigit && !isalpha(input))
			cout << "ERROR: Invalid input. Must be an alphabet character.\n";
		else if (!alphaOrDigit && !isdigit(input))
			cout << "ERROR: Invalid input. Must be a digit character.\n";
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}


/// <summary>
/// PreCondition: NA
/// PostCondition: returns any character
/// </summary>
/// <param name="prompt">: The string value to prompt the user</param>
/// <returns> The char value inputted by the user</returns>
char inputChar(string prompt)
{
	char input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be a character type.\n";
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


/// <summary>
/// PreCondition: NA
/// PostCondition: returns any integer value
///		basic int input validation
/// </summary>
/// <param name="prompt">: The string value to prompt the user</param>
/// <returns> The int in which the user inputted </returns>
int inputInteger(string prompt)
{
	int input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be an integer type.\n";
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


/// <summary>
/// PreCondition: posNeg (boolean true or false)
/// PostCondition: returns a positive integer value (posNeg = true) or a negative integer value (poseNeg = false)
///		Input validation 
///  </summary>
/// <param name="prompt">: The string value to prompt the user</param>
/// <param name="posNeg">: A boolean value for whether the input should accept positive (true) or negative (false) values</param>
/// <returns>The int the user inputted</returns>
int inputInteger(string prompt, bool posNeg)
{
	int input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be an integer type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (posNeg && input <= 0)
			cout << "ERROR: Invalid input. Must be a positive number.\n";
		else if (!posNeg && input >= 0)
			cout << "ERROR: Invalid input. Must be a negative number.\n";
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}


/// <summary>
/// PreCondition: start (integer) and greater (boolean true or false)
/// PostCondition: returns an integer value greater than start or lesser than start
///		Greater or less than input validation
/// </summary>
/// <param name="prompt">: The string value to prompt the user</param>
/// <param name="start">: A integer value for reference</param>
/// <param name="greater">: A boolean value whether to accept values greater than the integer</param>
/// <returns> The int inputted by the user</returns>
int inputInteger(string prompt, int start, bool greater)
{
	int input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be an integer type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (greater && input < start)
			cout << "ERROR: Invalid input. Must be a greater than or equal to " << start << ".\n";
		else if (!greater && input > start)
			cout << "ERROR: Invalid input. Must be a lesser than or equal to " << start << ".\n";
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}


/// <summary>
/// PreCondition: start (integer) and greater (boolean true or false)
/// PostCondition: returns an integer value greater than start or lesser than start
///		Greater or less than input validation
/// </summary>
/// <param name="prompt">: The string value to prompt the user</param>
/// <param name="start">: A integer value for reference</param>
/// <param name="greater">: A boolean value whether to accept values greater than the integer</param>
/// <returns> The int inputted by the user</returns>
int inputInteger(string prompt,int count, string postCount ,int start, bool greater)
{
	prompt += to_string(count) + postCount;
	int input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be an integer type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (greater && input < start)
			cout << "ERROR: Invalid input. Must be a greater than or equal to " << start << ".\n";
		else if (!greater && input > start)
			cout << "ERROR: Invalid input. Must be a lesser than or equal to " << start << ".\n";
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}


/// <summary>
///	PreCondition: startRange (integer) and endRange (integer)
///	PostCondition: returns an integer value within range (startRannge and endRange)
///		Input validation within a range of two integers
/// </summary>
/// <param name="prompt">: The string value to prompt the user</param>
/// <param name="startRange">: The integer for the lower bound</param>
/// <param name="endRange">: The integer for the higher bound</param>
/// <returns> The int inputted by the user</returns>
int inputInteger(string prompt, int startRange, int endRange)
{
	int input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be an integer type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (!(input >= min(startRange, endRange) && input <= max(startRange, endRange)))
			cout << "ERROR: Invalid input. Must be from " << startRange << ".." << endRange << ".\n";
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}


/// <summary>
/// PreCondition: NA
/// PostCondition: returns any double value
///		Basic double input validation
/// </summary>
/// <param name="prompt">: The string value to prompt the user</param>
/// <returns> The double inputted by the user</returns>
double inputDouble(string prompt)
{
	double input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be a double type.\n";
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


/// <summary>
///	PreCondition: posNeg (boolean true or false)
///	PostCondition: returns a positive double value (posNeg = true) or a negative double value (poseNeg = false)
///		Positive or negative input validation for a double
/// </summary>
/// <param name="prompt">: The string value to prompt the user</param>
/// <param name="posNeg">: The boolean value whether to accept positive (true) or negative (false) values</param>
/// <returns> The double inputted by the user</returns>
double inputDouble(string prompt, bool posNeg)
{
	double input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be a double type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (posNeg && input <= 0.0)
			cout << "ERROR: Invalid input. Must be a positive number.\n";
		else if (!posNeg && input >= 0.0)
			cout << "ERROR: Invalid input. Must be a negative number.\n";
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}


/// <summary>
///	PreCondition: start(integer) and greater(boolean true or false)
///	PostCondition: returns an integer value greater than start or lesser than start
///		Input validation greater or lower than a double
/// </summary>
/// <param name="prompt">: The string value to prompt the user</param>
/// <param name="start">: The double value as a point of reference</param>
/// <param name="posNeg">: A boolean value whether to accept values greater (true) or less than (false) the double</param>
/// <returns> The double inputted by the user</returns>
double inputDouble(string prompt, double start, bool posNeg)
{
	double input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be a double type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (posNeg && input <= start)
			cout << "ERROR: Invalid input. Must be greater than or equal to " << start << ".\n";
		else if (!posNeg && input >= start)
			cout << "ERROR: Invalid input. Must be lesser than or equal to " << start << ".\n";
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}


/// <summary>
///	PreCondition: start(integer) and greater(boolean true or false)
///	PostCondition: returns an integer value greater than start or lesser than start
///		Input validation greater or lower than a double
/// [overlaoded]
/// </summary>
/// <param name="prompt">: The string value to prompt the user</param>
/// <param name="start">: The double value as a point of reference</param>
/// <param name="posNeg">: A boolean value whether to accept values greater (true) or less than (false) the double</param>
/// <returns> The double inputted by the user</returns>
double inputDouble(string prompt, bool count, int value, double start, bool posNeg)
{
	double input = double();
	if (count)
		prompt += "[" + to_string(value) + "]: ";

	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be a double type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (posNeg && input <= start)
			cout << "ERROR: Invalid input. Must be greater than or equal to " << start << ".\n";
		else if (!posNeg && input >= start)
			cout << "ERROR: Invalid input. Must be lesser than or equal to " << start << ".\n";
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}


/// <summary>
/// PreCondition: startRange (integer) and endRange (integer)
/// PostCondition: returns an integer value within range (startRannge and endRange)
///		Input validation within a range
/// </summary>
/// <param name="prompt">: The string value to prompt the user</param>
/// <param name="startRange">: The lower bounds</param>
/// <param name="endRange">: The higher bounds</param>
/// <returns> The double inputted by the user</returns>
double inputDouble(string prompt, double startRange, double endRange)
{
	double input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be a double type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (!(input >= min(startRange, endRange) && input <= max(startRange, endRange)))
			cout << "ERROR: Invalid input. Must be from " << startRange << ".." << endRange << ".\n";
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}
//EOF