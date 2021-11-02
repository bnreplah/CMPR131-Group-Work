#pragma once
#include <iostream>
#include "input.h"
#include <stack>
#include <iomanip>

/*
Move the top \(N-1\) disks to an intermediate peg.
Move the bottom disk to the destination peg.
Finally, move the \(N-1\) disks from the intermediate peg to the destination peg.
*/



class TowerOfHanoi
{
private:

    stack<int> stickA = stack<int>();
    stack<int> stickB = stack<int>();
    stack<int> stickC = stack<int>();
    //stack<int>* source = nullptr;
    //stack<int>* dest = nullptr;
    //stack<int>* aux = nullptr;
    //stack<int>* swap;
    int rings;
    bool gameOver;
    bool winner;
    string message;
    int disk = int();
public:
    //default constructor
    TowerOfHanoi()
    {
        rings = 0;
        disk = 0;
        gameOver = false;
        winner = false;
        message = "";
    }

    stack<int> passStack(int i) {
        switch (i) {
        case(1):return stickA;
        case(2):return stickB;
        case(3):return stickC;
        default:
            return stickA;
        }
    }


    //precondition: no condition
    //postcondition: this will assign the value of message to ""
    void resetMessage()
    {
        message = "";
    }

    void setMessage(string val) {
        message = val;
    }


    //precondition: no condition
    //postcondition: this will print out the title of the game and an error message below it
    void displayErrorMessage() {

        std::cout << endl << "\t\t\t     Tower of Hanoi" << endl;;
        std::cout << endl << "     " << message << endl;
    }
    


    //precondition: value must be an integer stack
    //postcondition: will check if the stack is empty, if so will return true and the value of message wil change
    bool emptyPeg(stack<int> stick) {

        if (stick.size() == 0)
        {
            //message = "\tERROR: There are no rings placed in that peg to move, Please try again";
            return true;
        }

        return false;
    }



    //precondition: there must be at least one ring in the game for this to work properly
    //postcondition: this will check if all the rings are in stackC, 
    //if so will adjust the booleans of GameOver and Winner which will end the game
    bool checkGame(stack<int>& dest)
    {

        if (dest.size() == rings)
        {
            setGameOver();
            setWinner();
            return true;
        }
        return false;
    }


    //precondition: first two values must be chars of A B or C and the third value must be integer
    //postcondition: this will check if the move is legal if so will carry out the transfer of rings and
    // increment the number of turns by one
    void moveRings(int n, stack<int>& from, stack<int>& to, stack<int>& aux)
    {
        print();
        if (checkGame(to))
            return;

        if (n == 1)
        {
            move(to, from);
            return;
        }
        moveRings(n - 1, from, aux, to);
        move(to, from);
        moveRings(n - 1, aux, to, from);
        
    }

    ///time is in miliseconds
    void moveRings(int n, stack<int>& from, stack<int>& to, stack<int>& aux, size_t time_s)
    {
        
        print(time_s);
        if (checkGame(to))
            return;
        sleep_ms(time_s);
        if (n == 1)
        {
            move(to, from);
            return;
        }

        moveRings(n - 1, from, aux, to);
        sleep_ms(time_s);
        move(to, from);
        moveRings(n - 1, aux, to, from);
        
    }

    void run() {
        
        moveRings(disk, stickA, stickC, stickB);
        print();
    }  

    void run(size_t time_s) {
        
        moveRings(disk, stickA, stickC, stickB, time_s);
        print(time_s);
    }

    void move(stack<int>& to, stack<int>& from) {
        if (from.empty()) {
            std::cout << "\nempty... error\n";
            pause();
            return;
        }
        else {
            to.push(from.top());
            from.pop();
        }
    }
    //precondition: no condition
    //postcondition: this will set the gameOver value to true
    void setGameOver()
    {
        gameOver = true;

    }

    //precondition: no condition
    //postcondition: this will set the Winner value to true
    void  setWinner()
    {
        winner = true;
    }

    //precondition: no condition
    //postcondition: will return the value of gameOver
    bool getGameOver()
    {
        return gameOver;
    }

    //precondition: no condition
    //postcondition: will return the value of Winner
    bool getWinner()
    {
        return winner;
    }

