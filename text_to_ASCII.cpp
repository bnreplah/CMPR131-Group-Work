#include <iostream>
#include <string>
using namespace std;

int main() {
	do
	{
		cout << endl << "1\> ASCII Text To ASCII Numbers";
		cout << endl << "═════════════════════════════════════════════════════════════════════════════════════════";
		cout << endl << "	A \> Enter a text string";
		cout << endl << "	B \> Convert the text string to ASCII numbers";
		cout << endl << "	C \> Save the converted ASCII numbers into a binary file";
		cout << endl << "	D \> Read the binary file";
		cout << endl << "──────────────────────────────────────────────────────────────────────────────────────────";
		cout << endl << " 	0 \> return";
		cout << endl << "══════════════════════════════════════════════════════════════════════════════════════════";
		char option = '0';
		string text = "temp";

		switch (option)
		{
			case 0: exit;
			case 'A' || 'a': inputTextstring(text); break;
			case 'B' || 'b': convertTextToASCII(text,ascii); break;
			case 'C' || 'c': saveASCIIToBinaryFile(ascii); break;
			case 'D' || 'd': readBinaryFile(); break;

		}
	} while (true);
}
