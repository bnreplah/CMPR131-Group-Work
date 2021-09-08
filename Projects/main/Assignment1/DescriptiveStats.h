// Option 3 Descriptive Statistics design delegated to: 
//		Thien Nguyen
//		Itz Rodriquez
//		Tony Cheng
//		Jose Chavez
//		Ben Halpern



#pragma once
#include "input.h"
#include <iostream>
#include <iomanip>
#include "myContainers.h"
#include <cstdio>//stdio.h
#include <vector>
#include <map>
#include <string>
#include <fstream>

//no using namespace in header files ( best practice )

//start prototypes

//end prototypes



/// Postcondition:
// menu for descriptiveStatistics
char menuDS() {

	char optionChar;
	clrScrn();
	header("\t\t3> Descriptive Statistics");
	//end header

	string options[] = { "\n\t\t\tA> Read data file, store into a sorted dynamic array and display the data set ",
						"\n\t\t\tB> Minimum\t\t\t\tM> Mid Range",
						"\n\t\t\tC> Maximum\t\t\t\tN> Quartiles",
						"\n\t\t\tD> Range\t\t\t\tO> Interquartile Range",
						"\n\t\t\tE> Size\t\t\t\t\tP> Outliers",
						"\n\t\t\tF> Sum\t\t\t\t\tQ> Sum of Squares",
						"\n\t\t\tG> Mean\t\t\t\t\tR> Mean Absolute Deviation",
						"\n\t\t\tH> Median\t\t\t\tS> Root Mean Square",
						"\n\t\t\tI> Frequencies\t\t\t\tT> Standard Error of the Mean",
						"\n\t\t\tJ> Mode\t\t\t\t\tU> Coefficient of Variation",
						"\n\t\t\tK> Standard Deviation\t\t\tV> Relative Standard Deviation ",
						"\n\t\t\tL> Variance\t\t\n\t\t\tW> Display all results and write to an output text file",
						"\n" + string(100 , char(95)) +
						"\n\t\t\t0> exit "

	};//end array definition
	
	//loops and prints out all the options
	for (string option : options)
		std::cout << option;

	header("");

	optionChar = inputChar(string("\n\t\t\tOption: "), string("abcdefghijklmnopqrstuvw"));//return the user inputed char from the allowed options
	clrScrn();
	return optionChar;
}//end menuDS





/// [Class] Descriptive Statistics
///		Public:
///			
class DescriptiveStatistics {

private:

	bool *dataLoaded = nullptr;								//pointer boolean for the value 
	
	string* dataFile = nullptr;								//string pointer for holding the path to the dataFile
	
	//bool *toInt = nullptr;								//pointer boolean for the value of whether to conver they types to int (developmental) 
	
	LinkTList<double> dataset;								// ADT LinkList holding dataset loaded from file
	
	//bool *def = nullptr;									// if defaults were set < Consider removing, possibly redundent

	bool debug = true;										// debugging variable
	bool fromSample = true;									//if false takes from population calcualtions

public:

	//##########################################################################################################
	// Default Constructor									
	// Completed: [Y] []	Reviewed: [Y] []	Tested [Y][1]
	//##########################################################################################################

	/// Precondition: (string) fileName is an existing file containing a dataset
	/// Postcondition: 
	/// [Default Constructor]
	/// Set with a default value for testing purposes, consider removing later
	DescriptiveStatistics(bool deb = false) {

		dataLoaded = new bool(false);
		dataFile = new string();
		debug = deb;

	}//end constructor
	
	 
	 
	 //##########################################################################################################
	// Parameter Constructor									
	// Completed: [Y] []	Reviewed: [Y] []	Tested [Y][1]
	//##########################################################################################################

	/// Precondition: (string) fileName is an existing file containing a dataset
	/// Postcondition: 
	/// [Default Constructor]
	/// Set with a default value for testing purposes, consider removing later
	DescriptiveStatistics(string filename, bool deb = false) {

		dataLoaded = new bool(false);
		dataFile = new string(filename);
		debug = deb;
		read(filename);
		
	}//end constructor


	//##########################################################################################################
	// Destructor											
	// Completed: [Y] []	Reviewed: [Y] []	Tested [Y][1]
	//##########################################################################################################

	/// Postcondition: Deallocated memory dynamically allocated for the dataFile pointer and any other dynamically allocated member variables
	/// [Destructor]
	~DescriptiveStatistics() {

		//debugging switch:
		if (debug) { std::cout << "\n\t\t[DEBUG]: ~calling destructor\n"; }

		delete dataLoaded;
		delete dataFile;
		
	}//end destructor


	bool getLoaded() {
		return *dataLoaded;
	}

	//##########################################################################################################
	// read( filename: string ): void						
	// Completed: [Y] []	Reviewed: [Y] []	Tested [Y][1]
	//##########################################################################################################


	/// Precondition: (string) filename is an existing file containing (int) data to be read into the program
	/// Postcondition: reads, inserts, and sorts, the data inputed from the file
	void read(string filename) {
		bool overWrite = bool();

		if (debug) { std::cout << "\n\t\t[DEBUG]: filename" << filename << "\n" << "\t\t[DEBUG]: dataLoaded = " << *this->dataLoaded; }

		//precondition check:
		fstream chk = fstream(filename, ios::in);
		if (!chk) {//if the file doesn't exist return from read 
		
			std::cout << "\n\t\tERROR: File does not exist!\n";
			chk.close();
			return;

		}//end if
		else {
			chk.close();
		}//end else
		//end precondition check

		//if dataset is already loaded
		if (*this->dataLoaded) {
			std::cout << "\n\t\tA dataset is already loaded";
			overWrite = (inputChar("\n\t\tWould you like to write over the data in the data set? ( Y / N ) : ", 'Y', 'N') == 'Y') ? true : false;

			if (overWrite) {
				replaceDataset(filename);
				return;
			}//end if

		}//end if

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
		std::cout << dataset.print();
		std::cout << "\n";
		*this->dataLoaded = true;

	}//end read

