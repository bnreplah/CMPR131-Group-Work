#include <iostream>
#include "input.h"
#include "myContainers.h"
using namespace std;


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

    int optionInteger = inputInteger("\n\t\tOption: ", 0, 4);
    clrScrn();

    return optionInteger;

}//end menuOptions

void testing();



int main()
{
    LinkTList<LinkTList<bool>> test2d;

    testing();
    do
    {
        switch (mainMenuOption())
        {
        case 0: exit(0); break;
        case 1: ; break;
        case 2: ; break;
        case 3: ; break;
        case 4: ; break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        pause();
        clrScrn();
    } while (true);

    return EXIT_SUCCESS;
}



void testing() {
    LinkTList<LinkTList<bool>> test2d;
    test2d.appendNode(new LinkTList<bool>(3,false));
    std::cout << test2d;
    pause();
   std::cout << endl;
    graph<string> testingGraph;
    testingGraph.addVertex("v1");
    testingGraph.addVertex("v2");
    testingGraph.addVertex("v3");
    testingGraph.addVertex("v4");
    testingGraph.addVertex("v5");
    testingGraph.addVertex("v6");
    testingGraph.addVertex("v7");
    testingGraph.addVertex("v8");
    testingGraph.visualize_matrix();
    std::cout << "\n";
    testingGraph.addEdge(2, 2);
    testingGraph.addEdge(2, 7);
    testingGraph.addEdge(2, 5);
    testingGraph.addEdge(2, 6);
    testingGraph.visualize_matrix();
    std::cout << "\n";
    testingGraph.visualize_edgeSets();
    testingGraph.visualize_edgeList();
    //testingGraph.breadth_first(false);
    //testingGraph.breadth_first(true);
    //testingGraph.depth_first(true);
    //testingGraph.depth_first(true);

    pause();
}