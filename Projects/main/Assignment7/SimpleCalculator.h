#pragma once

#include <stack>
#include <iostream>
#include "input.h"

using namespace std;
class Expression
{

private:
	
	string equation;

	bool paranthesis_Check( string exp)
	{
		stack<char> testComparement;
		char temp;
		bool unbalanced = false;

		for (int i = 0; i < testComparement.size(); i++)
		{
			temp = exp[i];
			if (temp == '(')
			{
				testComparement.push(temp);
			}
			else if ((temp == ')') && (!testComparement.empty()))
			{
				testComparement.pop();
			}
			else if ((temp == ')') && (testComparement.empty()))
			{
				unbalanced = true;
			}
		}
		return unbalanced;
	}

public:
	
	double evaluate()
	{
		//first checking if paranthesis are balanced
		double answer;
		if (!paranthesis_Check(equation))
		{
			cout << "[ERROR]: Paranthesis are unbalanced.";
			return;
		}

		stack<double> numbers;
		stack<char> operators;
		stack<char> paranthesis;
		bool tokenize = false;
		string stringNumberTemp;

		/// Looping through every character seperating operands and operators, and tokenizing onto their respective stacks
		for (int i = 0; i < equation.size(); i++)
		{
			char tempChar = equation.at(i);

			/// Will concatenate 
			if (isdigit(tempChar)||(tempChar == '.'))
			{
				stringNumberTemp += tempChar;

			}
			// This will store the operand on the operator stack and trigger a tokenization of the strinNumberTemp
			else if (tempChar == '+'|| tempChar == '-'|| tempChar == '*'|| tempChar == '/' )
			{
				operators.push(tempChar);
				tokenize = true;
			}



			if (tokenize)
			{
				numbers.push(stod(stringNumberTemp));
			}



		}


		


		return answer;
	}
	void setExpress(string exp)
	{
		equation = exp;
	 }

};

void runSimpleCalculator()
{
	
	cout << "\t1. Simple Calculator\n";
	cout << "\t_______________________________\n";

	Expression function;
	
	function.setExpress(inputString("Type a fully paranthesized arithmetic expression:\n", false));
	function.evaluate();



}