	//##########################################################################################################
	// clear(): void										
	// Completed: [Y] []	Reviewed: [Y] []	Tested [Y][1]
	//##########################################################################################################

	/// Precondition: N/A
	/// Postcondition: Empties the contents of the dataset 
	void clear() {

		this->dataset.clear();

	}// end clear

	//##########################################################################################################
	// ReplaceDataset( filename: string ) : void			
	// Completed: [Y] []	Reviewed: [Y] []	Tested [Y][1]
	//##########################################################################################################

	/// Precodition: N/A 
	/// Postcondition: Clears the data currently stored in the current dataset
	void replaceDataset(string fileName) {
		if (debug) { std::cout << "\n\t\t[DEBUG]: filename" << fileName << "\n"; }

		this->clear();
		*this->dataLoaded = false;
		read(fileName);
		*this->dataLoaded = true;
	}//end replaceDataset

	//##########################################################################################################
	// getMin() const : double								
	// Completed: [Y] []	Reviewed: [Y] []	Tested [Y][1]
	//##########################################################################################################

	/// Precondition: dataset cannot be empty
	/// Postcondition: returns the first value in the sorted dataset
	double getMin() const {
		if (!dataLoaded) return 0;
		return dataset.getPos(0);
	
	}//end getMin

	//##########################################################################################################
	// getMax() const : double								
	// Completed: [Y] []	Reviewed: [Y] []	Tested [Y][1]
	//##########################################################################################################

	/// Precondition: dataset cannot be empty
	/// Postcondition: returns the last value in the sorted dataset
	double getMax() const {
		if (!dataLoaded) return 0;
		return (dataset.getPos(dataset.getSize() - 1));
	
	}//end getMax

	//##########################################################################################################
	// getRange() const : double							
	// Completed: [Y] []	Reviewed: [Y] []	Tested [Y][1]
	//##########################################################################################################

	// [Requires]: getMax(), getMin()
	/// Precondition: dataset cannot be empty
	/// Postcondition: returns the range from the highest to the lowest values in the dataset
	double getRange() const {
		if (!dataLoaded) return 0;
		return (this->getMax()) - (this->getMin());
	
	}//end getRange

	//##########################################################################################################
	// getSum() const : double								
	// Completed: [Y] []	Reviewed: [Y] []	Tested [Y][1]
	//##########################################################################################################


