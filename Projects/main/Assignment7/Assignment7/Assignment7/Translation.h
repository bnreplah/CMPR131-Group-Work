#pragma once

#include <iostream>
#include "input.h"
#include <stack>
//#include "myContainers.h"
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
	//stack<double> numStack = stack<double>();
	//stack<char> valueStack = stack<char>();

	//symbol stack
	stack<Operator> symbStack = stack<Operator>();
	
	string input = string();
	string fresult = string();

public:
	PostfixConverter() {}
	
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
			return 3 +_parenthesis_level;
			break;
		case ('*'):
			return 2 +_parenthesis_level;
			break;
		case ('/'):
			return 2 +_parenthesis_level;
			break;
		case ('+'):
			return 1 +_parenthesis_level;
			break;
		case ('-'):
			return 1 +_parenthesis_level;
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

	void translate(string pinput) 
	{
		this->input = pinput;

		//stack<char> hold;
		string result = string();//((a+b)*c - 5)



		for (int i = 0; i < input.length(); i++)
		{
			
			if (input.at(i) == ' ')//skip spaces
				continue;
			char temp = input.at(i);


		
		
		//If (the next input is a left parenthesis)
			// push to the stack
			if (priority(temp) == -1) {//if number or other operand
				result += temp;
				//result += " ";
			}
			else if (temp == '(') {	//if RHS parenthesis push to stack
				//if( the next input is a left parenthesis )
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

			}//end else

			//				else if (the next input is a number or other operand)
			//				read the operand and write it to the output
			else if (temp == ')'){
				_parenthesisEnd = true;
				
				--_parenthesis_level;
				
				_lookingForClose = false;

				while (!symbStack.empty() && symbStack.top().precedence != 6 && priority(temp) != 0 && priority(temp) != -1) {
					if (symbStack.top().symb != '(' && symbStack.top().symb != ')') {
						result += symbStack.top().symb;
						result += " ";
					}
					symbStack.pop();
				}//end while
				//if(!symbStack.empty()) symbStack.pop();//pops off the parenthesis

				_parenthesisStart = false;
				
			} // && priority(hold.top()) > priority(input[i]));	
			//(priority(temp) != 0 && priority(temp) != -1 && priority(temp) != 6){// if an operand
			
			else {//operator found
				Operator oper;
				//******************************************************************************
				result += " ";
				//******************************************************************************
				oper.precedence = priority(temp);
				oper.symb = temp;
				result += " ";
				//if (temp == ')') {

				while(!symbStack.empty() && oper.precedence  <= symbStack.top().precedence){
					if (symbStack.top().symb != '(' && symbStack.top().symb != ')') {
						
						result += symbStack.top().symb;
						result += " ";

					}
					symbStack.pop();
				
				}
				symbStack.push(oper);
			}
			
				
		}//end for
		if (_parenthesis_level != 0 && _parenthesisEnd && !_parenthesisStart) {
			_syntaxError = true;
			cout << "\nError: unbalanced paranthesis\n";
		}
		while (!symbStack.empty()) {//if at end of input read
			result += symbStack.top().symb;
			result += " ";
			symbStack.pop();
		}//end while

		

		this->fresult = result;
	}
	
	//precondition: run translate first
	//postcondition: returns the result as a string
	string getResult() {
		return this->fresult;
	}
	string getInput() {
		return this->input;
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
		//string exp = "a + b*(c^d-e)^(f+g*h)-i";//
		//string exp = "4.8+3.2-6+1+3.7)-8.1*6";//evaluates but tells user ubalanced parenthesis 
		string exp = "4.8+3.2-(6+1+3.7)-8.1*6";//evaluates but tells user ubalanced parenthesis 
		
		run.translate(exp);
		run.getResult();
		header("2> Translation of Arithmetic Expression");
		cout << "\n\t\tInfix expression: " << run.getInput();
		cout << "\n\t\tPostfix expressions: " << run.getResult();
		pause();
		return;
	
}