    //precondition: no condition
    //postcondition: this will set the amount of rings for the TowerOfHanoi Class which must be an interger whithin 1-64
    int setRings()
    {
        this->rings = inputInteger("\n\tEnter the number of rings (1..64) to begin: ", 1, 64);
        this->disk = this->rings;
        setGame(rings);
        return rings;
    }

    /// [RECURSIVE]
    //precondition: must be a set amount of rings in the class of TowerOfHanoi
    //postcondition: will set all the numbers to VectorA starting the game
    void setGame( int i )
    {
        if (i > 0) {
            stickA.push(i);
            setGame(i - 1);
        }
        else
            return;

    }

    
    //precondition: no condition
    //postcondition: this will output the base of the pegs
    void print()
    {
        
        printStack(stickA, stickB, stickC, rings);
        header("");
        std::cout << "\n\n";
        //std::cout << setw(13) << "\n" << " ===||==="<< "\t" <<" ===||===" << "\t"<< " ===||===\n";
    }
    
    //precondition: no condition
    //postcondition: this will output the base of the pegs
    void print(size_t t)
    {
        sleep_ms(t);
        printStack(stickA, stickB, stickC, rings);
        header("");
        std::cout << "\n\n";
        //std::cout << setw(13) << "\n" << " ===||==="<< "\t" <<" ===||===" << "\t"<< " ===||===\n";
    }
    
    

    /// [RECURSIVE]
    void printStack(stack<int> stick_a, stack<int> stick_b, stack<int> stick_c, int n) {
        if (n == 0 || (stick_a.empty() && stick_b.empty() && stick_c.empty()) ) {//base case
            return;
        }
        std::cout << "\n\t\t\t\t";
        if ((stick_a.size() == n) && !stick_a.empty() && stick_a.size() != 0) {
            std::cout << char(254) << stick_a.top() << char(254) << "\t\t\t";
                stick_a.pop();
        }
        else
            std::cout << "||" << "\t\t\t";
        if ((stick_b.size() == n) && !stick_b.empty() && stick_b.size() != 0) {
            std::cout << char(254) << stick_b.top() << char(254) << "\t\t\t";
            stick_b.pop();
        }
        else
            std::cout << "||" << "\t\t\t";
        if ((stick_c.size() == n) && !stick_c.empty() && stick_c.size() != 0) {
            std::cout << char(254) << stick_c.top() << char(254) << "\n";
            stick_c.pop();
        }
        else
            std::cout << "||" << "\t\t\t\n";
        std::cout << "\n";
        //std::cout << "\t\t\t\t" << stick_a.top() << "\t" << stick_b.top() << "\t" << stick_c.top();
        printStack(stick_a, stick_b, stick_c, n-1);
        
    }
    
};

//main driver function
void runTowerOfHanoi()
{
    //char optionChar;

    cout << "\n\tThe Tower of Hanoi also called the Tower of Brahma or Lucas' Tower is a mathematical game.";
    cout << "\n\tIt consists of three pegs and a number of rings of different sizes, which can slide onto";
    cout << "\n\tany peg.The game starts with the rings in a neat stack in ascending order of size on one";
    cout << "\n\tpeg, the smallest at the top, thus making a conical shape.";
    cout << "\n\n\tThe objective of the game is to move the entire stack from the starting peg - A to ending peg - B,";
    cout << "\n\tobeying the following simple rules :";
    cout << "\n\t      1. Only one disk can be moved at a time.";
    cout << "\n\t      2. Each move consists of taking the upper disk from one of the stacks and";
    cout << "\n\t         placing it on top of another stack or on an empty peg.";
    cout << "\n\t      3. No larger disk may be placed on top of a smaller disk.\n";
    

   clrScrn();
}


void test() {
    header("Towers of Hanoi using recursion");
    TowerOfHanoi test = TowerOfHanoi();
    test.setRings();
    if (inputChar("\n\tDo you want to add a delay? [ (Y)es / (N)o ]: ", char('Y'), char('N')) == 'Y') {
        int time_s = inputInteger("\n\tPlease enter the number of miliseconds for the delay: ", true);
        test.run(static_cast<size_t>(time_s));
    }else
        test.run();
    //stack<int> stick_a = test.passStack(1);
    //stack<int> stick_b = test.passStack(1);
    //stack<int> stick_c = test.passStack(1);
    //test.printStack(stick_a, stick_b, stick_c);

}