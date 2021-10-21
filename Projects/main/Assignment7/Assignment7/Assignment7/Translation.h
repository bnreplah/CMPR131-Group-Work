#pragma once

#include <iostream>
#include "input.h"
#include <stack>
#include "myContainers.h"
using namespace std;



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
	bool _numStackEmpty = bool();									// true if the number stack is empty

	bool _syntaxError = bool();


	//number stack
	stack<double> numStack = stack<double>();
	stack<char> valueStack = stack<char>();

	//symbol stack
	stack<char> symbStack = stack<char>();



public:
	PostfixConverter() {

	}




	//int priority(char p) 
	//{
	//	if (p == '^')
	//		return 3;
	//	else if (p == '/' || p == '*')
	//		return 2;
	//	else if (p == '+' || p == '-')
	//		return 1;
	//	else return -1;
	//}

	void translate(string input) 
	{
		//stack<char> hold;
		string result;

		for (int i = 0; i < input.length(); i++)
		{
			char temp = input[i];
			
			//If (the next input is a left parenthesis)
			//read and push to the stack
			if (temp == '(') {
				result += temp;
				_parenthesisStart = true;
				symbStack.push(temp);
				++_parenthesis_level;
				_lookingForOperand = true;
				_lookingForClose = true;
				
			}
			if ( _lookingForClose && temp == ')') {//if the closing parenthesis is found
				_parenthesisEnd = true;
				/*code to put the value in potfix*/
				if (!valueStack.empty() && !symbStack.empty()) {
					if (valueStack.size() >= 2) {
						temp += valueStack.top();
						valueStack.pop();
						temp += valueStack.top();
						valueStack.pop();
					}
					

				}
				else if (!numStack.empty() && !symbStack.empty()) {
					if (valueStack.size() >= 2) {
						cout << valueStack.top();
						temp += valueStack.top();
						valueStack.pop();

						cout << valueStack.top();
						temp += valueStack.top();
						valueStack.pop();

						if (symbStack.size() > 1) {
							temp += symbStack.top();
							symbStack.pop();
						}//end if
						
					}
					
				}
				else if (symbStack.empty()) {
					_syntaxError = true;
				}


				_lookingForClose = false;
				//_parenthesisEnd = true;
				--_parenthesis_level;
				
			}

			//else if (the next input is a number or other operand)
			//read the operand and write it to the output
			else if (_lookingForOperand &&  (temp >= '0' && temp <= '9'))
				numStack.push(temp);
				//result += temp;
			else if ((temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z')) {
				valueStack.push(temp);
			}
			
			//else if (the next input is one of the operation symbols)
			//do
			//	print the top operation and pop it
			//while none of these three conditions are true:
			//	(1)the stack becomes empty, or
			//	(2)The next symbol on the stack is a left parenthesis, or
			//	(3)the next symbol on the stack is an operation with lowere precendece than the next input symbol
			else if (temp == '^' || temp == '/' || temp == '*' || temp == '+' || temp == '-')
			{
				while (!symbStack.empty() && temp != ')') {
					result += temp;
					symbStack.pop();
				} // && priority(hold.top()) > priority(input[i]));
				symbStack.push(temp);
			}
			

			//else
			//Read and discard the next input symbol(which should be a right parenthesis)
			//Print the top operation and pop it; keep printing and popping until the next symbol on the stack is a left parenthesis
			//If no left parenthesis is encountered, then print an error message indicating unbalanced parenthese, and halt.
			//Finally, pop the left parenthesis
			else
			{
				while (!symbStack.empty() && temp != '(')
				{
					result += symbStack.top();
					symbStack.pop();
				}
			}
		}


	}


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

		run.translate(exp);
		cin.ignore(999, '\n');
		return;
	
}