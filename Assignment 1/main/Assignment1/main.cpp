//	Names:
//		Thien Nguyen
//		Itz Rodriquez
//		Tony Cheng
//		Jose Chavez
//		Ben Halpern
//	Professor Quanch
//	CMPR 131
//	Assignment 1
//	8/26/21
/*
*	Description:
*		Assignment 1, A menu driven program which provides the user to select 3 options, each option takes the user to another menu,
*			on further specifications.
*
* 
*/


#include <iostream>
#include "../../Resources/input (2).h"
using namespace std;


//Prototypes:
int menuOption();
//void Option1();
//void Option2();
//void Option3();

int main() {
	

	return EXIT_SUCCESS;
}//end main()


int menuOption( string title, string const options[] ) {
    clrScrn();
    header(title);
    
    for (string &option : options)
        cout << option;
    header("");
    return inputInteger("\nOption: ", 0, 14);

}//end menuOption




/// Precondition:
/// Postcondition: 
void Option1() {


	/*

		Option 1 Code Here:

	*/


}//end Option1()


/// Precondition:
/// Postcondition:
void Option2() {


	/*

		Option 2 Code Here:

	*/


}//end Option2()

/// Precondition:
/// Postcondition:
void Option3() {
	
	/*
		
		Option 3 Code Here:
	
	*/


}//end Option3()




