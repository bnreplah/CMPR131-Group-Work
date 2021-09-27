# Stack Data structures


stack:     
[((()))   ] push the plate down to the bottom of the stack
[ ((|))   ]    
[ ((|))   ]     
[ ((V))   ]    

[     ^    ]    
[     |    ]   
[     |    ]   
[  ((()))  ] Pop the plate from the top of the stack off the stack   
   

[  ((()))  ] isFull() tells if the stack is full    
[  ((()))  ]    
[  ((()))  ]   
[  ((()))  ]    

isFull come into play when you use a static length of the stack. 
if it's a dynamic array, is full is really no needed
When you create a stack, you have an STL ADT.
`#include <stack>` is a stack STL that impliments LIFO and is already in the Standard Template Library and can be used with various data types.

LIFO -> last in first out



# powerpoint notes #

Each time the program decides program decides to place a queen to place a queen on the board,on the board, the position of the position of the new queen is the new queen is stored in a stored in a record which is record which is placed in the placed in the stack.

We also have an integer variable integer variable to keep track of to keep track of how many rows how many rows have been filled have been filled so far.

Each time we try to place a new to place a new queen in the next queen in the next row, we start by row, we start by placing the placing the queen in the first queen in the first column...

...if there is a conflict with conflict with another queen, another queen, then we shift the then we shift the new queen to the new queen to the next column.next column.

If another conflict occurs, conflict occurs, the queen is the queen is shifted rightward shifted rightward again.

When there are no conflicts, we no conflicts, we stop and add one stop and add one to the value of to the value of filled.filled.ROW 1, COL 12filled

Let's look at the third row.  The third row.  The first position we first position we try has a try has a conflict...

...so we shift to column 2.  But column 2.  But another conflict another conflict arises...

...and we shift to the third column.the third column.Yet another Yet another conflict arises...

...and we shift to column 4.  column 4.  There's still a There's still a conflict in conflict in column 4, so we column 4, so we try to shift try to shift rightward rightward again...

fundemental computer science method: backtracking to solve N-Queens;
    it tracks the bounds and what was the last queen, and backtracks if can move or not. 
    If the next row is not found, then back up and move the next queen one space to next valid space. 

# The N-Queen Problem #

Notice it is pushing the move down the stack on the board. If it is invalid in placement, pop the invalid off the stack, 

psuedo code:
Initialize a stack where we can keep track of our decisions.decisions.
    - Place the first queen, pushing its position onto the Place the first queen, pushing its position onto the stack and setting stack and setting filledfilled to 0 to 0.
    - repeat these stepsrepeat these steps
    - if there are no conflicts with the queens...if there are no conflicts with the queens...
    - else if there is a conflict and there is room to else if there is a conflict and there is room to shift the current queen rightward...shift the current queen rightward...
    - else if there is a conflict and there is no room else if there is a conflict and there is no room to shift the current queen rightward...

    algorithm:
        If there are no conflicts:
            - if there are no conflicts with the queens...
              - Increase filled by 1.  
              - If filled is now N, then the algorithm is done.
              - Otherwise, move to the next row and place a queen in the first column
        Else if there is a conflict and there is room to shift the current queen rightward...
            - shift the current queen rightward...
            - Move the current queen rightward,
            - adjusting the record on top of the stack to indicate the new position
        Else if there is a confluct and is no  
            - else if there is a conflict and there is no room to shift the current queen rightward...
              - to shift the current queen rightward...
                - Backtrack!Keep popping the stack, and reducing filled by 1,
                - Until you reach a row where the queen can be shifted rightward.
                - Shift this queen right.




# Assignment 7

Calculator: 
    perfom exponential ,addition, etc. Follow PEMDAS order
    This assignment is useful for updatater division code.  
    Make sure you use the stack to make sure that the paranthesis if there is a syntax error etc.

    Option 3 is N-queens problem, not recursive
        Takes the amount of rows
        we place the first queen ( anywhere you want ), is not recursive so may be slow.
    
    for the calculator code is in the textbook, enhance the code. In his program he hardcoded the logic, DO NOT DO THIS!!!!


# midterm
Will start looking at code very carefully, on the midterm will look at logic, precondition, postcondition, everything. Make sure you take a deep look at the code.