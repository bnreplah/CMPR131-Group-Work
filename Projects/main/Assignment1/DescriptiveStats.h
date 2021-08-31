#pragma once
#include "input.h"
#include <iostream>
#include "Header1.h"
//#include <vector>
#include <fstream>



class DescriptiveStatistics {
private:
	bool dataLoaded = bool(false);
	string* dataFile = nullptr;
	bool toInt = bool(false);
	LinkTList<double> dataset;
	bool def = false;//if defaults were set

public:

	///
	///
	DescriptiveStatistics(string filename = "DATASET3.DAT") {
		if (filename == "DATASET3.DAT")
			def = true;
		dataFile = new string(filename);
	}//


	///
	///
	~DescriptiveStatistics() {
		delete dataFile;
	}//

	void read(string filename) {
		double value = double();
		fstream file = fstream(filename, ios::in);
		int items = int();
		
		for (items = 1; file >> value ; items++) {
			dataset.insertNode(value);
			if (file.eof())
				break;
		}//end for
		dataset.print();
		std::cout << "\n";
	}





};//

/// 
///  
// menu for descriptiveStatistics
char menuDS() {

	clrScrn();
	header("CMPR 131 -  Chapter 1 Software Development by Thien , Itz, Tony, Jose, and Ben");
	string options[] = { "\n\t\tA> Read data file, store into a sorted dynamic array and display the data set ",
						"\n\t\tB> Minimum\t\t\t\tM> Mid Range",
						"\n\t\tC> Maximum\t\t\t\tN> Quartiles",
						"\n\t\tD> Range\t\t\t\tO> Interquartile Range",
						"\n\t\tE> Size\t\t\t\t\tP> Outliers",
						"\n\t\tF> Sum\t\t\t\t\tQ> Sum of Squares",
						"\n\t\tG> Mean\t\t\t\t\tR> Mean Absolute Deviation",
						"\n\t\tH> Median\t\t\t\tS> Root Mean Square",
						"\n\t\tI> Frequencies\t\t\t\tT> Standard Error of the Mean",
						"\n\t\tJ> Mode\t\t\t\t\tU> Coefficient of Variation",
						"\n\t\tK> Standard Deviation\t\t\tV> Relative Standard Deviation ",
						"\n\t\tL> Variance\t\t\n\t\tW> Display all results and write to an output text file",
						"\n" + string(100 , char(196)) +
						"\n\t\t0> exit "

	};
	for (string option : options)
		cout << option;
	header("");
	return inputChar(string("\nOption : "), string("abcdefghijklmnopqrstuvw"));
}//end menuDS


// Note: possibly change name of function.
/// 
///
void runDescriptiveStatistics() {

	DescriptiveStatistics desc = DescriptiveStatistics();

	do {
		switch (menuDS()) {
			case '0': return;

			case 'A': desc.read("DATASET3.DAT"); break;

			case 'B':  break;

			case 'C': break;

			case 'D':  break;

			case 'E':  break;

			case 'F':break;

			case 'G':break;

			case 'H':break;

			case 'I':break;

			case 'J':break;

			case 'K':break;

			case 'L':break;

			case 'M':break;

			case 'N':break;

			case 'O':break;

			case 'P':break;

			case 'Q':break;

			case 'R':break;

			case 'S':break;

			case 'T':break;

			case 'U':break;

			case 'V':break;

			case 'W':break;

			default:;
		}//end switch
		pause();
	} while (true);
	
}


