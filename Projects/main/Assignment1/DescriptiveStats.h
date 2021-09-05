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
#include <cstdio>//stdio.h
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

	bool *dataLoaded = nullptr;								//
	
	string* dataFile = nullptr;								//
	
	//bool *toInt = nullptr;								//
	
	LinkTList<double> dataset;								// ADT LinkList holding dataset loaded from file
	
	//bool *def = nullptr;									// if defaults were set < Consider removing, possibly redundent

	const bool debug = true;								// constant debugging variable

public:

	//##########################################################################################################
	// Default Constructor									Completed: [Y] []	Reviewed: [] [N]	Tested [Y][1]
	//##########################################################################################################

	/// Precondition: (string) fileName is an existing file containing a dataset
	/// Postcondition: 
	/// [Default Constructor]
	/// Set with a default value for testing purposes, consider removing later
	DescriptiveStatistics() {
		dataLoaded = new bool(false);
		dataFile = new string();
		//toInt = new bool(false);
		//dataset = new LinkTList<double>();

	}//end constructor

	//##########################################################################################################
	// Destructor											Completed: [Y] []	Reviewed: [] [N]	Tested [Y][1]
	//##########################################################################################################

	/// Postcondition: Deallocated memory dynamically allocated for the dataFile pointer and any other dynamically allocated member variables
	/// [Destructor]
	~DescriptiveStatistics() {

		//debugging switch:
		if (debug) { std::cout << "\n\t\t[DEBUG]: ~calling destructor\n"; }

		delete dataLoaded;
		delete dataFile;
		
	}//end destructor

	//##########################################################################################################
	// read( filename: string ): void						Completed: [Y] []	Reviewed: [] [N]	Tested [Y][1]
	//##########################################################################################################


	/// Precondition: (string) filename is an existing file containing (int) data to be read into the program
	/// Postcondition: reads, inserts, and sorts, the data inputed from the file
	void read(string filename) {

		if (debug) { std::cout << "\n\t\t[DEBUG]: filename" << filename << "\n"; }

		//precondition check:
		fstream chk = fstream(filename, ios::in);
		if (!chk) {//if the file doesn't exist return from read 
		
			std::cout << "\nERROR: File does not exist!\n";
			chk.close();
			return;

		}//end if
		else {
			chk.close();
		}//end else
		//end precondition check


		double value = double();
		fstream file = fstream(filename, ios::in);
		int items = int();
		
		//end initialization


		for (items = 1; file >> value ; items++) {
			if (debug) { std::cout << "\n\t\t[DEBUG]: value read:"<< value <<" \n"; }
			dataset.insertNode(value);
			if (file.eof())
				break;
		}//end for
		dataset.print();
		std::cout << "\n";
	}//end read

	//##########################################################################################################
	// clear(): void										Completed: [Y] []	Reviewed: [] [N]	Tested [N][0]
	//##########################################################################################################

	/// Precondition: N/A
	/// Postcondition: Empties the contents of the dataset 
	void clear() {

		this->dataset.clear();

	}// end clear

	//##########################################################################################################
	// ReplaceDataset( filename: string ) : void			Completed: [Y] []	Reviewed: [] [N]	Tested [N][0]
	//##########################################################################################################

	/// Precodition: N/A 
	/// Postcondition: Clears the data currently stored in the current dataset
	void replaceDataset(string fileName) {
		if (debug) { std::cout << "\n\t\t[DEBUG]: filename" << fileName << "\n"; }

		this->clear();
		read(fileName);

	}//end replaceDataset

	//##########################################################################################################
	// getMin() const : double								Completed: [Y] []	Reviewed: [] [N]	Tested [Y][1]
	//##########################################################################################################

	/// Precondition: dataset cannot be empty
	/// Postcondition: returns the first value in the sorted dataset
	double getMin() const {
		
		return dataset.getPos(0);
	
	}//end getMin

	//##########################################################################################################
	// getMax() const : double								Completed: [Y] []	Reviewed: [] [N]	Tested [Y][1]
	//##########################################################################################################

	/// Precondition: dataset cannot be empty
	/// Postcondition: returns the last value in the sorted dataset
	double getMax() const {

		return (dataset.getPos(dataset.getSize() - 1));
	
	}//end getMax

	//##########################################################################################################
	// getRange() const : double							Completed: [Y] []	Reviewed: [] [N]	Tested [Y][1]
	//##########################################################################################################

	/// Precondition: dataset cannot be empty
	/// Postcondition: returns the range from the highest to the lowest values in the dataset
	double getRange() const {

		return getMax() - getMin();
	
	}//end getRange

	//##########################################################################################################
	// getSum() const : double								Completed: [Y] []	Reviewed: [] [N]	Tested [Y][1]
	//##########################################################################################################


	/// Precondition: dataset cannot be empty
	/// Postcondition: returns the sum of all the values in 
	double getSum() const {

		double sum = double();
		//end initialization

		for (int i = 0; i < dataset.getSize(); i++) {
			
			//debugging
			//std::cout << dataset[i] << "+ ... =" << sum << endl;
			
			sum += dataset[i];
		}//end for
		return (sum);

	}//end getSum

	//##########################################################################################################
	// getSize() const: int									Completed: [Y] []	Reviewed: [] [N]	Tested [Y][1]
	//##########################################################################################################

	/// Precondition: dataset must be instatiated
	/// Postcondition: Returns the size of the dataset
	int getSize() const {

		return dataset.getSize();
	
	}//end getSize

	//##########################################################################################################
	// getMean() const : double								Completed: [Y] []	Reviewed: [] [N]	Tested [Y][1]
	//##########################################################################################################

	/// Precondition: dataset cannot be empty
	/// Postcondition: Returns the average ( mean ) sum / size
	double getMean() const {
	
		return ( getSum() / getSize() );
	
	}//end getMean

	//##########################################################################################################
	// getMedian() const : double							Completed: [Y] []	Reviewed: [] [N]	Tested [N][0]
	//##########################################################################################################

	/// Precondition: dataset cannot be empty
	/// Postcondition: If the size of the dataset is
	///					 odd then, the middle index is the median.
	///					 even then, the median is the average of the two middle values  
	double getMedian() const {
		
		bool isOdd = (dataset.getSize() % 2) != 0;								//boolean for better readibility
		int pos = int();														//int holding position of median
		//end initialization

		if (isOdd) {

			pos = (dataset.getSize() / 2);
			//pos--;//to account for 1 to 0 shift
			return dataset[pos];
		
		}//end if
		else {
		
			double total = dataset[(dataset.getSize() / 2)] + dataset[(dataset.getSize() / 2) - 1];
			return total / 2.0;
		
		}//end else	
	}//end getMedian

	//##########################################################################################################
	// getFrequencies() const : pair						Completed: [Y] []	Reviewed: [] [N]	Tested [Y][1]
	//##########################################################################################################

	/// Precondition: dataset cannot be empty
	/// Postcondition: Returns a ( pair ) containing a ( map ) with the frequencies and a ( vector ) filled with the unique values of the dataset
	pair<map<double, int>, vector<double>> getFrequecies() const {
		map <double, int> frequencies;
		vector<double> unique_values;
		//end initialization

		for (int strt = 0; strt < dataset.getSize();  strt++) {
			
			double cur = dataset[strt];
			if (frequencies.find(cur) != frequencies.end()) {//out of bounds error
				
				frequencies[cur] = frequencies.at(cur) + 1;
		
			}//end if
			else {
			
				frequencies.insert(std::pair<double, int>(cur, 1));
				unique_values.push_back(cur);
			
			}//end else
		
		}//end for

		return pair<map<double, int>, vector<double>>(frequencies, unique_values);
	}//end getFrequencies

	//##########################################################################################################
	// displayFrequencies() : void							Completed: [Y] []	Reviewed: [] [N]	Tested [Y][1]
	//##########################################################################################################
	
	/// Precondition: N/A
	/// Postcondition: Prints out the frequencies of every value of the dataset in a formatted manner
	void displayFrequencies() {
		map<double, int> freq = getFrequecies().first;
		vector<double> keys = getFrequecies().second;
		//end initialization

		//prints frequency table
		printf("%10s %10s %15s \n", "Value", "Frequency", "Frequency %");
		for (double value : keys) {
			int percent = static_cast<int>(100 * ((static_cast<double>(freq.at(value))) / (static_cast<double>(getSize()))));
			printf("%10.2f %10i %13i %%\n", value, freq.at(value), percent);
		}//end for
	}//end 


	//##########################################################################################################
	// getMode() const: vector								Completed: [Y] []	Reviewed: [] [N]	Tested [N][0]
	//##########################################################################################################

	/// Precondition:
	/// Postcondition:
	// Possibly consider alternative to getMode/getFrequencies
	vector<double> getMode() const {
		map<double, int> freq = getFrequecies().first;
		vector<double> keys = getFrequecies().second;
		vector<double> mode;
		//end initialization
		

		int highest_freq = int();
		for (double value : keys) {

			if (debug) { std::cout << "\n\t\t[DEBUG]: key value: " << value << "\t[DEBUG]: frequency: " << freq.at(value); }
			
			if (freq.at(value) > 1) {//if frequency greater than 1
				
				if (freq.at(value) >= highest_freq) {
					highest_freq = freq.at(value);
					
					if (freq.at(value) == highest_freq) {
						mode.push_back(value);
					}//end if

					if (freq.at(value) > highest_freq) {

						if (mode.empty()) {
							mode.push_back(value);
						}//end if
						else {
							mode.clear();//empty the mode
							mode.push_back(value);
						}//end else
					}//end if
				}//end if
				
			}//end if
		}//end for
		return mode;

	}//end getMode

	//##########################################################################################################
	// getStandardDeviation() const : double				Completed: [Y] []	Reviewed: [] [N]	Tested [N][0]
	//##########################################################################################################

	// Standard Deviation
	//		Standard deviation is a measure of dispersion of data values from the mean.
	//		The formula for standard deviation is the square root of the sum of squared differences from the mean divided by the size of the data set.
	//

	/// Precondition: dataset cannot be empty
	/// Postcondition: Returns the standard deviation as defined [below] 
	///																	Standard deviation is a measure of dispersion of data values from the mean.
	///																	The formula for standard deviation is the square root of the sum of squared differences from the mean divided by the size of the data set.
	double getStandardDeviation() const {
		
		double sum = double();

		for (int i = 0; i < this->getSize(); i++)
			sum += pow((dataset[i] - (this->getMean())), 2.0);


		return sqrt( (sum) / static_cast<double>( (this->getSize()) ) )  ;

	}//end getStandardDeviation

	//##########################################################################################################
	// getVariance() const : double							Completed: [Y] []	Reviewed: [] [N]	Tested [N][0]
	//##########################################################################################################
	
	/// Precondition: dataset cannot be empty
	/// Postcondition: Returns the variance of the datset as defined by the definition [below]
	///																    Variance measures dispersion of data from the mean. 
	///																	The formula for variance is the sum of squared differences from the mean divided by the size of the data set.
	/// Note: the Variance is the standard Deviation ^2
	double getVariance() const {

		double sum = double();

		for (int i = 0; i < this->getSize(); i++)
			sum += pow((dataset[i] - (this->getMean())), 2.0);


		return sum / static_cast<double>(this->getSize());

	}//end getVariance

	//##########################################################################################################
	// getMidRange() const : double							Completed: [Y] []	Reviewed: [] [N]	Tested [N][0]
	//##########################################################################################################

	/// Precondition:
	/// Postcondition: Returns the average of the sum of the max and min
	double getMidRange() {


		return (this->getMax() + this->getMin()) / 2.0;

	}//end getQuartiles

	//##########################################################################################################
	// getStandardDeviation() const : double				Completed: [] [N]	Reviewed: [] [N]	Tested [N][0]
	//##########################################################################################################

	// could possibly improve by breaking it into another function 

	/// Precondition: 
	/// Postcondition:
	double getQuartiles() const {
		
		return 0;
	}//end getQuartiles

	//##########################################################################################################
	// RelativeStandardDeviation											Completed: [] [N]	Reviewed: [] [N]
	//##########################################################################################################

	/// Precondition:
	/// Postcondition:
	double getInterQuartileRange() {

		//stub
		return 0;

	}//end getInterQuartileRange

	//##########################################################################################################
	// getOutlier() const : double							Completed: [] [N]	Reviewed: [] [N]	Tested [N][0]
	//##########################################################################################################

	/// Precondition:
	/// Postcondition:
	double getOutliers() const{

		//stub
		return 0;

	}//end getOutliers

	//##########################################################################################################
	// getSumOfSquares() const : double						Completed: [] [N]	Reviewed: [] [N]	Tested [N][0]
	//##########################################################################################################

	/// Precondition:
	/// Postcondition:
	double getSumOfSquares() {

		//stub
		return 0;

	}//end getSumOfSquare

	//##########################################################################################################
	// getMeanAbsoluteDeviation() const : double			Completed: [] [N]	Reviewed: [] [N]	Tested [N][0]
	//##########################################################################################################

	/// Precondition:
	/// Postcondition:
	double getMeanAbsoluteDeviation() {

		//stub
		return 0;

	}//end getMeanAbsoluteDeviation


	//##########################################################################################################
	// getRootMeanSquare() const : double					Completed: [] [N]	Reviewed: [] [N]	Tested [N][0]
	//##########################################################################################################

	/// Precondition:
	/// Postcondition:
	double getRootMeanSquare() const{

		//stub
		return 0;

	}//end getRootMeanSquare

	//##########################################################################################################
	// getStandardErrorOfTheMean() const : double			Completed: [] [N]	Reviewed: [] [N]	Tested [N][0]
	//##########################################################################################################

	/// Precondition:
	/// Postcondition:
	double getStandardErrorOfTheMean() const {

		//stub
		return 0;

	}//end getStandardErrorOfTheMean

	//##########################################################################################################
	// getCoeffecientOfVariation() const : double			Completed: [] [N]	Reviewed: [] [N]	Tested [N][0]
	//##########################################################################################################

	/// Precondition:
	/// Postcondition:
	double getCoeffitiantOfVariation() const{

		//stub
		return 0;

	}//end getCoeffecientOfVariation

	
	//##########################################################################################################
	// getRelativeStandardDeviation() const : double		Completed: [] [N]	Reviewed: [] [N]	Tested [N][0]
	//##########################################################################################################


	/// Precondition:
	/// Postcondition:
	double getRelativeStandardDeviation() const {

		//stub
		return 0;

	}//end getRelativeStandardDeviation

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
/// Precondition:
/// Postcondition:
void runDescriptiveStatistics() {

	DescriptiveStatistics desc = DescriptiveStatistics();

	do {
		switch (menuDS()) {
			case '0': return; break;


			//#######################################################################################################################
			// Option A : Read													Completed: [Y] []	Reviewed: [] [N]
			//#######################################################################################################################
			

			case 'A': {//Read
				
				desc.read("DATASET3.DAT");
				break; 
			
			}//end case A

			//#######################################################################################################################
			// Option B : Min													Completed: [Y] []	Reviewed: [] [N]
			//#######################################################################################################################

			case 'B': {//min
				
				std::cout << desc.getMin();
				break; 
			
			}//end case B

			//#######################################################################################################################
			// Option C : Max													Completed: [Y] []	Reviewed: [] [N]
			//#######################################################################################################################

			case 'C': {//max
			
				std::cout << desc.getMax();
				break; 
			
			}//end case C

			//#######################################################################################################################
			// Option D : Range													Completed: [Y] []	Reviewed: [] [N]
			//#######################################################################################################################

			case 'D': {//range
			
				std::cout << desc.getRange();
				break;
			
			}//end case D

			//#######################################################################################################################
			// Option E : Size													Completed: [Y] []	Reviewed: [] [N]
			//#######################################################################################################################

			case 'E': {//size
				
				std::cout << desc.getSize(); 
				break; 
			
			}//end case E

			//#######################################################################################################################
			// Option F : Sum													Completed: [Y] []	Reviewed: [] [N]
			//#######################################################################################################################

			case 'F': {//sum
				
				std::cout << desc.getSum();
				break; 
			
			}//end case F

			//#######################################################################################################################
			// Option G : Mean													Completed: [Y] []	Reviewed: [] [N]
			//#######################################################################################################################

			case 'G': {//mean

				std::cout << desc.getMean();
				break; 
			
			}//end case G

			//#######################################################################################################################
			// Option H : Median												Completed: [Y] []	Reviewed: [] [N]
			//#######################################################################################################################

			case 'H': {//median 

				std::cout << desc.getMedian();
				break; 
			
			}//end case H

			//#######################################################################################################################
			// Option I : Display Frequencies									Completed: [Y] []	Reviewed: [] [N]
			//#######################################################################################################################

			case 'I': {//display frequencies

				desc.displayFrequencies();
				break;
			
			}//end case I

			//#######################################################################################################################
			// Option J : Mode													Completed: [Y] []	Reviewed: [] [N]
			//#######################################################################################################################

			case 'J': {//mode
				std::cout << "\nMode(s): ";
				if (desc.getMode().empty()) {
					std::cout << "no mode\n";
				}//end if
				else {
					for (double mode : desc.getMode())
						std::cout << mode << " ";
				}//end else
				break;
			
			}//end case J


			//#######################################################################################################################
			// Option K : Standard Deviation									Completed: [Y] []	Reviewed: [] [N]
			//#######################################################################################################################


			case 'K': {//standard deviation

				std::cout << desc.getStandardDeviation();
				break;
			
			}//end case K


			//#######################################################################################################################
			// Option L : Varaince												Completed: [Y] []	Reviewed: [] [N]
			//#######################################################################################################################


			case 'L': {//varaince

				std::cout << desc.getVariance();
				break;
			
			}//end case L

			//#######################################################################################################################
			// Option M : Mid range												Completed: [Y] []	Reviewed: [] [N]
			//#######################################################################################################################


			case 'M': {//mid range

				std::cout << desc.getMidRange();
				break;
			
			}//end case M

			//#######################################################################################################################
			// Option N : Quartiles												Completed: [Y] []	Reviewed: [] [N]
			//#######################################################################################################################

			case 'N': {//Quartiles
				//stub
				break;
			
			}//end case N

			//#######################################################################################################################
			// Option O : InterQuartile Range									Completed: [] [N]	Reviewed: [] [N]
			//#######################################################################################################################

			case 'O': {//interquartile range

				std::cout << desc.getInterQuartileRange();
				break;
			
			}//end case O

			//#######################################################################################################################
			// Option P : Outliers												Completed: [] [N]	Reviewed: [] [N]
			//#######################################################################################################################

			case 'P': {//Outliers

				std::cout << desc.getOutliers();
				break;
			
			}//end case P

			//#######################################################################################################################
			// Option Q : Sum of Squares										Completed: [] [N]	Reviewed: [] [N]
			//#######################################################################################################################

			case 'Q': {//sum of squares

				//stub
				break;
			
			}//end case Q

			//#######################################################################################################################
			// Option R : Mean Absolute Deviation								Completed: [] [N]	Reviewed: [] [N]
			//#######################################################################################################################

			case 'R': {//Mean Absolute Deviation
				std::cout << desc.getMeanAbsoluteDeviation();
				break;
			
			}//end case R

			//#######################################################################################################################
			// Option S : Root Mean Square										Completed: [] [N]	Reviewed: [] [N]
			//#######################################################################################################################

			case 'S': {//Root Mean Square

				std::cout << desc.getRootMeanSquare();
				break;
			
			}//end case S

			//#######################################################################################################################
			// Option T : Standard Error of the Mean							Completed: [] [N]	Reviewed: [] [N]
			//#######################################################################################################################

			case 'T': {//Standard Error of the Mean

				std::cout << desc.getStandardErrorOfTheMean();
				break;
			
			}//end case T


			//#######################################################################################################################
			// Option U : Coefficient of Variation								Completed: [] [N]	Reviewed: [] [N]
			//#######################################################################################################################


			case 'U': {// Coefficient of Variation

				std::cout << desc.getCoeffitiantOfVariation();
				break;
			
			}//end case U

			//#######################################################################################################################
			// Option V : Relative Standard Deviation							Completed: [] [N]	Reviewed: [] [N]
			//#######################################################################################################################

			case 'V': {//Relative Standard Deviation

				std::cout << desc.getRelativeStandardDeviation();
				break;
			
			}//end case V


			//#######################################################################################################################
			// Option W : Display all resultsand write to an output text file	Completed: [] [N]	Reviewed: [] [N]
			//#######################################################################################################################


			case 'W': {//Display all resultsand write to an output text file

				std::cout << desc.getMean();
				break;
			
			}//end case W


			//#######################################################################################################################
			// Invalid Option													Completed: [Y] []	Reviewed: [] [N]
			//#######################################################################################################################

			default: { 

				std::cout << "\nInvalid option: Please select a option within the menu";
				break;
			
			}//end default

		}//end switch
		pause();
	} while (true);
	
}


