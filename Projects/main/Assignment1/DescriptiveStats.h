// Option 3 Descriptive Statistics design delegated to:
// Reviewed by:
// 2nd Reviewer:
// How to use
//
//


#pragma once
#include "input.h"
#include <iostream>
#include "myContainers.h"
#include <vector>
#include <map>
#include <fstream>

//no using namespace in header files ( best practice )


/// [Class] Descriptive Statistics
///		Public:
///			DescriptiveStatistics()
///			read()
///			
class DescriptiveStatistics {

private:

	bool dataLoaded = bool(false);						//
	
	string* dataFile = nullptr;							//
	
	bool toInt = bool(false);							//
	
	LinkTList<double> dataset = LinkTList<double>();	// ADT LinkList holding dataset loaded from file
	
	bool def = false;									// if defaults were set < Consider removing, possibly redundent

	const bool debug = true;							// constant debugging variable

public:


	/// Precondition:
	/// Postcondition:
	/// [Default Constructor]
	/// Set with a default value for testing purposes, consider removing later
	DescriptiveStatistics(string filename = "DATASET3.DAT") {
		if (filename == "DATASET3.DAT")
			def = true;
		dataFile = new string(filename);
	}//end constructor



	/// Postcondition: Deallocated memory dynamically allocated for the dataFile pointer and any other dynamically allocated member variables
	/// [Destructor]
	~DescriptiveStatistics() {

		//debugging switch:
		if (debug) { std::cout << "\n~calling destructor\n"; }

		delete dataFile;
		
	}//end destructor


	/// Precondition: (string) filename is an existing file containing (int) data to be read into the program
	/// Postcondition: reads, inserts, and sorts, the data inputed from the file
	void read(string filename) {
		//precondition check:



		//start initialization

		double value = double();
		fstream file = fstream(filename, ios::in);
		int items = int();
		
		//end initialization


		for (items = 1; file >> value ; items++) {
			dataset.insertNode(value);
			if (file.eof())
				break;
		}//end for
		dataset.print();
		std::cout << "\n";
	}//end read

	/// Precondition:
	/// Postcondition:
	double getMin() const {
		return dataset.getPos(0);
	}//end getMin

	/// Precondition:
	/// Postcondition: 
	double getMax() const {
		return (dataset.getPos(dataset.getSize() - 1));
	}//end getMax

	/// Precondition:
	/// Postcondition:
	double getRange() const {
		return getMax() - getMin();
	}//end getRange

	/// Precondition:
	/// Postcondition:
	double getSum() const {
		double sum = double();
		for (int i = 0; i < dataset.getSize(); i++) {
			
			//debugging
			//std::cout << dataset[i] << ":" << sum << endl;
			
			sum += dataset[i];
		}//end for
		return (sum);
	}//end getSum


	/// Precondition:
	/// Postcondition:
	int getSize() const {
		return dataset.getSize();
	}//end getSize


	/// Precondition:
	/// Postcondition:
	double getMean() const {
		return (getSum() / getSize());
	}//end getMean


	/// Precondition:
	/// Postcondition:
	double getMedian() const {
		bool isOdd = (dataset.getSize() % 2) != 0;
		int pos = int();
		if (isOdd) {
			pos = (dataset.getSize() + 1) / 2;
			pos--;//to account for 1 to 0 shift
			return dataset[pos];
		}
		else {
			double total = dataset[(dataset.getSize() / 2)] + dataset[(dataset.getSize() / 2) - 1];
			return total / 2.0;
		}	
	}


	/// Precondition:
	/// Postcondition:
	pair<map<double, int>, vector<double>> getFrequecies() const {
		map <double, int> frequencies;
		vector<double> unique_values;
		for (int strt = 0; strt < dataset.getSize();  strt++) {
			double cur = dataset[strt];
			if (frequencies.at(cur)) {
				frequencies[cur] += 1;
			}
			else {
				frequencies.insert(std::pair<double, int>(cur, 1));
				unique_values.push_back(cur);
			}
		}

		return pair<map<double, int>, vector<double>>(frequencies, unique_values);
	}

	/// Precondition:
	/// Postcondition:
	// Possibly consider alternative to getMode/getFrequencies
	double getMode() const {
		map<double, int> freq = getFrequecies().first;
		vector<double> key = getFrequecies().second;
		vector<double> mode;
	//
	//get highest number possibly multiple from frequencies
	//


	}