	/// Precondition: dataset cannot be empty
	/// Postcondition: returns the sum of all the values in 
	double getSum() const {
		if (!dataLoaded) return 0;
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
	// getSize() const: int									
	// Completed: [Y] []	Reviewed: [Y] []	Tested [Y][1]
	//##########################################################################################################

	/// Precondition: dataset must be instatiated
	/// Postcondition: Returns the size of the dataset
	int getSize() const {
		if (!dataLoaded) return 0;
		return dataset.getSize();
	
	}//end getSize

	//##########################################################################################################
	// getMean() const : double								
	// Completed: [Y] []	Reviewed: [Y] []	Tested [Y][1]
	//##########################################################################################################


	// [Requires]: getSum(), getSize()
	/// Precondition: dataset cannot be empty
	/// Postcondition: Returns the average ( mean ) sum / size
	double getMean() const {
		if (!dataLoaded) return 0;
		return ( (getSum()) / (this->getSize()) );
	
	}//end getMean

	//##########################################################################################################
	// getMedian() const : double							
	// Completed: [Y] []	Reviewed: [Y] []	Tested [Y][1]
	//##########################################################################################################


	/// Precondition: dataset cannot be empty
	/// Postcondition: If the size of the dataset is
	///					 odd then, the middle index is the median.
	///					 even then, the median is the average of the two middle values  
	double getMedian() const {
		if (!dataLoaded) return 0;
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
	// getFrequencies() const : pair						
	// Completed: [Y] []	Reviewed: [Y] []	Tested [Y][1]
	//##########################################################################################################

	
	/// Precondition: dataset cannot be empty
	/// Postcondition: Returns a ( pair ) containing a ( map ) with the frequencies and a ( vector ) filled with the unique values of the dataset
	std::pair<map<double, int>, vector<double>> getFrequecies() const {
		if (!dataLoaded) return std::pair<map<double, int>, vector<double>>();
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

		return std::pair<map<double, int>, vector<double>>(frequencies, unique_values);
	}//end getFrequencies

	//##########################################################################################################
	// displayFrequencies() : void							
	// Completed: [Y] []	Reviewed: [Y] []	Tested [Y][1]
	//##########################################################################################################
	
	// [Requires]: displayFrequencies()
	/// Precondition: N/A
	/// Postcondition: Prints out the frequencies of every value of the dataset in a formatted manner
	void displayFrequencies() const {
		if (!dataLoaded) return;
		map<double, int> freq = getFrequecies().first;
		vector<double> keys = getFrequecies().second;
		string frequency = string();
		//end initialization
		
		//prints frequency table
		printf("\t\t\tFrequency Table\n");
		printf("\t\t\t%10s %10s %15s \n", "Value", "Frequency", " Frequency %");
		for (double value : keys) {
			int percent = static_cast<int>(100 * ((static_cast<double>(freq.at(value))) / (static_cast<double>(this->getSize()))));
			printf("\t\t\t%10.2f %10i %13i \n", value, freq.at(value), percent);
		}//end for
	}//end 

	//##########################################################################################################
	// displayFrequenciesToFile(file : ofstream& ) : void							
	// Completed: [Y] []	Reviewed: [Y] []	Tested [Y][1]
	//##########################################################################################################
	
	// [Requires]: displayFrequencies()
	/// Precondition: N/A
	/// Postcondition: Prints out the frequencies of every value of the dataset in a formatted manner
	void displayFrequenciesToFile(fstream& file) const {
		if (!dataLoaded) return;
		map<double, int> freq = getFrequecies().first;
		vector<double> keys = getFrequecies().second;
		//end initialization

		//prints frequency table
		file << "\t" << setw(10) <<  "Value" << "Frequency" << setw(15) << " Frequency %\n";
		for (double value : keys) {
			int percent = static_cast<int>(100 * ((static_cast<double>(freq.at(value))) / (static_cast<double>(this->getSize()))));
			file << "\t" << setw(10) << value << freq.at(value) << setw(15) <<  percent << setw(5) << " %\n";
		}//end for
		file << "\n";
	}//end 




	//##########################################################################################################
	// getMode() const: vector								
	// Completed: [Y] []	Reviewed: [Y] []	Tested [Y][1]
	//##########################################################################################################

	// [Requires]: getMode()
	/// Precondition: datset cannot be empty and has a value which repeats more than once ( otherwise displays 'no mode' )
	/// Postcondition: Returns a vector containing any mode found in the data set
	// Possibly consider alternative to getMode/getFrequencies
	vector<double> getMode() const {
		if (!dataLoaded) return vector<double>();
		map<double, int> freq = getFrequecies().first;
		vector<double> keys = getFrequecies().second;
		vector<double> mode;
		bool aboveOne = false;
		//end initialization
		

		int highest_freq = int();
		for (double value : keys) {

			if (debug) { std::cout << "\n\t\t[DEBUG]: key value: " << value << "\t[DEBUG]: frequency: " << freq.at(value); }
			
			if (freq.at(value) > (aboveOne)? 1: 0) {//if frequency greater than 1
				
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
	// displayMode() const : void								
	// Completed: [Y] []	Reviewed: [Y] []	Tested [Y][1]
	//##########################################################################################################


	/// Precondition: display is a boolean whether to display the mode to the screen or just silently deliver it as a string
	/// Postcondition:  returns mode(s) as a string
	string displayMode(bool display = true) const {
		if (!dataLoaded) return "";
		string modeStr = string("");
		//end initialization

		if (this->getMode().empty()) {
			modeStr = "{no mode} ";
			printf("\t\t\t%-25s = %s","Mode",  "no mode\n");
		}//end if
		
		else {
			for (double mode : this->getMode()) {
				modeStr += to_string(mode) + ",";
			}//end for

			if (display) {

				printf("\t\t\t%-25s \t\t= ", "Mode");
				for (double mode : this->getMode()) {
					printf("%.f", mode);
					if (this->getMode()[this->getMode().size() - 1] == mode) {
						continue;
					}//end if
					else {
						printf(", ");
					}//end else

				}//end for
			}//end if
		}//end else

		return modeStr.substr(modeStr.length() - 2);//cuts of last character
	
	}//end displayMode



	//##########################################################################################################
	// displayModeToFIle(file: FILE*) const: void								
	// Completed: [Y] []	Reviewed: [Y] []	Tested [Y][1]
	//##########################################################################################################


	void displayModeToFile(fstream& file) const {
		if (!dataLoaded) return;
		if (this->getMode().empty()) {
			file << setw(25) << left << "Mode" << right << "= no mode\n";
		}//end if
		else {
			file << setw(25) << left << "Mode" << right << "=" << left ;
			for (double mode : this->getMode()) {
				file <<  mode;
				if (this->getMode()[this->getMode().size() - 1] == mode) {
					continue;
				}//end if
				else {
					file << setw(2)  << ", " << left;
				}//end else

			}//end for
			file << "\n";
		}//end else

	
	}//end displayMode
	


	//##########################################################################################################
	// getStandardDeviation() const : double				
	// Completed: [Y] []	Reviewed: [Y] []	Tested [Y][1]
	//##########################################################################################################

	// Standard Deviation
	//		Standard deviation is a measure of dispersion of data values from the mean.
	//		The formula for standard deviation is the square root of the sum of squared differences from the mean divided by the size of the data set.
	//

	// [Requires]: getSize(), getMean()
	/// Precondition: dataset cannot be empty
	/// Postcondition: Returns the standard deviation as defined [below] 
	///																	Standard deviation is a measure of dispersion of data values from the mean.
	///																	The formula for standard deviation is the square root of the sum of squared differences from the mean divided by the size of the data set.
	double getStandardDeviation() const {
		if (!dataLoaded) return 0;
		double sum = double();

		for (int i = 0; i < this->getSize(); i++) {
			if (debug) { std::cout << "\n[DEBUG]: " << dataset[i] << " - " << this->getMean() << "\n"; }
			sum += pow((dataset[i] - (this->getMean())), 2.0);

		}//end for

		return sqrt( (sum) / static_cast<double>( (this->getSize() - 1) ) )  ;

	}//end getStandardDeviation

	//##########################################################################################################
	// getVariance() const : double							
	// Completed: [Y] []	Reviewed: [Y] []	Tested [Y][1]
	//##########################################################################################################
	
	// [Requires]: getSize()
	/// Precondition: dataset cannot be empty
	/// Postcondition: Returns the variance of the datset as defined by the definition [below]
	///																    Variance measures dispersion of data from the mean. 
	///																	The formula for variance is the sum of squared differences from the mean divided by the size of the data set.
	/// Note: the Variance is the standard Deviation ^2
	double getVariance() const {
		if (!dataLoaded) return 0;
		double sum = double();

		for (int i = 0; i < this->getSize(); i++)
			sum += pow((dataset[i] - (this->getMean())), 2.0);


		return sum / static_cast<double>((this->getSize() - 1));

	}//end getVariance

	//##########################################################################################################
	// getMidRange() const : double							
	// Completed: [Y] []	Reviewed: [Y] []	Tested [Y][1]
	//##########################################################################################################

	// [Requires]: getMax(), getMin()
	/// Precondition: dataset cannot be empty
	/// Postcondition: Returns the average of the sum of the max and min
	double getMidRange() const {
		if (!dataLoaded) return 0;

		return (this->getMax() + this->getMin()) / 2.0;

	}//end getQuartiles

	//##########################################################################################################
	// getMedianN() const : double				
	// Completed: [Y] []	Reviewed: [Y] []	Tested [Y][1]
	//##########################################################################################################

	
	/// Precondition: set is a LinkTList<double> containing a set to find the median of.
	/// Postcondition: Returns the median of set
	double getMedianN(LinkTList<double> set) const {
		if (!dataLoaded) return 0;
		bool isOdd = (set.getSize() % 2) != 0;								//boolean for better readibility
		int pos = int();														//int holding position of median
		//end initialization

		if (isOdd) {

			pos = (set.getSize() / 2);
			//pos--;//to account for 1 to 0 shift
			return set[pos];

		}//end if
		else {

			double total = set[(set.getSize() / 2)] + set[(set.getSize() / 2) - 1];
			return total / 2.0;

		}//end else	
	}//end getMedian


	//##########################################################################################################
	// getQuartiles() const : double				
	// Completed: [Y] []	Reviewed: [Y] []	Tested [Y][1]									
	//##########################################################################################################

	//possible logical error may need revising

	// [Requires]: getMedian(), getMedianN(), dataset
	/// Precondition: dataset cannot be empty and should be of 4 or greater
	/// Postcondition: Returns a pointer with the value [make sure to deallocate] of an array carrying the 3 quartiles which break up the dataset into 4 sections
	double* getQuartiles() const {
		if (!dataLoaded) return nullptr;
		double* quartile = new double[3];
		//end initialization
		
		quartile[1] = this->getMedian();
		auto qHalf = dataset.split(quartile[1]);
		quartile[0] = getMedianN(qHalf.first);
		quartile[2] = getMedianN(qHalf.second);
		return quartile;
		
	}//end getQuartiles

	
	/// Precondition: Dataset cannot be empty
	/// Postcondition: displays Quartile data to the screen
	void displayQuartiles() const {
		if (!dataLoaded) return;
		double* quartiles = this->getQuartiles();
		bool unknownLower = false;
		//end initialization
		
		if (this->getSize() <= 3) {
			std::cout << "\n\t\tWarning: Quartile 1 and Quartile 3 don't have enough data to produce an accurate result\b\a\n";
			unknownLower = true;
		}

		printf("\t\t\tQuartiles\n");
		for (int i = 0; i < 3; i++) {
			if (unknownLower) {
				if (i == 0 || i == 2) {
					printf("\t\t\t\tQ%i %s \n", (i + 1), "-->Unknown");
				}
				else
					printf("\t\t\t\tQ%i %s %f \n", (i + 1), "-->", quartiles[i]);

			}else
			printf( "\t\t\tQ%i %s %f \n", (i + 1),  "-->", quartiles[i]);
		}//end for
		delete[] quartiles;
	}//end displayQuartile



	void displayQuartilesToFile(fstream& file) const {
		if (!dataLoaded) return;
		double* quartiles = this->getQuartiles();
		bool unknownLower = false;
		//end initialization

		if (this->getSize() <= 3) {
			std::cout << "\n\t\tWarning: Quartile 1 and Quartile 3 don't have enough data to produce an accurate result\b\a\n";
			unknownLower = true;
		}


		for (int i = 0; i < 3; i++) {
			if (unknownLower) {
				if (i == 0 || i == 2) {
					file << "Q"  << (i + 1) << "-->Unknown" << "\n";
				}else
					file << "Q" << (i + 1) << "-->" << quartiles[i] << "\n";
			}else
			file << "Q" << (i + 1) <<   "-->" <<  quartiles[i] << "\n";
		}//end for
		delete[] quartiles;
		
	}//end displayQuartile

	//##########################################################################################################
	// getInterQuartileRange() const : double											
	// Completed: [Y] []	Reviewed: [Y] []	Tested [Y][1]
	//##########################################################################################################

	// [Requires]: getQuartiles()
	/// Precondition: dataset cannot be empty
	/// Postcondition: returns the interQuartileRange, which is Q3 - Q1
	double getInterQuartileRange() const {
		if (!dataLoaded) return 0;
		if (this->getSize() <= 3) {
			std::cout << "\n\t\tWarning: Quartile 1 and Quartile 3 don't have enough data to produce an accurate result\b\a\n";
		}

		double* quartiles = this->getQuartiles();
		
		return quartiles[2] - quartiles[0];

	}//end getInterQuartileRange

	//##########################################################################################################
	// getOutlier() const : double							
	// Completed: [Y] []	Reviewed: [Y] []	Tested [Y][1]
	//##########################################################################################################

	// [Requires]: getQuartiles(), getInterQuartileRange(), dataset
	/// Precondition: dataset cannot be empty
	/// Postcondition: returns a vector containing possible outlier candidates
	vector<double> getOutliers() const{
		if (!dataLoaded) return vector<double>();
		double* quartiles = this->getQuartiles();
		const double FENCERANGE = 1.5 * (this->getInterQuartileRange());
		double upperFence = ( quartiles[2] + FENCERANGE );
		double lowerFence = ( quartiles[0] - FENCERANGE );
		vector<double> outliers;
		//end initialization

		if (this->getSize() <= 3) {
			std::cout << "\n\t\tWarning: Quartile 1 and Quartile 3 don't have enough data to produce an accurate result\b\a\n";
		}


		for (int i = 0; i < dataset.getSize(); i++) {
			if (dataset.getPos(i) < lowerFence || dataset.getPos(i) > upperFence) {
				outliers.push_back(dataset.getPos(i));
			}//end if

		}//end for

		delete[] quartiles;
		return outliers;

	}//end getOutliers

	void displayOutliers() const {
		if (!dataLoaded) return;
		vector<double> outliers = this->getOutliers();
		
		printf("\t\t\t%-50s = ", "Outliers");
		for (double value : outliers) {
			if (this->getOutliers()[this->getOutliers().size() - 1] == value) {
				printf("%f", value);
			}else
				printf("%f,", value);
			
		}//end for

	}//end displayOutliers	
	
	
	void displayOutliersToFile(fstream& file) const {
		if (!dataLoaded) return;
		vector<double> outliers = this->getOutliers();
		
		file << setw(25) << left << "Outliers"<< right << "= " << left;
		for (double value : outliers) {
			if (this->getOutliers()[this->getOutliers().size() - 1] == value) {
				file << value;
			}else
				file << setw(2) << "," << setw(25) << value;
			
		}//end for
		file << "\n";
	}//end displayOutliers

	//##########################################################################################################
	// getSumOfSquares() const : double						
	// Completed: [Y] []	Reviewed: [Y] []	Tested [Y][1]
	//##########################################################################################################

	// [Requires]: getMean(), getSize()
	/// Precondition: dataset cannot be empty
	/// Postcondition: returns the sum of the difference between each datavalue and the mean squared.
	double getSumOfSquares() const {
		if (!dataLoaded) return 0;
		double sum = double();
		//end initialization

		for (int i = 0; i < this->getSize(); i++)
			sum += pow((dataset[i] - (this->getMean())), 2.0);

		
		return sum;

	}//end getSumOfSquare

	//##########################################################################################################
	// getMeanAbsoluteDeviation() const : double			
	// Completed: [Y] []	Reviewed: [Y] []	Tested [Y][1]
	//##########################################################################################################

	// [Requires]: getMean(), getSize()
	/// Precondition:
	/// Postcondition:
	double getMeanAbsoluteDeviation() const {
		if (!dataLoaded) return 0;

		double sum = double();

		for (int i = 0; i < this->getSize(); i++)
			sum += abs((dataset[i] - (this->getMean())));


		return sum / static_cast<double>(this->getSize());

	}//end getMeanAbsoluteDeviation


	//##########################################################################################################
	// getRootMeanSquare() const : double					
	// Completed: [Y] []	Reviewed: [Y] []	Tested [Y][1]
	//##########################################################################################################

	/// Precondition:
	/// Postcondition:
	double getRootMeanSquare() const{
		if (!dataLoaded) return 0;


		double sum = double();

		for (int i = 0; i < this->getSize(); i++)
			sum += pow((dataset[i]), 2.0);


		return sqrt(sum / static_cast<double>(this->getSize()));

	}//end getRootMeanSquare

	//##########################################################################################################
	// getStandardErrorOfTheMean() const : double			
	// Completed: [Y] []	Reviewed: [Y] []	Tested [Y][1]
	//##########################################################################################################

	/// Precondition:
	/// Postcondition:
	double getStandardErrorOfTheMean() const {
		if (!dataLoaded) return 0;
		return (this->getStandardDeviation()) / (sqrt(this->getSize()));

	}//end getStandardErrorOfTheMean

	//##########################################################################################################
	// getCoeffecientOfVariation() const : double			
	// Completed: [Y] []	Reviewed: [Y] []	Tested [Y][1]
	//##########################################################################################################

	/// Precondition:
	/// Postcondition:
	double getCoefficiantOfVariation() const{
		if (!dataLoaded) return 0;
		return (this->getStandardDeviation())/(this->getMean());

	}//end getCoeffecientOfVariation

	
	//##########################################################################################################
	// getRelativeStandardDeviation() const : double		
	// Completed: [Y] []	Reviewed: [Y] []	Tested [Y][1]
	//##########################################################################################################


	/// Precondition: dataset cannot be empty
	/// Postcondition: Returns the standard deviation * 100 divided by the mean
	double getRelativeStandardDeviation() const {
		if (!dataLoaded) return 0;
		return ((this->getStandardDeviation() * 100.00) / this->getMean());

	}//end getRelativeStandardDeviation




	//##########################################################################################################
	//  operator<<(strm : iostream&, const obj : DescriptiveStatistics&) : iostream		
	// Completed: [Y] []	Reviewed: [Y] []	Tested [Y][1]
	//##########################################################################################################



	void displayAllToFile() {
		
		
		
		if (!dataLoaded) {
			std::cout << "ERROR: NO DATA FILE LOADED \b\n";
			return;
		}

		std::cout << "\t\t\t" << dataset.print() << "\n";
		std::cout << "\t\t\t" << setw(50) << left << "Minimum" << right << "= " << setw(25) << this->getMin() << "\n";
		std::cout << "\t\t\t" << setw(50) << left << "Maximum" << right << "= " << setw(25) << this->getMax() << "\n";
		std::cout << "\t\t\t" << setw(50) << left << "Range" << right << "= " << setw(25) << this->getRange() << "\n";
		std::cout << "\t\t\t" << setw(50) << left << "Size" << right << "= " << setw(25) << this->getSize() << "\n";
		std::cout << "\t\t\t" << setw(50) << left << "Sum" << right << "= " << setw(25) << this->getSum() << "\n";
		std::cout << "\t\t\t" << setw(50) << left << "Mean" << right << "= " << setw(25) << this->getMean() << "\n";
		std::cout << "\t\t\t" << setw(50) << left << "Median" << right << "= " << setw(25) << this->getMedian() << "\n";
		this->displayFrequencies();
		this->displayMode();
		std::cout << "\n\t\t\t" << setw(50) << left << "Standard Deviation" << right << "= " << setw(25) << this->getStandardDeviation() << "\n";
		std::cout << "\t\t\t" << setw(50) << left << "Varaince" << right << "= " << setw(25) << this->getVariance() << "\n";
		std::cout << "\t\t\t" << setw(50) << left << "MidRange" << right << "= " << setw(25) << this->getMidRange() << "\n";
		this->displayQuartiles();
		std::cout << "\t\t\t" << setw(50) << left << "InterQuartile Range" << right << "= " << setw(25) << this->getInterQuartileRange() << "\n";
		this->displayOutliers();
		std::cout << "\n\t\t\t" << setw(50) << left << "Sum of Squares" << right << "= " << setw(25) << this->getSumOfSquares() << "\n";
		std::cout << "\t\t\t" << setw(50) << left << "Mean Absolute Deviation" << right << "= " << setw(25) << this->getMeanAbsoluteDeviation() << "\n";
		std::cout << "\t\t\t" << setw(50) << left << "Root Mean Square" << right << "= " << setw(25) << this->getRootMeanSquare() << "\n";
		std::cout << "\t\t\t" << setw(50) << left << "Standard Error of the Mean" << right << "= " << setw(25) << this->getStandardErrorOfTheMean() << "\n";
		std::cout << "\t\t\t" << setw(50) << left << "Coeffeciant of Variation" << right << "= " << setw(25) << this->getCoefficiantOfVariation() << "\n";
		std::cout << "\t\t\t" << setw(50) << left << "Relative Standard Deviation" << right << "= " << setw(25) << this->getRelativeStandardDeviation() << "\n";

		string outputFile = inputString("\n\t\t\tPlease enter an output filename: ", false);
		fstream file = fstream(outputFile, ios::out);


		file << "\nDescriptive Analysis\n";
		file << "\t\t\t" << dataset.print();
		file << setw(25) << left << "Minimum" << "\t" << right << "= " << setw(25) << left << this->getMin() << "\n";
		file << setw(25) << left << "Maximum" << "\t" << right << "= " << setw(25) << left << this->getMax() << "\n";
		file << setw(25) << left << "Range" << "\t" << right << "= " << setw(25) << left << this->getRange() << "\n";
		file << setw(25) << left << "Size" << "\t" << right << "= " << setw(25) << left << this->getSize() << "\n";
		file << setw(25) << left << "Sum" << "\t" << right << "= " << setw(25) << left << this->getSum() << "\n";
		file << setw(25) << left << "Mean" << "\t" << right << "= " << setw(25) << left << this->getMean() << "\n";
		file << setw(25) << left << "Median" << "\t" << right << "= " << setw(25) << left << this->getMedian() << "\n";
		this->displayFrequenciesToFile(file);
		this->displayModeToFile(file);

		file << setw(25) << left << "Standard Deviation" << "\t" << right << "= " << setw(25) << left << this->getStandardDeviation() << "\n";
		file << setw(25) << left << "Varaince" << "\t" << right << "= " << setw(25) << left << this->getVariance() << "\n";
		file << setw(25) << left << "MidRange" << "\t" << right << "= " << setw(25) << left << this->getMidRange() << "\n";
		this->displayQuartilesToFile(file);
		file << setw(25) << left << "InterQuartile Range" << "\t" << right << "=" << setw(25) << left << this->getInterQuartileRange()<< "\n";

		this->displayOutliersToFile(file);
		file << setw(25) << left << "Sum of Squares" << "\t" << right << "= " << setw(25) << left << this->getSumOfSquares() << "\n";
		file << setw(25) << left << "Mean Absolute Deviation" << "\t" << right << "= " << setw(25) << left << this->getMeanAbsoluteDeviation() << "\n";
		file << setw(25) << left << "Root Mean Square" << right << "\t" << "= " << setw(25) << left << this->getRootMeanSquare() << "\n";
		file << setw(25) << left << "Standard Error of the Mean" << "\t" << right << "= " << setw(25) << left << this->getStandardErrorOfTheMean() << "\n";
		file << setw(25) << left << "Coeffeciant of Variation" << "\t" << right << "= " << setw(25) << left << this->getCoefficiantOfVariation() << "\n";
		file << setw(25) << left << "Relative Standard Deviaition" << "\t" << right << "=" << setw(25) << left << this->getRelativeStandardDeviation() << "\n";
				
		file.close();

	}//end 



};//end class Descriptive Statistics

// Note: possibly change name of function.
/// Precondition:
/// Postcondition:
void runDescriptiveStatistics() {

	DescriptiveStatistics desc = DescriptiveStatistics(false);

	do {
		switch (menuDS()) {
			case '0': return; break;


			//#######################################################################################################################
			// Option A : Read													
			// Completed: [Y] []	Reviewed: [Y] []
			//#######################################################################################################################
			

			case 'A': {//Read
				
				string filename = inputString("Enter a data file name: ", false);
				desc.read(filename);
				break; 
			
			}//end case A

			//#######################################################################################################################
			// Option B : Min													
			// Completed: [Y] []	Reviewed: [Y] []
			//#######################################################################################################################

			case 'B': {//min
				if (desc.getLoaded() == false) {
					std::cout << "\nERROR: No data loaded, please load data in option A\n";
					break;
				}//end if
				printf("\t\t\t%-25s = %-25.f\n","Minimum", desc.getMin());
				//std::cout << desc.getMin();
				break; 
			
			}//end case B

			//#######################################################################################################################
			// Option C : Max													
			// Completed: [Y] []	Reviewed: [Y] []
			//#######################################################################################################################

			case 'C': {//max
				if (desc.getLoaded() == false) {
					std::cout << "\nERROR: No data loaded, please load data in option A\n";
					break;
				}//end if
				printf("\t\t\t%-25s = %-25.f\n", "Maximum", desc.getMax());
				//std::cout << desc.getMax();
				break; 
			
			}//end case C

			//#######################################################################################################################
			// Option D : Range													
			// Completed: [Y] []	Reviewed: [Y] []
			//#######################################################################################################################

			case 'D': {//range
				if (desc.getLoaded() == false) {
					std::cout << "\nERROR: No data loaded, please load data in option A\n";
					break;
				}//end if
				printf("\t\t\t%-25s = %-25.f\n", "Range", desc.getRange());
				//std::cout << desc.getRange();
				break;
			
			}//end case D

			//#######################################################################################################################
			// Option E : Size													
			// Completed: [Y] []	Reviewed: [Y] []
			//#######################################################################################################################

			case 'E': {//size
				if (desc.getLoaded() == false) {
					std::cout << "\nERROR: No data loaded, please load data in option A\n";
					break;
				}//end if
				printf("\t\t\t%-25s = %-25i\n", "Size", desc.getSize());
				//std::cout << desc.getSize(); 
				break; 
			
			}//end case E

			//#######################################################################################################################
			// Option F : Sum													
			// Completed: [Y] []	Reviewed: [Y] []
			//#######################################################################################################################

			case 'F': {//sum
				if (desc.getLoaded() == false) {
					std::cout << "\nERROR: No data loaded, please load data in option A\n";
					break;
				}//end if
				printf("\t\t\t%-25s = %-25.f\n", "Sum", desc.getSum());
				//std::cout << desc.getSum();
				break; 
			
			}//end case F

			//#######################################################################################################################
			// Option G : Mean													
			// Completed: [Y] []	Reviewed: [Y] []
			//#######################################################################################################################

			case 'G': {//mean
				if (desc.getLoaded() == false) {
					std::cout << "\nERROR: No data loaded, please load data in option A\n";
					break;
				}//end if
				printf("\t\t\t%-25s = %-25f\n", "Mean", desc.getMean());
				//std::cout << desc.getMean();
				break; 
			
			}//end case G

			//#######################################################################################################################
			// Option H : Median												
			// Completed: [Y] []	Reviewed: [Y] []
			//#######################################################################################################################

			case 'H': {//median 
				if (desc.getLoaded() == false) {
					std::cout << "\nERROR: No data loaded, please load data in option A\n";
					break;
				}//end if
				printf("\t\t\t%-25s = %-25f\n", "Median", desc.getMedian());
				//std::cout << desc.getMedian();
				break; 
			
			}//end case H

			//#######################################################################################################################
			// Option I : Display Frequencies									
			// Completed: [Y] []	Reviewed: [Y] []
			//#######################################################################################################################

			case 'I': {//display frequencies
				if (desc.getLoaded() == false) {
					std::cout << "\nERROR: No data loaded, please load data in option A\n";
					break;
				}//end if
				desc.displayFrequencies();
				break;
			
			}//end case I

			//#######################################################################################################################
			// Option J : Mode													
			// Completed: [Y] []	Reviewed: [Y] []
			//#######################################################################################################################

			case 'J': {//mode
				if (desc.getLoaded() == false) {
					std::cout << "\nERROR: No data loaded, please load data in option A\n";
					break;
				}//end if
				desc.displayMode();
				break;
			
			}//end case J


			//#######################################################################################################################
			// Option K : Standard Deviation									
			// Completed: [Y] []	Reviewed: [Y] []
			//#######################################################################################################################


			case 'K': {//standard deviation
				if (desc.getLoaded() == false) {
					std::cout << "\nERROR: No data loaded, please load data in option A\n";
					break;
				}//end if
				printf("\t\t\t%-25s = %-25f\n", "Standard Deviation", desc.getStandardDeviation());
				//std::cout << desc.getStandardDeviation();
				break;
			
			}//end case K


			//#######################################################################################################################
			// Option L : Varaince												
			// Completed: [Y] []	Reviewed: [Y] []
			//#######################################################################################################################


			case 'L': {//varaince
				if (desc.getLoaded() == false) {
					std::cout << "\nERROR: No data loaded, please load data in option A\n";
					break;
				}//end if
				printf("\t\t\t%-25s = %-25f\n", "Varaince", desc.getVariance());
				//std::cout << desc.getVariance();
				break;
			
			}//end case L

			//#######################################################################################################################
			// Option M : Mid range												
			// Completed: [Y] []	Reviewed: [Y] []
			//#######################################################################################################################


			case 'M': {//mid range
				if (desc.getLoaded() == false) {
					std::cout << "\nERROR: No data loaded, please load data in option A\n";
					break;
				}//end if
				printf("\t\t\t%-25s = %-25f\n", "Mid Range", desc.getMidRange());
				//std::cout << desc.getMidRange();
				break;
			
			}//end case M

			//#######################################################################################################################
			// Option N : Quartiles												
			// Completed: [Y] []	Reviewed: [Y] []
			//#######################################################################################################################

			case 'N': {//Quartiles
				if (desc.getLoaded() == false) {
					std::cout << "\nERROR: No data loaded, please load data in option A\n";
					break;
				}//end if
				desc.displayQuartiles();
				break;
			
			}//end case N

			//#######################################################################################################################
			// Option O : InterQuartile Range									
			// Completed: [Y] []	Reviewed: [Y] []
			//#######################################################################################################################

			case 'O': {//interquartile range
				if (desc.getLoaded() == false) {
					std::cout << "\nERROR: No data loaded, please load data in option A\n";
					break;
				}//end if
				printf("\t\t\t%-25s = %-25f\n", "Interquartile Range", desc.getInterQuartileRange());
				//std::cout << desc.getInterQuartileRange()<<"\n";
				break;
			
			}//end case O

			//#######################################################################################################################
			// Option P : Outliers												
			// Completed: [Y] []	Reviewed: [Y] []
			//#######################################################################################################################

			case 'P': {//Outliers
				if (desc.getLoaded() == false) {
					std::cout << "\nERROR: No data loaded, please load data in option A\n";
					break;
				}//end if
				desc.displayOutliers();
				break;
			
			}//end case P

			//#######################################################################################################################
			// Option Q : Sum of Squares										
			// Completed: [Y] [d]	Reviewed: [Y] []
			//#######################################################################################################################

			case 'Q': {//sum of squares
				if (desc.getLoaded() == false) {
					std::cout << "\nERROR: No data loaded, please load data in option A\n";
					break;
				}//end if
				printf("\t\t\t%-25s = %-25f\n", "Sum of Squares", desc.getSumOfSquares());
				std::cout << desc.getSumOfSquares();
				break;
			
			}//end case Q

			//#######################################################################################################################
			// Option R : Mean Absolute Deviation								
			// Completed: [Y] []	Reviewed: [Y] []
			//#######################################################################################################################

			case 'R': {//Mean Absolute Deviation
				if (desc.getLoaded() == false) {
					std::cout << "\nERROR: No data loaded, please load data in option A\n";
					break;
				}//end if
				printf("\t\t\t%-25s = %-25f\n", "Mean Absolute Deviation", desc.getMeanAbsoluteDeviation());
				//std::cout << desc.getMeanAbsoluteDeviation();
				break;
			
			}//end case R

			//#######################################################################################################################
			// Option S : Root Mean Square										
			// Completed: [Y] []	Reviewed: [Y] []
			//#######################################################################################################################

			case 'S': {//Root Mean Square
				if (desc.getLoaded() == false) {
					std::cout << "\nERROR: No data loaded, please load data in option A\n";
					break;
				}//end if
				printf("\t\t\t%-25s = %-25f\n", "Root Mean Square", desc.getRootMeanSquare());
				std::cout << desc.getRootMeanSquare();
				break;
			
			}//end case S

			//#######################################################################################################################
			// Option T : Standard Error of the Mean							
			// Completed: [Y] []	Reviewed: [Y] []
			//#######################################################################################################################

			case 'T': {//Standard Error of the Mean
				if (desc.getLoaded() == false) {
					std::cout << "\nERROR: No data loaded, please load data in option A\n";
					break;
				}//end if
				printf("\t\t\t%-25s = %-25f\n", "Standard Error of the Mean", desc.getStandardErrorOfTheMean());
				//std::cout << desc.getStandardErrorOfTheMean();
				break;
			
			}//end case T


			//#######################################################################################################################
			// Option U : Coefficient of Variation								
			// Completed: [Y] []	Reviewed: [Y] []
			//#######################################################################################################################


			case 'U': {// Coefficient of Variation
				if (desc.getLoaded() == false) {
					std::cout << "\nERROR: No data loaded, please load data in option A\n";
					break;
				}//end if
				printf("\t\t\t%-25s = %-25f\n", "Coeffitiant of Variation", desc.getCoefficiantOfVariation());
				//std::cout << desc.getCoeffitiantOfVariation();
				break;
			
			}//end case U

			//#######################################################################################################################
			// Option V : Relative Standard Deviation							
			// Completed: [Y] []	Reviewed: [Y] []
			//#######################################################################################################################

			case 'V': {//Relative Standard Deviation
				if (desc.getLoaded() == false) {
					std::cout << "\nERROR: No data loaded, please load data in option A\n";
					break;
				}//end if
				printf("\t\t\t%-25s = %-25f %%\n", "Relative Standard Deviation", desc.getRelativeStandardDeviation());
				//std::cout << desc.getRelativeStandardDeviation();
				break;
			
			}//end case V


			//#######################################################################################################################
			// Option W : Display all resultsand write to an output text file	
			// Completed: [Y] []	Reviewed: [Y] []
			//#######################################################################################################################


			case 'W': {//Display all resultsand write to an output text file
				if (desc.getLoaded() == false) {
					std::cout << "\nERROR: No data loaded, please load data in option A\n";
					break;
				}//end if
				desc.displayAllToFile();
				break;
			
			}//end case W


			//#######################################################################################################################
			// Invalid Option													
			// Completed: [Y] []	Reviewed: [Y] []
			//#######################################################################################################################

			default: { 

				std::cout << "\nInvalid option: Please select a option within the menu";
				break;
			
			}//end default

		}//end switch
		pause();
	} while (true);
	
}


