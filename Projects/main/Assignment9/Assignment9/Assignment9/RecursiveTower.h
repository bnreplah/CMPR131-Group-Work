/// File:    RecursiveTower.h
/// Team Members:
///          Itz Rodrigez 
///          Tony Cheng
///          Ben Halpern
///          Jose Chavez
///          Thien Nguyen
///          Jesus Sierra
/// Professor Q
/// CMPR 131
/// Assignment 9
/// 11/1/21
/// Description:
///
/// 
/// Reviewed by:	[Name]	:	[Date]
///							:
///							:
///							:

#pragma once
#include <iostream>
#include "input.h"
#include <stack>
#include <iomanip>

/*  Recursive algorithm for Towers of Hanoi
*   1) Move the top disks to an auxillary peg.
*   2) Move the bottom disk to the destination peg.
*   3) Finally, move the previous disks from the auxillary peg to the destination peg.
*/


/***    Class Invariant 
*       [RECURSIVE][CLASS] TowerOfHanoi
*  
* 
* 
* 
* 
*       Depends on:             input.h, iostream, stack, iomanip
*       Classes and function:   header(), inputChar(), inputInteger(), Class TowerOfHanoi, clrScrn()
*/
class TowerOfHanoi
{
private:

    stack<int> mStickA = stack<int>();
    stack<int> mStickB = stack<int>();
    stack<int> mStickC = stack<int>();
    int mMoveNum = int();
    int mRings;
    bool mGameOver;
    bool mWinner;
    string mMessage;
    int mDisk = int();
public:
    
    /// [DEFAULT][CONSTRUCTOR]
    /// Precondition: N/A
    /// Postcondition: initialized the private member variables and resets the booleans
    TowerOfHanoi()
    {
        mRings = 0;
        mDisk = 0;
        mGameOver = false;
        mWinner = false;
        mMessage = "";
    }//end default constructor

    /// precondition: take an int variable
    /// postcondition: this will return the stack i. it defaults to stackA
    stack<int> passStack(int i) {
        switch (i) {
        case(1):return mStickA;
        case(2):return mStickB;
        case(3):return mStickC;
        default:
            return mStickA;
        }
    }//end passStack


    /// precondition: no condition
    /// postcondition: this will assign the value of message to ""
    void resetMessage()
    {
        mMessage = "";
    }//end resetMessage
    
    ///precondition:Take a string variable
    ///postcondition: set mMessage to the string variable val
    void setMessage(string val) {
        mMessage = val;
    }//end setMessage


    /// precondition: no condition
    /// postcondition: this will print out the title of the game and an error message below it
    void displayMessage() {
        std::cout << endl << "\t" << mMessage << endl;
    }//end displayErrorMessage
    


    /// precondition: value must be an integer stack
    /// postcondition: will check if the stack is empty, if so will return true.
    bool emptyPeg(stack<int> pStick) {

        if (pStick.size() == 0)
        {
            //message = "\tERROR: There are no rings placed in that peg to move, Please try again";
            return true;
        }

        return false;
    }//end emptyPeg



    /// Precondition: there must be at least one ring in the game for this to work properly
    /// Postcondition: this will check if all the rings are in stackC, 
    ///     if so will adjust the booleans of GameOver and Winner which will end the game
    bool checkGame(stack<int>& pDest)
    {

        if (pDest.size() == mRings)
        {
            setGameOver();
            setWinner();
            return true;
        }
        return false;
    }//end checkGame

    /// [RECURSIVE]
    /// Precondition: first two values must be chars of A B or C and the third value must be integer
    /// Postcondition: this will check if the move is legal if so will carry out the transfer of rings and
    ///     increment the number of turns by one
    void moveRings(int n, stack<int>& pFrom, stack<int>& pTo, stack<int>& pAux)
    {
       
        if (checkGame(pTo))
            return;

        if (n == 1)
        {
            move(pTo, pFrom);
            print();
            return;
        }
        moveRings(n - 1, pFrom, pAux, pTo);
        move(pTo, pFrom);
        print();
        moveRings(n - 1, pAux, pTo, pFrom);
        
    }//end moveRings

    
    /// [RECURSIVE][OVERLOADED]
    /// Precondition:       (size_t) time_s is in miliseconds, the time to delay during the recursive run to better be able to see the towers 
    /// Postcondition:      
    void moveRings(int n, stack<int>& pFrom, stack<int>& pTo, stack<int>& pAux, size_t pTime_s)
    {
        clrScrn();
        
        //sleep_ms(time_s);
        if (checkGame(pTo))
            return;
        
        if (n == 1)
        {
            
            move(pTo, pFrom);
            print(pTime_s);
            return;
        }

        moveRings(n - 1, pFrom, pAux, pTo);
        move(pTo, pFrom);
        print(pTime_s);
        moveRings(n - 1, pAux, pTo, pFrom);
        
        
    }