	/// Precondition:
	/// Postcondition:
	double getStandardDeviation() {
		
		//stub
		return 0;

	}



	/// Precondition:
	/// Postcondition:
	double getVariance() {

		//stub
		return 0;

	}



	/// Precondition:
	/// Postcondition:
	double getQuartiles() {

		//stub
		return 0;

	}



	/// Precondition:
	/// Postcondition:
	double getInterQuartileRange() {

		//stub
		return 0;

	}



	/// Precondition:
	/// Postcondition:
	double getOutliers() {

		//stub
		return 0;

	}



	/// Precondition:
	/// Postcondition:
	double getSumOfSquares() {

		//stub
		return 0;

	}



	/// Precondition:
	/// Postcondition:
	double getMeanAbsoluteDeviation() {

		//stub
		return 0;

	}




	/// Precondition:
	/// Postcondition:
	double getRootMeanSquare() {

		//stub
		return 0;

	}



	/// Precondition:
	/// Postcondition:
	double getStandardErrorOfTheMean() {

		//stub
		return 0;

	}



	/// Precondition:
	/// Postcondition:
	double getCoeffecientOfVariation() {

		//stub
		return 0;

	}



	/// Precondition:
	/// Postcondition:
	double getRelativeStandardDeviation() {

		//stub
		return 0;

	}





};//end class Descriptive Statistics

/// Precondition:
/// Postcondition:
// menu for descriptiveStatistics
char menuDS() {

	clrScrn();
	header("CMPR 131 -  Chapter 1 Software Development by Thien , Itz, Tony, Jose, and Ben");
	//end header

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

	};//end array definition

	//loops and prints out all the options
	for (string option : options)
		std::cout << option;

	header("");
	
	return inputChar(string("\nOption : "), string("abcdefghijklmnopqrstuvw"));//return the user inputed char from the allowed options
}//end menuDS


// Note: possibly change name of function.
/// 
///
void runDescriptiveStatistics() {

	DescriptiveStatistics desc = DescriptiveStatistics();

	do {
		switch (menuDS()) {
			case '0': return;


			case 'A': { 
	
				desc.read("DATASET3.DAT");
				break; 
			
			}//end case A


			case 'B': { 
				
				std::cout << desc.getMin();
				break; 
			
			}//end case B


			case 'C': {
			
				std::cout << desc.getMax();
				break; 
			
			}//end case C


			case 'D': {
			
				std::cout << desc.getRange();
				break;
			
			}//end case D


			case 'E': { 
				
				std::cout << desc.getSize(); 
				break; 
			
			}//end case E


			case 'F': {
				
				std::cout << desc.getSum();
				break; 
			
			}//end case F


			case 'G': {

				std::cout << desc.getMean();
				break; 
			
			}//end case G


			case 'H': { 

				std::cout << desc.getMean();
				break; 
			
			}//end case H


			case 'I': {

				std::cout << desc.getMean();
				break;
			
			}//end case I


			case 'J': {

				std::cout << desc.getMean();
				break;
			
			}//end case J


			case 'K': {

				std::cout << desc.getMean();
				break;
			
			}//end case K


			case 'L': {

				std::cout << desc.getMean();
				break;
			
			}//end case L


			case 'M': {

				std::cout << desc.getMean();
				break;
			
			}//end case M


			case 'N': {

				std::cout << desc.getMean();
				break;
			
			}//end case N


			case 'O': {

				std::cout << desc.getMean();
				break;
			
			}//end case O


			case 'P': {

				std::cout << desc.getMean();
				break;
			
			}//end case P


			case 'Q': {

				std::cout << desc.getMean();
				break;
			
			}//end case Q


			case 'R': {
				std::cout << desc.getMean();
				break;
			
			}//end case R


			case 'S': {

				std::cout << desc.getMean();
				break;
			
			}//end case S


			case 'T': {

				std::cout << desc.getMean();
				break;
			
			}//end case T


			case 'U': {

				std::cout << desc.getMean();
				break;
			
			}//end case U


			case 'V': {

				std::cout << desc.getMean();
				break;
			
			}//end case V


			case 'W': {

				std::cout << desc.getMean();
				break;
			
			}//end case W


			default: { 

				std::cout << desc.getMean();
				break;
			
			}//end default

		}//end switch
		pause();
	} while (true);
	
}


