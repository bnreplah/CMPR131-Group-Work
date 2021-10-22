#pragma once

#include <iostream>
#include "input.h"
#include <stack>
#include "myContainers.h"
using namespace std;

struct Operator {
	char symb;
	int precedence;
};


class PostfixConverter {
private:
	//state variables
	bool  _parenthesisStart = bool();								// true when found '(' open parenthesis
	bool _parenthesisEnd = bool();									// true when found ')' close parenthesis
	
	bool _lookingForOperand = bool();								// true when waiting for next operand
	
	bool _lookingForOperator = bool();								// true when looking for next operator
	bool _lookingForClose = bool();									// true when looking for closing parenthesis
	
	int _parenthesis_level = int();									//counts the ammount of parenthesis, must be at 0 when done, othewise error
	
	bool _symStackEmpty = bool();									// true if no operators on the stack
	//bool _numStackEmpty = bool();									// true if the number stack is empty

	bool _syntaxError = bool();										//if syntax error, flip to true, and exit

	int _lastLevelOfPrecendence = int();							//the level or precedence of the last object

	//number stack
	stack<double> numStack = stack<double>();
	stack<char> valueStack = stack<char>();

	//symbol stack
	stack<Operator> symbStack = stack<Operator>();
	
	string input = string();


public:
	PostfixConverter() {

	}
	
	PostfixConverter(string pInput): input(pInput) {	}



	//gets order fo precedence
	int priority(char p) 
	{
		switch (p) {
		case('('):
			_parenthesisStart = true;
			++_parenthesis_level;
			return 6 ;
			break;
		case ('^'):
			return 5 + _parenthesis_level;
			break;
		case ('*'):
			return 4 + _parenthesis_level;
			break;
		case ('/'):
			return 3 + _parenthesis_level;
			break;
		case ('+'):
			return 2 + _parenthesis_level;
			break;
		case ('-'):
			return 1 + _parenthesis_level;
			break;
		case (')'):
			_parenthesisEnd = true;
			--_parenthesis_level;
			return 0;
			break;
		default://if number
			return -1;
			break;
		}
	}


	//	psuedo code logic from the book
	//	2)	do
	//			if( the next input is a let parenthesis )
	//				read the left parenthesis and push it onto the stack.
	//			else if (the next input is a number or other operand)
	//				read the operand and write it to the output
	//			else if (the next input is one of the operation symbols){
	//				do 
	//					prin the top operation and pop it
	//				while none of these three conditions are ture
	//					(1) The stack becomes empty, or
	//					(2) The enxt symbol on the stack is a left parenthessi 
	//					(3) The next symbol on the stack is an operation with lower precednce than the next input symbol
	//
	//

	void translate(string input) 
	{
		//stack<char> hold;
		string result = string();//((a+b)*c - 5)



		for (int i = 0; i < input.length(); i++)
		{
			if (input.at(i) == ' ')
				continue;
			char temp = input.at(i);


		
		
		//If (the next input is a left parenthesis)
			// push to the stack
			if (temp == '(') {	//if( the next input is a left parenthesis )
								//read the left parenthesis and push it onto the stack.

				//result += " "temp;
				_parenthesisStart = true;
				//symbStack.push(temp);
				++_parenthesis_level;
				//_lookingForOperand = true;
				_lookingForClose = true;
				Operator current;
				current.precedence = this->priority(temp);
				current.symb = temp;
				symbStack.push(current);//pushes to stack with precedence

			}

			//			else if (the next input is a number or other operand)
			//				read the operand and write it to the output
			else if (priority(temp) == -1){//then number or other operand
				result += temp;
				//result += " ";
			}
			else if (priority(temp) != 0 && priority(temp) != -1 && priority(temp) != 6){
				Operator oper;
				//******************************************************************************
				result += " ";
				//******************************************************************************
				oper.precedence = priority(temp);
				oper.symb = temp;
				if (!symbStack.empty()) {
					if (temp != ')') {

						do {
							//***********************************************
							if (!symbStack.empty() && symbStack.top().symb == '(')
							{
								symbStack.push(oper);
							}
							//***********************************************
							else if (!symbStack.empty() && oper.precedence > symbStack.top().precedence) {//can only put on the stack if higher precendence than one on the stack
							
																									 
								symbStack.push(oper);
							}
							else {
								result +=  symbStack.top().symb;
								result += " ";
								symbStack.pop();
								//***********************************************
								if (symbStack.empty())
								{
									symbStack.push(oper);
								}
								//***********************************************
							}
						} while (!symbStack.empty() && oper.precedence < symbStack.top().precedence);
					}
					else {
						if (symbStack.top().symb != '(' && symbStack.top().symb != ')') {
							result += symbStack.top().symb;
							result += " ";
							symbStack.pop();
						}
					}
				}
				else
					symbStack.push(oper);
			} // && priority(hold.top()) > priority(input[i]));	
			else {//if ')'
				while (!symbStack.empty()) {//if at end of input read
					
					
					///******************************************
					if (symbStack.top().symb !='(')
					{
						result += symbStack.top().symb ;
						result += " ";
					}
					else
					{
						symbStack.pop();
						break;
					}
					///******************************************
					symbStack.pop();
				}//end while
			}

		}//end for
		while (!symbStack.empty())
		{
			result += symbStack.top().symb;
			symbStack.pop();
		}

		cout << "\n answer: " << result;


	}
				/*else if (symbStack.empty()) {
					_syntaxError = true;
					return;
				}*/


		//	_lookingForClose = false;
		//	//_parenthesisEnd = true;
		//	--_parenthesis_level;
		//		
		//}

		//else if (the next input is one of the operation symbols)
		//do
		//	print the top operation and pop it
		//while none of these three conditions are true:
		//	(1)the stack becomes empty, or
		//	(2)The next symbol on the stack is a left parenthesis, or
		//	(3)the next symbol on the stack is an operation with lowere precendece than the next input symbol
	
			

		//else
		//Read and discard the next input symbol(which should be a right parenthesis)
		//Print the top operation and pop it; keep printing and popping until the next symbol on the stack is a left parenthesis
		//If no left parenthesis is encountered, then print an error message indicating unbalanced parenthese, and halt.
		//Finally, pop the left parenthesis

};


//////////////////////////
// MAIN DRIVER FUNCTION //
//////////////////////////
// Precondition: N/A 
// Postcondition: main driver, runs selected function
void runTranslation()
{
		
	
		PostfixConverter run;
		string exp = "a + b*(c^d-e)^(f+g*h)-i";// ab+(cd^ e - )(f  g h * + )^ * i -
		//string exp = "4.8+3.2-6+(1+3.7)-8.1*6";// ab+(cd^ e - )(f  g h * + )^ * i -
		
											   
		//string exp = "4.8+3.2-6+(1+3.7)-8.1*6";// 4.8 3.2 + 6 - 1 3.7 + + 8.1 6 * -
		//string exp = "";// 4.8 3.2 + 6 - 1 3.7 + + 8.1 6 * -

		run.translate(exp);
		pause();
		return;
	
}