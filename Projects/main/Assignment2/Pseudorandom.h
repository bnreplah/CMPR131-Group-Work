/// File:
/// Class:
/// Team Members:
///					
///					
///					
///
					
/**
* Value semantics:
*	< naming conventions used in the code > and how to use the class
* 
* 
* 
* 
* 
* 
*/




#pragma once
#include <iostream>
#include <cmath>
#include <random>
#include <ctime>
using namespace std;

//class for pseudorandom generator
class Pseudorandom {
public:

	/// 
	///
	Pseudorandom(int initSeed = 1, int initMultiplier = 40, int initIncrement = 725, int initModulus = 729);

	/// Precondition:
	/// Postcondition:
	int basicpseudorandom(int multi);

	/// Precondition:
	/// Postcondition:
	void test1(int trial);
	
	/// Precondition:
	/// Postcondition:
	void check();

	/// Precondition:
	/// Postcondition:
	void giveseed();

	/// Precondition:
	/// Postcondition:
	int givecount();

	/// Precondition:
	/// Postcondition:
	void test2randomset();

	/// Precondition:
	/// Postcondition:
	void test2();

	/// Precondition:
	/// Postcondition:
	double test2pseudorandom();
	
	/// Precondition:
	/// Postcondition:
	void Gaussian_dist();
private:
	double doubModulus;
	int seed;
	int multiplier;
	static int multiplierTest2;
	int increment;
	int modulus;
	int countTest1 = 0;
};
//implementation:

// Review
//
//


int Pseudorandom::multiplierTest2 = 500;
//consturctor call everything that should be shown, Test1: initialing seed, multiplier, increment and modulus before runing the generator 729 times
Pseudorandom::Pseudorandom(int initSeed = 1, int initMultiplier = 40, int initIncrement = 725, int initModulus = 729) {
	seed = initSeed;
	multiplier = initMultiplier;
	increment = initIncrement;
	modulus = initModulus;
}

//the pseudorandom number generator
int Pseudorandom::basicpseudorandom(int multi) {
	return (multi * seed + increment) % modulus;
}


//test1.It take a int variable and run the generator that many times.
void Pseudorandom::test1(int trial) {
	//cout << seed << endl;
	for (int i = 0; i <= trial - 1; i++) {
		seed = basicpseudorandom(multiplier);
		//cout << "seed " << i << " = " << seed << endl;
		countTest1++;
	}
	//cout << "countTest1 = " << countTest1 << endl;
}

//function for check what is the current seed, multiplier, increment and modulus
void Pseudorandom::check() {
	cout << "seed:" << seed << endl;
	cout << "multiplier:" << multiplier << endl;
	cout << "increment:" << increment << endl;
	cout << "modulus:" << modulus << endl;
}

//function for showing the seed
void Pseudorandom::giveseed() {
	cout << "\t\tSeed = " << seed << endl;
}

//function for showing the seed
int Pseudorandom::givecount() {
	return countTest1;
}

