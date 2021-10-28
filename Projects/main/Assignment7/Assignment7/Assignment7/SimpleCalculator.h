#pragma once
/// Itz Rodriguez
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
		if (postEquation.empty())
			return 0;
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
		for (int i = 0; i < exp.length(); i++) {
			if (exp[i] == ')' || exp[i] == '(') {
				std::cout << "\nunbalenced parenthesis in equation\n";
				return;
			}
		}
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


};

//////////////////////////
// MAIN DRIVER FUNCTION //
//////////////////////////
// Precondition: N/A 
// Postcondition: main driver, runs selected function
void runSimpleCalculator()
{
	header("1. Simple Calculator");
	//cout << "\n\t" + string(100, char(196));
	PostfixConverter run;
	Expression function;
	string inputfunct;
	//function.setExpression(inputString("\n\n\tType a fully paranthesized arithmetic expression:\n\t", false));
	//cout << "\n\n\tType a fully paranthesized arithmetic expression : \n\t";
	//getline(cin, inputfunct);
	inputfunct = inputString("\n\tType a fully paranthesized arithmetic expression : \n\t ", false);
	run.translate(inputfunct);
	
	//cout << run.getResult().find("(") << endl;
	//cout<<run.getResult().find(")") << endl;
	
	function.setExpression(run.getResult());
	
	// DEBUG ============================================
	//function.display();
	
	cout << "\n\tIt evaluates to: " << function.evaluatePostFix();

	return;
};
