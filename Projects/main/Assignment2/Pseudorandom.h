#pragma once
#include <iostream>
#include <cmath>
#include <random>
using namespace std;

//class for pseudorandom generator
class Pseudorandom {
public:
	Pseudorandom(int seed, int multiplier, int increment, int modulus);
	int basicpseudorandom();
	void test1(int trial);
	void check();
	void giveseed();
	void test2randomset();
	void test2();
	double test2pseudorandom();
	void Gaussian_dist();
private:
	double a;
	int seed;
	static int multiplier;																//changed from nonstatic to static (bh)
	int increment;																		//consider changing from nonstatic to static (bh)
	int modulus;																		//consider changing from nonstatic to static (bh)
	int count = 0;
};

int Pseudorandom::multiplier = 3200;
//int Pseudorandom::increment = 3200;
//int Pseudorandom::modulus = 3200;
//consturctor call everything that should be shown, Test1: initialing seed, multiplier, increment and modulus before runing the generator 729 times
Pseudorandom::Pseudorandom(int a = 1, int b = 40, int c = 725, int d = 729) {
	seed = a;
	multiplier = b;																			
	increment = c;																				
	modulus = d;																				
	cout << "\ttest1 (pseudorandom):" << endl;
	giveseed();
	test1(729); cout << endl;
	cout << "\t\tGenerated random " << count << "different numbers." << endl;
	cout << endl;
	//Test 2 run 1 million test and the distrubution of the numbers
	cout << "\ttest2 (pseudorandom):" << endl;
	cout << endl;
	test2randomset();
	test2();
	//Gaussian distribution
	Gaussian_dist();
}

//the pseudorandom number generator
int Pseudorandom::basicpseudorandom() {
	return (multiplier * seed + increment) % modulus;
}


//test1.It take a int variable and run the generator that many times.
void Pseudorandom::test1(int trial) {
	//cout << seed << endl;
	for (int i = 0; i <= trial - 1; i++) {
		seed = basicpseudorandom();
		//cout << "seed " << i << " = " << seed << endl;
		count++;
	}
	//cout << "count = " << count << endl;
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

//function for setting random numbers to multipler, increment, modulus and setting seed2 to 1. Passing modulus's value to the double variable a
void Pseudorandom::test2randomset() {
	seed = 1;
	default_random_engine generator;
	//srand(time(0));
	//rand();//part of the cmath header
	uniform_int_distribution<int> distribution(1, 200);
	multiplier += distribution(generator);
	uniform_int_distribution<int> distribution2(10, 32000);
	increment = distribution2(generator);
	modulus = distribution2(generator);
	a = modulus;
	cout << "\t\tmultiplier = " << multiplier << ", increment = " << increment << ", modulus = " << modulus << ", and the new seed = " << seed << endl;
	cout << endl;
}

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
	seed = basicpseudorandom();
	return seed / a;
}

//part 3 finds the approximate Gaussian distribution
void Pseudorandom::Gaussian_dist() {
	//the 12 uniformly distributed rand number
	double n[12];
	for (int i = 0; i <= 11; i++) {
		n[i] = test2pseudorandom();
	}
	for (int i = 0; i <= 11; i++) {
		cout << n[i] << endl;
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
	for (int i = 0; i <= 11; i++) {
		cout << n[i] << endl;
	}
	//the calculation
	double median = n[5] + n[6] / 2;
	cout << median << endl;
	double sum = 0;
	for (int i = 0; i <= 11; i++) {
		sum = sum + n[1];
	}
	cout << sum << endl;
	double mean = sum / 12;
	double sdpart = 0;
	for (int i = 0; i <= 11; i++) {
		sdpart = sdpart + ((n[i] - mean) * (n[i] - mean));
	}
	double sd = sqrt(sdpart / 12);
	cout << sd << endl;
	double ans = median + (sum - 6) * sd;
	cout << "\t\tWith 12 uniformly distributed rand number in the range[0...1.0)," << endl;
	cout << "\t\tthe approximate Gaussian distribution is " << ans << endl;
	cout << endl;
}




void runPseudorandom() {
	Pseudorandom obj = Pseudorandom();
	//obj.test1();
	//obj.test2();

}