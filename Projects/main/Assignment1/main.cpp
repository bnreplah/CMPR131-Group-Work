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
#include "input.h"
using namespace std;


//Prototypes:
int menuOption();
//void Option1();
//void Option2();
//void Option3();

int main() {
	
    do
    {
        switch (menuOption())
        {
        case 0: exit(1); break;
		//case 1: Option1(); break;
		//case 2: Option2(); break;
		//case 3: Option3(); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        pause();
    } while (true);

	return EXIT_SUCCESS;
}//end main()


/// Precondition: N/A
/// Postcondition: Diplays a menue for the user and prompt for the user's option choice selection. Returns a valid option.
int menuOption() {
    clrScrn();
    header("CMPR 131 -  Chapter 1 Software Development by Thien , Itz, Tony, Jose, and Ben");
	string options[] = { "\n\t\t1> ASCII Text To ASCII Numbers ",
						"\n\t\t2> Base Converter ",
						"\n\t\t3> Descriptive Statistics ",
						"\n" + string(100 , char(196)) + 
						"\n\t\t0> exit "

    };
    for (string option : options)
        cout << option;
    header("");
    return inputInteger("\nOption: ", 0, 3);

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