    /// [DRIVER]
    /// Precondition:       N/A
    /// Postcondition:      runs the recursive solution for towers of hanoi
    /// 
    ///     Dependent on:           
    ///     Classes and Functions:  
    void run() {
        
        moveRings(mDisk, mStickA, mStickC, mStickB);
        setMessage("Complete the Towers of Hanoi");
        print();
    }//end run  

    /// [DRIVER][OVERLOADED]
    /// Precondition:       (size_t) time_s is time in miliseconds to delay each print and recursive run of the moveRings() function, time_s is a non negative value
    /// Postcondition:      runs the recursive solution for towers of hanoi
    /// 
    ///     Dependent on:           
    ///     Classes and Functions:  
    void run(size_t pTime_s) {
        
        moveRings(mDisk, mStickA, mStickC, mStickB, pTime_s);
        setMessage("Completed the Towers of Hanoi");
        print(pTime_s);
    }//end run [overlaoded]

    /// [MUTATOR]
    /// Precondition:       (stack<int>) &to is a stack parameter passed by reference from which to push the top value from the (stack<int>) &from stack
    ///                     (stack<int>) &from cannot be empty
    /// Postcondition:      moves the top value from int stack from to the int stack to
    /// 
    ///     Dependent on:           input.h, stack, iostream
    ///     Classes and Functions:  pause(), stack, std::cout
    void move(stack<int>& pTo, stack<int>& pFrom) {
        
        getMove(pTo, pFrom);

        //print();
        if (pFrom.empty()) {
            std::cout << "\nempty... error\n";
            pause();
            return;
        }//end if
        else {
            pTo.push(pFrom.top());
            pFrom.pop();
            mMoveNum++;
        }//end else
    }//end move
    
    ///Precondition: require two stack arguments
    ///Postcondition: set message to reflect the move that was made
    void getMove(stack<int>& pTo, stack<int>& pFrom) {
        char chTo = char();
        char chFrom = char();
        if (pTo == mStickA)
            chTo = 'A';
        else if (pTo == mStickB)
            chTo = 'B';
        else if (pTo == mStickC)
            chTo = 'C';

        if (pFrom == mStickA)
            chFrom = 'A';
        else if (pFrom == mStickB)
            chFrom = 'B';
        else if (pFrom == mStickC)
            chFrom = 'C';

        setMessage("Move #" + to_string(mMoveNum + 1) + " Moved ring " + to_string(pFrom.top()) + " from peg " + chFrom + " to " + chTo);
    }

    /// [MUTATOR]
    /// Precondition:       no condition
    /// Postcondition:      this will set the mGameOver value to true
    void setGameOver(){
        mGameOver = true;
    }//end setGameOver

    /// [MUTATOR]
    /// Precondition:       no condition
    /// Postcondition:      this will set the mWinner value to true
    void  setWinner(){
        mWinner = true;
    }//end setWinner

    /// [ACCESSOR]
    /// Precondition:       no condition
    /// Postcondition:      will return the value of mGameOver
    bool getGameOver(){
        return mGameOver;
    }//end getGameOver

    /// [ACCESSOR]
    /// Precondition:       no condition
    /// Postcondition:      will return the value of mWinner
    bool getWinner(){
        return mWinner;
    }//end getWinner

    /// [MUTATOR]
    /// Precondition:       no condition
    /// Postcondition:      this will set the amount of rings for the TowerOfHanoi Class which must be an interger whithin 1-64
    /// 
    ///     Dependent on:           input.h, *this
    ///     Classes and Functions:  stack, setGame()
    int setRings()
    {
        this->mRings = inputInteger("\n\tEnter the number of rings (1..64) to begin: ", 1, 64);
        this->mDisk = this->mRings;
        setGame(mRings);
        print();
        return mRings;
    }//end setRings

    /// [RECURSIVE][MUTATOR]
    /// Precondition: must be a set amount of rings in the class of TowerOfHanoi
    /// Postcondition: will set all the numbers to VectorA starting the game
    ///     Dependent on:           stack
    ///     Classes and Functions:  stack, setGame()
    void setGame( int i )
    {
        if (i > 0) {
            mStickA.push(i);
            setGame(i - 1);
        }
        else
            return;
    }//end setGame