//function for setting random numbers to multipler, increment, modulus and setting seed2 to 1. Passing modulus's value to the double variable a
void Pseudorandom::test2randomset() {
	srand(time(NULL));
	seed = 1;
	const int lowerBound = 1;
	const int secLowerBound = 10;
	const int upperBound = 30;
	const int secUpperBound = 31989;

	//end initialization
	multiplierTest2 += rand() % upperBound + lowerBound;
	increment = rand() % secUpperBound + secLowerBound + 1;
	modulus = rand() % secUpperBound + secLowerBound + 1;
	doubModulus = modulus;
	cout << "\t\tmultiplier = " << multiplierTest2 << ", increment = " << increment << ", modulus = " << modulus << ", and the new seed = " << seed << endl;
	cout << endl;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HARD CODING< CHANGE >
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


//Running part 2 and displaying result of the number range
void Pseudorandom::test2() {
	//tempory storage of the double variable
	double buffer = 0;
	//counting the 10 possible result ranges
	int c1 = 0;
	int c2 = 0;
	int c3 = 0;
	int c4 = 0;
	int c5 = 0;
	int c6 = 0;
	int c7 = 0;
	int c8 = 0;
	int c9 = 0;
	int c10 = 0;
	//run the test and collecting results
	for (int z = 1; z <= 1000000; z++) {
		buffer = test2pseudorandom();
		if (buffer >= 0 && buffer < .1) {
			c1++;
		}
		else if (buffer >= .1 && buffer < .2) {
			c2++;
		}
		else if (buffer >= .2 && buffer < .3) {
			c3++;
		}
		else if (buffer >= .3 && buffer < .4) {
			c4++;
		}
		else if (buffer >= .4 && buffer < .5) {
			c5++;
		}
		else if (buffer >= .5 && buffer < .6) {
			c6++;
		}
		else if (buffer >= .6 && buffer < .7) {
			c7++;
		}
		else if (buffer >= .7 && buffer < .8) {
			c8++;
		}
		else if (buffer >= .8 && buffer < .9) {
			c9++;
		}
		else if (buffer >= .9 && buffer < 1) {
			c10++;
		}
	}
	//displaying results
	cout << "\t\tRange           Number of" << endl;
	cout << "\t\t                Occurrences" << endl;
	cout << "\t\t[0.0 ... 0.1)   " << c1 << endl;
	cout << "\t\t[0.1 ... 0.2)   " << c2 << endl;
	cout << "\t\t[0.2 ... 0.3)   " << c3 << endl;
	cout << "\t\t[0.3 ... 0.4)   " << c4 << endl;
	cout << "\t\t[0.4 ... 0.5)   " << c5 << endl;
	cout << "\t\t[0.5 ... 0.6)   " << c6 << endl;
	cout << "\t\t[0.6 ... 0.7)   " << c7 << endl;
	cout << "\t\t[0.7 ... 0.8)   " << c8 << endl;
	cout << "\t\t[0.8 ... 0.9)   " << c9 << endl;
	cout << "\t\t[0.9 ... 1.0)   " << c10 << endl;
	cout << endl;
}

//test 2 return the pseudorandom number divide by a (a double variable with the same value as modulus) as a double variable
double Pseudorandom::test2pseudorandom() {
	seed = basicpseudorandom(multiplierTest2);
	return seed / doubModulus;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HARD CODING< CHANGE >
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//part 3 finds the approximate Gaussian distribution
void Pseudorandom::Gaussian_dist() {
	//the 12 uniformly distributed rand number
	double n[12];
	for (int i = 0; i <= 11; i++) {
		n[i] = test2pseudorandom();
	}
	//sort the array
	int i, j;
	double temp;
	for (i = 1; i <= 11; i++)
	{
		temp = n[i];
		for (j = i - 1; (j >= 0) && (n[j] < temp); j--)
		{
			n[j + 1] = n[j];
		}
		n[j + 1] = temp;
	}
	//the calculation
	double median = (n[5] + n[6]) / 2;
	//cout << median << endl;
	double sum = 0;
	for (int i = 0; i <= 11; i++) {
		sum = sum + n[1];
	}
	//cout << sum << endl;
	double mean = sum / 12;
	double sd = .05;
	//cout << sd << endl;
	double ans = median + (sum - 6) * sd;
	cout << "\t\tWith 12 uniformly distributed rand number in the range[0...1.0)," << endl;
	cout << "\t\tthe approximate Gaussian distribution is " << ans << endl;
	cout << endl;
}




//main driver function for the pseudorandom class
void runPseudorandom(Pseudorandom &test) {

	cout << endl;
	cout << "\t2> Pseudorandom Project" << endl;
	cout << endl;

	cout << "\ttest1 (pseudorandom):" << endl;
	test.giveseed();
	test.test1(729); cout << endl;
	int countTest1 = test.givecount();
	
	cout << "\t\tGenerated random " << countTest1 << "different numbers." << endl;
	cout << endl;
	
	//Test 2 run 1 million test and the distrubution of the numbers
	cout << "\ttest2 (pseudorandom):" << endl;
	cout << endl;
	
	test.test2randomset();
	test.test2();
	
	//Gaussian distribution
	test.Gaussian_dist();


}//end runPseudorandom