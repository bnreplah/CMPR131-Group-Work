#pragma once

#include <iostream>
#include <stack>
#include "input.h"
#include <math.h>
#include "Translation.h"

using namespace std;

class Expression
{

private:

	string postEquation;
	string equation;

public:

	/// Precondition: object must hold elements and must pass the masterCheck, to check for correct paranthesis and consecutive operators
	/// Postcondition: will traverse through the string and apply postfix notation
	double evaluatePostFix()
	{
		//first checking if paranthesis are balanced
		double answer = 0;

		stack<double> numberStack;
		stack<char> operatorStack;
		bool tokenize = false;
		string stringNumberTemp;
		char tempChar;
		bool boolEvaluate = false;

		if (checkIfOnlyNumber())
		{
			return stod(postEquation);
		}

		/// Looping through every character seperating operands and operators, and tokenizing onto their respective stacks
		for (int i = 0; i < postEquation.size(); i++)
		{
			tempChar = postEquation.at(i);
			
			/// Will concatenate 
			if (isdigit(tempChar) || (tempChar == '.'))
			{
				stringNumberTemp += tempChar;
			}
			// This will store the operand on the operator stack and trigger a tokenization of the strinNumberTemp
			else if (tempChar == '+' || tempChar == '-' || tempChar == '*' || tempChar == '/' || tempChar == '^')
			{
				operatorStack.push(tempChar);
				tokenize = true;
				boolEvaluate = true;
			}
			else if (tempChar == ' ')
			{
				tokenize = true;
			}

			if (tokenize)
			{
				if (!stringNumberTemp.empty())
				{
					numberStack.push(stod(stringNumberTemp));
					stringNumberTemp.clear();
				}
				tokenize = false;
			}

			if (boolEvaluate == true)
			{
				evaluateStackTops(numberStack, operatorStack);
				boolEvaluate = false;
			}
		}

		answer = numberStack.top();
		return answer;
	}
	
	///precondition: postEquation must not be empty
	///postcondition: will iterate through the equation to check for operators, will ignore a '-' in the 0 position
	bool checkIfOnlyNumber()
	{
		bool justNumber = true;
		for (int i = 0; i < postEquation.size(); i++)
		{

			if (postEquation.at(i)== '+')
			{
				justNumber = false;
			}

			else if (postEquation.at(i) == '-'&& i!=0)
			{
				justNumber = false;
			}
			else if (postEquation.at(i) == '*')
			{
				justNumber = false;
			}
			else if (postEquation.at(i) == '/')
			{
				justNumber = false;
			}			
			else if (postEquation.at(i) == '^')
			{
				justNumber = false;
			}
		}
		return justNumber;
	}


	/// Precondition: Object must be initialized
	/// Postcondition: wil assign the value to equation
	void setExpression(string exp)
	{
		postEquation = exp;
	}

	/// Precondition: Object must be initialized
	/// Postcondition: will return the value of equation
	string getExpression()
	{
		return equation;
	}

	/// Precondition: must be two objects in the numbers stack, must be at least one objects in the operations stack
	/// Postcondition: will return the result of the two numbers in the top of numbers relative to what operation is at the top of the operations stack
	void evaluateStackTops(stack<double>& numbers, stack<char>& operations)
	{
		double operand1, operand2;

		double tempResult;
		operand2 = numbers.top(); //assigns operand2 for consistency in the switch case 
		numbers.pop();
		operand1 = numbers.top();
		numbers.pop();
		switch (operations.top())
		{
		case '+':
			tempResult = operand1 + operand2;
			numbers.push(operand1 + operand2);
			break;
		case '-':
			tempResult = operand1 - operand2;
			numbers.push(operand1 - operand2);
			break;
		case '*':
			tempResult = operand1 * operand2;
			numbers.push(operand1 * operand2);
			break;
		case '/':
			tempResult = operand1 / operand2;
			numbers.push(operand1 / operand2);
			break;
		case '^':
			tempResult = pow(operand1, operand2);
			numbers.push(pow(operand1, operand2));
			break;
		}
		operations.pop();
	}

	/// precondition: equation must not be empty
	/// postcondition: will check if there are an even amount of paranthesis that correspond in the correct format, if there are then will return false
	bool isParanBalanced(const string& expression)
		// Library facilities used: stack, string
	{
		// Meaningful names for constants
		const char LEFT_PARENTHESIS = '(';
		const char RIGHT_PARENTHESIS = ')';

		stack<char> store;    // Stack to store the left parentheses as they occur
		string::size_type i;  // An index into the string
		char next;            // The next character from the string
		bool failed = false;  // Becomes true if a needed parenthesis is not found

		for (i = 0; !failed && (i < expression.length()); ++i)
		{
			next = expression[i];
			if (next == LEFT_PARENTHESIS)
				store.push(next);
			else if ((next == RIGHT_PARENTHESIS) && (!store.empty()))
				store.pop();      // Pops the corresponding left parenthesis.
			else if ((next == RIGHT_PARENTHESIS) && (store.empty()))
				failed = true;
		}
		return (store.empty() && !failed);
	}

	/// precondition: equation must not be empty
	/// postcondition: will check if there are two operators next to each other, if there are then will return false
	bool operatorCheck()
	{
		char tempChar;
		int count = 0;
		for (int i = 0; i < equation.size(); i++)
		{
			tempChar = equation.at(i);
			if (tempChar == '+' || tempChar == '-' || tempChar == '*' || tempChar == '/')
			{
				count++;
			}
			else
			{
				count = 0;
			}
			if (count > 1)
			{
				return false;
			}
		}
		return true;
	}

	///precondition: object must initialized
	///postcondition; will print out equation for debugging purposes
	void display()
	{
		cout << "\n\t [DEBUG]:  " << postEquation;
	}
};

//////////////////////////
// MAIN DRIVER FUNCTION //
//////////////////////////
// Precondition: N/A 
// Postcondition: main driver, runs selected function
void runSimpleCalculator()
{
	cout << "\n\t1. Simple Calculator";
	cout << "\n\t" + string(100, char(196));

	Expression function;
	string inputfunct;
	//function.setExpression(inputString("\n\n\tType a fully paranthesized arithmetic expression:\n\t", false));
	cout << "\n\n\tType a fully paranthesized arithmetic expression : \n\t";
	getline(cin, inputfunct);
	function.setExpression(inputfunct);
	
	// DEBUG ============================================
	function.display();

	cout << "\n\tIt evaluates to: " << function.evaluatePostFix();

	return;
};