    /// [ACCESSOR][DRIVER]
    /// Precondition: N/A
    /// Postcondition: runs the recursive print setting the value of levels ( items on the pegs ) to that of the user defined ring number
    ///     Dependent on:           input.h, iostream, stack
    ///     Classes and Functions:  header(), printStack(), std::cout
    void print()
    {
        
        displayMessage();
        printStack(mStickA, mStickB, mStickC, mRings);
        header("");
        std::cout << "\n\n";
        //std::cout << setw(13) << "\n" << " ===||==="<< "\t" <<" ===||===" << "\t"<< " ===||===\n";
    }
    /// [ACCESSOR][DRIVER]
    /// Precondition: (size_t) t is a non zero incremental value which will be passed to the sleep_ms() which runs a delay for t miliseconds 
    /// Postcondition: runs the recursive print setting the value of levels ( items on the pegs ) to that of the user defined ring number
    ///     Dependent on:           input.h, iostream, stack
    ///     Classes and Functions:  sleep_ms(), printStack(), header(), std::cout
    void print(size_t t)
    {
        sleep_ms(t);
        displayMessage();
        printStack(mStickA, mStickB, mStickC, mRings);
        header("");
        std::cout << "\n\n";
        //std::cout << setw(13) << "\n" << " ===||==="<< "\t" <<" ===||===" << "\t"<< " ===||===\n";
    }

    /// [RECURSIVE]
    /// Precondition:   (stack<int>) stick_a is the stack holding the values of the first peg
    ///                 (stack<int>) stick_b is the stack holding the values of the second peg
    ///                 (stack<int>) stick_c is the stack holding the values of the last peg
    ///                 (int) n is the recursive condition which triggers the stop case value which is decrimented 
    /// Postcondition:  if the stacks are empty then the screen will display a set of empty pegs equal to the value of n
    ///                 otherwise where there is a non empty stack, the function will take the stacks passed by value and pop off the values of the stack to display the pegs with their values
    void printStack(stack<int> pStick_a, stack<int> pStick_b, stack<int> pStick_c, int n) {
        
        if (n == 0 || (pStick_a.empty() && pStick_b.empty() && pStick_c.empty()) ) {               //stop case
            return;
        }//end if
        std::cout << "\n\t\t\t\t";
        if ((pStick_a.size() == n) && !pStick_a.empty() && pStick_a.size() != 0) {                 //base case(1)
            std::cout << char(254) << pStick_a.top() << char(254) << "\t\t\t";
                pStick_a.pop();
        }//end if
        else
            std::cout << "||" << "\t\t\t";                                                      //empty first peg
        if ((pStick_b.size() == n) && !pStick_b.empty() && pStick_b.size() != 0) {                 //base case(2)
            std::cout << char(254) << pStick_b.top() << char(254) << "\t\t\t";
            pStick_b.pop();
        }//end if
        else
            std::cout << "||" << "\t\t\t";                                                      //empty middle peg
        if ((pStick_c.size() == n) && !pStick_c.empty() && pStick_c.size() != 0) {                 //base case(3)
            std::cout << char(254) << pStick_c.top() << char(254) << "\n";
            pStick_c.pop();
        }//end if
        else
            std::cout << "||" << "\t\t\t\n";                                                    //empty peg
        std::cout << "\n";                                                                      //blank line for visibility
        printStack(pStick_a, pStick_b, pStick_c, n-1);
    }
};//end Class TowerOfHanoi

//////////////////////////
// MAIN DRIVER FUNCTION //
//////////////////////////

/// Precondition: N/A
/// Postcondition: Drives the recursive Towers of Hanoi Game
///     Depends on:             input.h, RecursiveTower.h, iostream
///     Classes and functions:  header(), inputChar(), inputInteger(), Class TowerOfHanoi, clrScrn()
void runTowerOfHanoi()
{
 
    header("\n\tTowers of Hanoi using recursion");
    std::cout << "\n";                                                                         //blank line for visibility

    std::cout << "\n\tThe Tower of Hanoi also called the Tower of Brahma or Lucas' Tower is a mathematical game.";
    std::cout << "\n\tIt consists of three pegs and a number of rings of different sizes, which can slide onto";
    std::cout << "\n\tany peg.The game starts with the rings in a neat stack in ascending order of size on one";
    std::cout << "\n\tpeg, the smallest at the top, thus making a conical shape.";
    std::cout << "\n\n\tThe objective of the game is to move the entire stack from the starting peg - A to ending peg - B,";
    std::cout << "\n\tobeying the following simple rules :";
    std::cout << "\n\t      1. Only one disk can be moved at a time.";
    std::cout << "\n\t      2. Each move consists of taking the upper disk from one of the stacks and";
    std::cout << "\n\t         placing it on top of another stack or on an empty peg.";
    std::cout << "\n\t      3. No larger disk may be placed on top of a smaller disk.\n";
    
    TowerOfHanoi test = TowerOfHanoi();
    test.setRings();
    if (inputChar("\n\tDo you want to add a delay? [ (Y)es / (N)o ]: ", char('Y'), char('N')) == 'Y') {
        int time_s = inputInteger("\n\tPlease enter the number of miliseconds for the delay: ", true);
        test.run(static_cast<size_t>(time_s));
    }
    else
        test.run();
   
}//end runTowerOfHanoi


