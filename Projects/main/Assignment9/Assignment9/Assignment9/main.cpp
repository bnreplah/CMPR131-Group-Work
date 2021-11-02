//
//
//
//
//



#include <iostream>
#include "input.h"
#include "Stars.h"
#include "RecursiveGuessing.h"
#include "RecursiveTower.h"
using namespace std;
int mainMenuOption();

int main()
{
    do
    {
        switch (mainMenuOption())
        {
        case 0: exit(0); break;
        case 1: runStars(); break;
        case 2: runRecursiveGuessing(); break;
        case 3: test(); break;
        case 4: ; break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        pause();
        clrScrn();
    } while (true);

    return EXIT_SUCCESS;
}

int mainMenuOption()
{
    header("CMPR131 Chapter 9 - Assignmnet 9 by  Ben, Thien , Itz, Tony, Jose, and Jesus");
    string options[] = { "\n\t\t1> Patterns of asterisks and blanks",
                         "\n\t\t2> Guess a number",
                         "\n\t\t3> Solve Tower of Hanoi",
                         "\n\t\t4> Solve n-Queens",
                         "\n\t" + string(100 , char(196)) +
                         "\n\t\t0 > exit "
    };
    for (string option : options)
        cout << option;
    header("");

    int optionInteger = inputInteger("\n\t\tOption: ", 0, 4);
    clrScrn();

    return optionInteger;

}//end menuOptions