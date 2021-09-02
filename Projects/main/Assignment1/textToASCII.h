#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <conio.h>		//needed for _getch()
#include <type_traits>
#include <fstream>
#include "input.h"

using namespace std;

/// Precondition: N/A
/// Postcondition: Diplays a menu for the user and prompt for the user's selection. Returns a valid option.
int Option1Menu() {
	clrScrn();
	header("1> ASCII Text To ASCII Numbers");
	string options[] = {"\n\t\tA> Enter a text string",
						"\n\t\tB> Convert the text string to ASCII numbers",
						"\n\t\tC> Save the converted ASCII numbers into a binary file",
						"\n\t\tD> Read the binary file",
						"\n" + string(100 , char(196)) +
						"\n\t\t0> return "

	};
	for (string option : options)
		cout << option;
	header("");
	return inputChar(string("\nOption: "), string("abcd"));
}

/// Precondition: N/A
/// Postcondition: return a string input from user entry
string stringInput() {
	string text = string();
	cout << "enter a text line:"; cin >> text;
	return text;
}

/// Precondition: Input string exist
/// Postcondition: return a string input by converting input string to ascii
string textToAscii(string inputText) {
	string ascii = ascii;
	if (inputText == string()) {
		perror("ERROR: empty input text.");
	}
	else {
		
		char temp = '0';
		string convert = string();
		for (int i = 0; i < inputText.length(); i++)
		{
			temp = inputText.at(i);
			convert = int(temp);
			ascii = ascii + convert + " ";
		}
		cout << "Converted to ASCII numbers:" << endl;
		cout << ascii << endl;
	}
	return ascii;
}

/// Precondition: ascii string exist
/// Postcondition: save the ascii into a bin file and return size of the string saved
void asciiToBin(string ascii) {
		if (ascii == string()) {
		cout << "ERROR: empty binary text." << endl;
		return 0;
	}
	else {
		fstream infile = fstream();
		infile.open("test.bin", ios::binary | ios::out);
		infile << ascii;
		infile.close();
		cout << "File, test.bin, has been written and saved." << endl;
		return size(ascii);
	}
}


/// Precondition: test.bin exist, ascii_size exist
/// Postcondition: read test.bin's data
void readTest(int ascii_size) {
	if (ascii_size == 0)
	{
		cout << "ERROR: unable to buffer the size of string to store.";
	}
	else
	{
		char* buffer = new char [ascii_size];
		fstream file = fstream();
		file.open("test.bin", ios::in);
		cout << "Reading file, test.bin..." << endl;
		file.read(buffer, ascii_size);
		cout << buffer << endl;
		file.close();
	}
	
}
