/// File: Pseudorandom.h
/// Class: CMPR 131
/// Team Members:
///	Thien Nguyen
//	Itz Rodriquez
//	Tony Cheng
//	Jose Chavez
//	Ben Halpern				
///					
///					
///




#pragma once
#include <iostream>
#include <cmath>
#include <random>
#include <ctime>
using namespace std;

//class for pseudorandom generator
class Pseudorandom {
public:

	/// Precondition:Take 4 possible int for the seed, multiplier, increment and modulus
	/// Postcondition: Create a Pseudorandom Class
	Pseudorandom(int initSeed, int initMultiplier, int initIncrement, int initModulus);

	/// Precondition:Takes an int for the multiplier value
	/// Postcondition:Return an int as the answer after running the equation
	int basicpseudorandom(int multi);

	/// Precondition: Takes an int for the number of trials
	/// Postcondition: runs basicpseudorandom for the given number of time and change the count according to the number of time that it has been ran
	void test1(int trial);

	/// Precondition: N/A
	/// Postcondition: Give the current seed, multiplier, increment and modulus
	void check();

	/// Precondition: N/A
	/// Postcondition: Give the current seed
	void giveseed();

	/// Precondition: N/A
	/// Postcondition: Return the count for how many times the basicpseudorandom has ran in test1
	int givecount();

	/// Precondition: N/A
	/// Postcondition: Randomize the seed, multiplier, increment and modulus for test 2
	void test2randomset();

	/// Precondition: Takes an int for the number of trials
	/// Postcondition: runs test2pseudorandom and display the result of numbers that occurs between each value
	void test2(int trial);

	/// Precondition: N/A
	/// Postcondition: return a double number created from basicpseudorandom divide by the modulus
	double test2pseudorandom();

	/// Precondition: N/A
	/// Postcondition: Generate 12 random number and find the approximate Gaussian distribution
	void Gaussian_dist(int gaussian_numbers);
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
	seed = 1;
	multiplier = 40;
	increment = 725;
	modulus = 729;
	countTest1 = 0;
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
void Pseudorandom::test2(int trial) {
	//tempory storage of the double variable
	double buffer = 0;
	//counting the 10 possible result ranges
	int choice1 = 0;
	int choice2 = 0;
	int choice3 = 0;
	int choice4 = 0;
	int choice5 = 0;
	int choice6 = 0;
	int choice7 = 0;
	int choice8 = 0;
	int choice9 = 0;
	int choice10 = 0;
	//run the test and collecting results
	for (int z = 1; z <= trial; z++) {
		buffer = test2pseudorandom();
		if (buffer >= 0 && buffer < .1) {
			choice1++;
		}
		else if (buffer >= .1 && buffer < .2) {
			choice2++;
		}
		else if (buffer >= .2 && buffer < .3) {
			choice3++;
		}
		else if (buffer >= .3 && buffer < .4) {
			choice4++;
		}
		else if (buffer >= .4 && buffer < .5) {
			choice5++;
		}
		else if (buffer >= .5 && buffer < .6) {
			choice6++;
		}
		else if (buffer >= .6 && buffer < .7) {
			choice7++;
		}
		else if (buffer >= .7 && buffer < .8) {
			choice8++;
		}
		else if (buffer >= .8 && buffer < .9) {
			choice9++;
		}
		else if (buffer >= .9 && buffer < 1) {
			choice10++;
		}
	}
	//displaying results
	cout << "\t\tRange           Number of" << endl;
	cout << "\t\t                Occurrences" << endl;
	cout << "\t\t[0.0 ... 0.1)   " << choice1 << endl;
	cout << "\t\t[0.1 ... 0.2)   " << choice2 << endl;
	cout << "\t\t[0.2 ... 0.3)   " << choice3 << endl;
	cout << "\t\t[0.3 ... 0.4)   " << choice4 << endl;
	cout << "\t\t[0.4 ... 0.5)   " << choice5 << endl;
	cout << "\t\t[0.5 ... 0.6)   " << choice6 << endl;
	cout << "\t\t[0.6 ... 0.7)   " << choice7 << endl;
	cout << "\t\t[0.7 ... 0.8)   " << choice8 << endl;
	cout << "\t\t[0.8 ... 0.9)   " << choice9 << endl;
	cout << "\t\t[0.9 ... 1.0)   " << choice10 << endl;
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
void Pseudorandom::Gaussian_dist(int gaussian_numbers) {
	//the 12 uniformly distributed rand number
	double randomGauss[12];
	for (int i = 0; i <= gaussian_numbers - 1; i++) {
		randomGauss[i] = test2pseudorandom();
	}
	//sort the array
	int i, j;
	double temp;
	for (i = 1; i <= gaussian_numbers - 1; i++)
	{
		temp = randomGauss[i];
		for (j = i - 1; (j >= 0) && (randomGauss[j] < temp); j--)
		{
			randomGauss[j + 1] = randomGauss[j];
		}
		randomGauss[j + 1] = temp;
	}
	//the calculation
	double median = ((randomGauss[5]) + (randomGauss[6])) / 2;
	//cout << median << endl;
	double sum = 0;
	for (int i = 0; i <= gaussian_numbers - 1; i++) {
		sum = sum + randomGauss[i];
	}
	//cout << sum << endl;
	double mean = sum / 12;
	double sdpart = 0;
	for (int i = 0; i <= gaussian_numbers - 1; i++) {
		sdpart = sdpart + ((randomGauss[i] - mean) * (randomGauss[i] - mean));
	}
	double sd = sqrt(sdpart / 12);
	//cout << sd << endl;
	double ans = median + (sum - 6) * sd;
	cout << "\t\tWith 12 uniformly distributed rand number in the range[0...1.0)," << endl;
	cout << "\t\tthe approximate Gaussian distribution is " << ans << endl;
	cout << endl;
}




//main driver function for the pseudorandom class
void runPseudorandom(Pseudorandom& test) {

	cout << endl;
	cout << "\t2> Pseudorandom Project" << endl;
	cout << endl;

	cout << "\ttest1 (pseudorandom):" << endl;
	test.giveseed();
	int test1trial = 729;
	test.test1(test1trial); cout << endl;
	int countTest1 = test.givecount();

	cout << "\t\tGenerated random " << countTest1 << "different numbers." << endl;
	cout << endl;

	//Test 2 run 1 million test and the distrubution of the numbers
	cout << "\ttest2 (pseudorandom):" << endl;
	cout << endl;
	int test2trial = 1000000;
	test.test2randomset();
	test.test2(test2trial);

	//Gaussian distribution
	int gaussian_numbers = 12;
	test.Gaussian_dist(gaussian_numbers);

}