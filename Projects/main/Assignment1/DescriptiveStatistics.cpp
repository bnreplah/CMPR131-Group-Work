#pragma once
//
//
//
//
#include "input.h"
#include "Header1.h"
#include <fstream>
//#include <vector>


int main() {//debugging main 
	


}//end main

//menu for descriptiveStatistics
char menuDS() {

	clrScrn();
	header("CMPR 131 -  Chapter 1 Software Development by Thien , Itz, Tony, Jose, and Ben");
	string options[] = { "\n\t\tA> Read data file, store into a sorted dynamic array and display the data set ",
						"\n\t\tB> Minimum\t\t\t\tM> Mid Range",
						"\n\t\tC> Maximum\t\t\t\tN> Quartiles",
						"\n\t\tD> Range\t\t\t\tO> Interquartile Range",
						"\n\t\tE> Size\t\t\t\tP> Outliers",
						"\n\t\tF> Sum\t\t\t\tQ> Sum of Squares",
						"\n\t\tG> Mean\t\t\t\tR> Mean Absolute Deviation",
						"\n\t\tH> Median\t\t\t\tS> Root Mean Square",
						"\n\t\tI> Frequencies\t\t\t\tT> Standard Error of the Mean",
						"\n\t\tJ> Mode\t\t\t\tU> Coefficient of Variation",
						"\n\t\tK> ",
						"\n\t\tL> ",
						"\n\t\tM> ",
						"\n\t\tN> ",
						"\n\t\tO> ",
						"\n\t\tP> ",
						"\n\t\tQ> ",
						"\n\t\tR> ",
						"\n\t\tS> ",
						"\n\t\tT> ",
						"\n\t\tU> ",
						"\n\t\tV> ",
						"\n" + string(100 , char(196)) +
						"\n\t\t0> exit "

	};
	for (string option : options)
		cout << option;
	header("");
	return inputChar("Option : ", "abcdefghijklmnopqrstuv");
}//end menuDS


/// 
/// menuDriver for DescriptiveStatistics
bool runDescriptiveStatistics() {
	
	DescriptiveStatistics desc = DescriptiveStatistics();

	do {
		switch (menuDS()) {
		case 'A': 
			
			break;
		case 'B':
			
			
			break;
		case 'C':
			
			
			
			break;
		case 'D': 
			
			
			break;
		case 'E': 
			
			
			
			break;
		case 'F': 
			
			
			
			break;
		case 'G': 
			
			
			
			break;
		case 'H': 
			
			
			
			break;
		case 'I': 
			
			
			
			break;
		case 'J': 
			
			
			
			
			break;
		case 'K': 
			
			
			
			
			break;
		case 'L':
			
			
			
			break;
		case 'M':
			
			
			
			break;
		case 'N':
			
			
			
			break;
		case 'O':
			
			
			
			break;
		case 'P':
			
			
			
			break;
		case 'Q':
			
			
			
			
			break;
		case 'R':
			
			
			
			break;
		case 'S':
			
			
			
			
			break;
		case 'T':
			
			
			
			
			break;
		case 'U':
			
			
			
			
			break;
		case 'V':
			
			
			
			break;

		}//end switch

	} while (true);

	
}//end runDescriptiveStatistics

class DescriptiveStatistics {
private:

	string dataFile = string();
	bool dataLoaded = bool(false);
	LinkTList<double>* dataSet = nullptr;
	//vector<double>* vectorDataSet = nullptr;

public:

	/// [Default Constructor]
	/// Postcondition: initializes dataset linkList
	DescriptiveStatistics() {

		dataSet = new LinkTList<double>();
	
	}//end constructor

	~DescriptiveStatistics() {

		delete dataSet;
	
	}//end destructor

	/// Precondition:
	/// Postcondition:
	bool read();
	
	/// Precondition:
	/// Postcondition:
	bool populate();
	
	/// Precondition:
	/// Postcondition:
	void displaySet();

	/// Precondition:
	/// Postcondition:
	void displayAllOut();


	/// Precondition:
	/// Postcondition:
	double getMin();
	
	/// Precondition:
	/// Postcondition:
	double getMax();

	/// Precondition:
	/// Postcondition:
	double getRange();
	
	/// Precondition:
	/// Postcondition:
	double getSize();

	/// Precondition:
	/// Postcondition:
	double getSum();
	
	/// Precondition:
	/// Postcondition:
	double getMean();
	
	/// Precondition:
	/// Postcondition:
	double getMedian();
	
	/// Precondition:
	/// Postcondition:
	double getFrequencies();
	
	
	/// Precondition:
	/// Postcondition:
	double getMode();
	
	/// Precondition:
	/// Postcondition:
	double getStandardDeviation();
	
	
	
	/// Precondition:
	/// Postcondition:
	double getVariance();
	
	
	/// Precondition:
	/// Postcondition:
	double getMidRange();
	
	
	/// Precondition:
	/// Postcondition:
	double getQuartiles();
	
	
	/// Precondition:
	/// Postcondition:
	double getInterQuartileRange();
	
	/// Precondition:
	/// Postcondition:
	double getOutliers();
	
	
	/// Precondition:
	/// Postcondition:
	double getSumOfSquares();
	
	
	/// Precondition:
	/// Postcondition:
	double getMeanAbsoluteDeviation();
	
	
	
	/// Precondition:
	/// Postcondition:
	double getRootMeanSquare();
	
	
	/// Precondition:
	/// Postcondition:
	double getStandardErrorOfTheMean();
	
	
	/// Precondition:
	/// Postcondition:
	double getCoeffecientOfVariation();
	
	
	
	/// Precondition:
	/// Postcondition:
	double getRelativeStandardDeviation();


};