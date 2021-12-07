#include <iostream>
#include "input.h"
using namespace std;

int main()
{
    do
    {
        switch (mainMenuOption())
        {
        case 0: exit(0); break;
        case 1: ; break;
        case 2: ; break;
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
    header("CMPR131 Chapter 15 - Assignmnet 13 by  Ben, Thien , Itz, Tony, Jose, and Jesus");
    string options[] = { "\n\t\t1> Create a directed or undirected graph with number of vertice",
                         "\n\t\t2> Built edge",
                         "\n\t\t3> Display graph",
                         "\n\t\t4> Traversals",
                         "\n\t" + string(100 , char(196)) +
                         "\n\t\t0 > Exit "
    };
    for (string option : options)
        cout << option;
    header("");

    int optionInteger = inputInteger("\n\t\tOption: ", 0, 2);
    clrScrn();

    return optionInteger;

}//end menuOptions