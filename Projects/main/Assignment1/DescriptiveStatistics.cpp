#pragma once
//
//
//
//

#include "Header1.h"
#include <fstream>
#include <vector>


int main() {//debugging main 
	


}//end main

/// 
/// menuDriver for DescriptiveStatistics
bool runDescriptiveStatistics() {



	return true;
}//end runDescriptiveStatistics

class DescriptiveStatistics {
private:

	string dataFile = string();
	bool dataLoaded = bool(false);
	LinkTList<double>* dataSet = nullptr;
	vector<double> vectorDataSet = vector<double>();

public:

	/// [Default Constructor]
	/// Postcondition: initializes dataset linkList
	DescriptiveStatistics() {

		dataset = new LinkTList<double>();
	}//end constructor

	~DescriptiveStatistics() {
		delete dataset;
	}

	/// Precondition:
	/// Postcondition:
	bool read();
	bool populate();
	void displaySet();
	void displayAllOut();
	double getMin();
	double getMax();
	double getRange();
	double getSize();
	double getSum();
	double getMean();
	double getMedian();
	double getFrequencies();
	double getMode();
	double getStandardDeviation();
	double getVariance();
	double getMidRange();
	double getQuartiles();
	double getInterQuartileRange();
	double getOutliers();
	double getSumOfSquares();
	double getMeanAbsoluteDeviation();
	double getRootMeanSquare();
	double getStandardErrorOfTheMean();
	double getCoeffecientOfVariation();
	double getRelativeStandardDeviation();




};