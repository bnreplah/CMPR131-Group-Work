/// Jesus, Ben
/// Tony Cheng
///
///
///
///
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include "input.h"
#include <queue>


#pragma once
class CostcoLine {
private:
	queue<int>* cashRegister;
	int timer = 0;
	long int serveCustomerCount = 0;
	int registerAmount = 0;
	time_t *d_time;
public:
	///
	/// Constructor
	///
	CostcoLine() {
		d_time = new time_t();
	}
	/// Precondition: N/A
	/// Postcondition: Set int value for timer, amount of cashRegister, and customerTime via user's int input
	void SetUpSim() {
		timer = inputInteger("\n\tEnter the time (0..37800 in seconds) of the store will be operated:", 0, 37800);
		registerAmount = inputInteger("Enter the number of cash registers (1..10):", 1, 10);
		cashRegister = new queue<int>[registerAmount];
	}
	/// Precondition: N/A
	/// Postcondition: run the CostcoLine Simulation a certain amount of times
	void runSimCount() {
		srand(time(NULL));
		while (timer != 0) {
			addCustomer();
			displaySim();
			
			serveCustomer();
			timer--;
		}
	}
	/// Precondition: N/A
	/// Postcondition: run the CostcoLine Simulation for duration of time
	void runSimTime() {
		srand(time(NULL));
		int intiTime = (int)(time(d_time)) + timer;
		*d_time += timer;
		addCustomer();
		while ((int)((*d_time - time(0)) != 0)) {
			if( (int)((*d_time - time(0))) % (15 - registerAmount) == 0)//adds random number of customers every 3 seconds
				addCustomer();
			displaySim();
			serveCustomer();
			timer--;
		}
	}
	/// Precondition: N/A
	/// Postcondition: create customer with random amount of items an add them to the registers.
	void addCustomer() {
		
		int customerAdd = randCustomerCount();
		sortCustomer(customerAdd);
	}
	/// Precondition: N/A
	/// Postcondition: generate a value for how many customer to be add
	int randCustomerCount() {
		//return a value from 1 to 3
		return rand() % 3 + 1;
	}
	/// Precondition: N/A
	/// Postcondition: sort customer to each of the registers.
	void sortCustomer(int customerAmount) {
		int lowest = 0;
		for (int addedC = 0; addedC < customerAmount; addedC++) {
			for (int check = 0; check < registerAmount; check++) {
				if (cashRegister[check].size() < cashRegister[lowest].size()) {
					lowest = check;
				}
			}
			cashRegister[lowest].push(genCustomer());
		}
	}
	/// Precondition: N/A
	/// Postcondition: create a customer with random amount of items
	int genCustomer() {
		//return a value from 1 to 99
		return rand() % 99 + 1;
	}
	/// Precondition: N/A
	/// Postcondition: randomly serve customers and increase customer serve count
	void serveCustomer() {
		for (int rcount = 0; rcount < registerAmount; rcount++) {
			if (!cashRegister[rcount].empty()) {
				if (cashRegister[rcount].front() > 0)
					cashRegister[rcount].front()--;
				else
				{
					cashRegister[rcount].pop();
					serveCustomerCount++;
				}
			}//end if
		}
	}
	/// Precondition: N/A
	/// Postcondition: Print the visual display of the simulation
	void displaySim() {
		clrScrn();
		//cout << to_string(*d_time - time(0)) ;
		std::cout << "\n\tCostCo warehouse store: " + to_string(*d_time - time(0)) + "\t" + "Number of served customers: " + to_string(serveCustomerCount);
		std::cout << endl;
		for(int rcount = 0; rcount < registerAmount; rcount++) {
			std::cout << "\n\t\tCash register #" << to_string(rcount + 1) << ":";
			if (!cashRegister[rcount].empty()) {

				if (cashRegister[rcount].front() > 9) {
					std::cout << "\n\t\t\t\t" << char(254) << cashRegister[rcount].front() << char(254);
				}
				else {
					std::cout << "\n\t\t\t\t" << char(254) << cashRegister[rcount].front() << char(254);
				}
				for (int Ccount = 0; Ccount < cashRegister[rcount].size() - 1; Ccount++) {
					std::cout << " " << string(4, char(254));
				}
			}
		}
	}
};



void runCostcoLine() {
	CostcoLine Sim;
	std::cout << "\n\t3> Simulation of checkout lines at a CostCo warehouse store\n";
	Sim.SetUpSim();
	clrScrn();
	Sim.runSimTime();


}