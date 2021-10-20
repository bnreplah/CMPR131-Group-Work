#pragma once

#include <stack>
#include <iostream>
#include "input.h"

using namespace std;
class Expression
{

private:

	string equation;

	/// Precondition:
	/// Postcondition:
	bool parenthesesCheck(string exp)
	{
		stack<char> testStack;
		char temp;
		bool unbalanced = false;

		for (int i = 0; i < testStack.size(); i++)
		{
			temp = exp[i];
			if (temp == '(')
			{
				testStack.push(temp);
			}
			else if ((temp == ')') && (!testStack.empty()))
			{
				testStack.pop();
			}
			else if ((temp == ')') && (testStack.empty()))
			{
				unbalanced = true;
			}
		}
		return unbalanced;
	}

public:

	/// Precondition:
	/// Postcondition:
	double evaluate()
	{
		//first checking if paranthesis are balanced
		double answer;
		if (!parenthesesCheck(equation))
		{
			cout << "\n\t[ERROR] : Parentheses don't match.";
			return;
		}

		stack<double> numberStack;
		stack<char> operatorStack;
		stack<char> parenthesisStack;
		bool tokenize = false;
		string stringNumberTemp;

		//    ( 2 + 3.5 ) - 4

		/// Looping through every character seperating operands and operators, and tokenizing onto their respective stacks
		for (int i = 0; i < equation.size(); i++)
		{
			char tempChar = equation.at(i);

			/// Will concatenate 
			if (isdigit(tempChar) || (tempChar == '.'))
			{
				stringNumberTemp += tempChar;

			}
			// This will store the operand on the operator stack and trigger a tokenization of the strinNumberTemp
			else if (tempChar == '+' || tempChar == '-' || tempChar == '*' || tempChar == '/')
			{
				operatorStack.push(tempChar);
				tokenize = true;
			}
			if (tokenize)
			{
				numberStack.push(stod(stringNumberTemp));
				// clear string

			}
		}

		return answer;
	}



	/// Precondition:
	/// Postcondition:
	void setExpression(string exp)
	{
		equation = exp;
	}

	/// Precondition: 
	/// Postcondition: 
	void evaluateStackTops(stack<double>& numbers, stack<char>& operations)
	{
		double operand1, operand2;

		operand2 = numbers.top();
		numbers.pop();
		operand1 = numbers.top();
		numbers.pop();
		switch (operations.top())
		{
		case '+': numbers.push(operand1 + operand2);
			break;
		case '-': numbers.push(operand1 - operand2);
			break;
		case '*': numbers.push(operand1 * operand2);
			break;
		case '/': numbers.push(operand1 / operand2);
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

	cout << "\n\t1. Simple Calculator";
	cout << "\n\t_______________________________";

	Expression function;

	function.setExpression(inputString("\n\tType a fully paranthesized arithmetic expression:\n", false));

	// maybe check parentheses before evaluation

	function.evaluate();



}









/// Precondition: 
/// Postcondition: 

//######################################################################################
//  FOR REFERENCE/CHEATING PURPOSES ONLY                          ERASE AFTER COMPLETION
//######################################################################################

//// FILE: parens.cxx
//// A small demonstration program for a stack.
//#include <cstdlib>     // Provides EXIT_SUCCESS
//#include <iostream>    // Provides cin, cout
//#include <stack>       // Provides stack
//#include <string>      // Provides string
//using namespace std;
//
//// PROTOTYPE for a function used by this demonstration program
//bool is_balanced(const string& expression);
//// Postcondition: A true return value indicates that the parentheses in the
//// given expression are balanced. Otherwise, the return value is false.
//
//int main()
//{
//	string user_input;
//
//	cout << "Type a string with some parentheses:\n";
//	getline(cin, user_input);
//
//	if (is_balanced(user_input))
//		cout << "Those parentheses are balanced.\n";
//	else
//		cout << "Those parentheses are not balanced.\n";
//
//	cout << "That ends this balancing act.\n";
//	return EXIT_SUCCESS;
//}
//
//bool is_balanced(const string& expression)
//// Library facilities used: stack, string
//{
//	// Meaningful names for constants
//	const char LEFT_PARENTHESIS = '(';
//	const char RIGHT_PARENTHESIS = ')';
//
//	stack<char> store;    // Stack to store the left parentheses as they occur
//	string::size_type i;  // An index into the string
//	char next;            // The next character from the string
//	bool failed = false;  // Becomes true if a needed parenthesis is not found
//
//	for (i = 0; !failed && (i < expression.length()); ++i)
//	{
//		next = expression[i];
//		if (next == LEFT_PARENTHESIS)
//			store.push(next);
//		else if ((next == RIGHT_PARENTHESIS) && (!store.empty()))
//			store.pop(); // Pops the corresponding left parenthesis.
//		else if ((next == RIGHT_PARENTHESIS) && (store.empty()))
//			failed = true;
//	}
//
//	return (store.empty() && !failed);
//}


//// FILE: calc.cxx
//// Basic calculator program that takes a fully parenthesized arithmetic
//// expression as input, and evaluates the arithmetic expression.
//// The purpose is to illustrate a fundamental use of stacks.
//
//#include <cctype>     // Provides isdigit
//#include <cstdlib>    // Provides EXIT_SUCCESS
//#include <cstring>    // Provides strchr
//#include <iostream>   // Provides cout, cin, peek, ignore
//#include <stack>      // Provides the stack template class
//using namespace std;
//
//// PROTOTYPES for functions used by this demonstration program:
//double read_and_evaluate(istream& ins);
//// Precondition: The next line of characters in the istream ins is a fully
//// parenthesized arithmetic expression formed from non-negative numbers and
//// the four operations + - * /.
//// Postcondition: A line has been read from the istream ins, and this line has
//// been evaluated as an arithmetic expression. The value of the expression has
//// been returned by the function.
//
//void evaluate_stack_tops(stack<double>& numbers, stack<char>& operations);
//// Precondition: The top of the operations stack contains + - * or /, and the
//// numbers stack contains at least two numbers.
//// Postcondition: The top two numbers have been popped from the number stack,
//// and the top operation has been popped from the operation stack. The two
//// numbers have been combined using the operation (with the second number
//// popped as the left operand). The result of the operation has then been
//// pushed back onto the numbers stack.
//
//
//int main()
//{
//	double answer;
//
//	cout << "Type a fully parenthesized arithmetic expression:" << endl;
//	answer = read_and_evaluate(cin);
//	cout << "That evaluates to " << answer << endl;
//
//	return EXIT_SUCCESS;
//}
//
//
//double read_and_evaluate(istream& ins)
//// Library facilities used: cstring, iostream, stack
//{
//	const char DECIMAL = '.';
//	const char RIGHT_PARENTHESIS = ')';
//
//	stack<double> numbers;
//	stack<char> operations;
//	double number;
//	char symbol;
//
//	// Loop continues while istream is not �bad� (tested by ins) and next character isn�t newline.
//	while (ins && ins.peek() != '\n')
//	{
//		if (isdigit(ins.peek()) || (ins.peek() == DECIMAL))
//		{
//			ins >> number;
//			numbers.push(number);
//		}
//		else if (strchr("+-*/", ins.peek()) != NULL)
//		{
//			ins >> symbol;
//			operations.push(symbol);
//		}
//		else if (ins.peek() == RIGHT_PARENTHESIS)
//		{
//			ins.ignore();
//			evaluate_stack_tops(numbers, operations);
//		}
//		else
//			ins.ignore();
//	}
//
//	return numbers.top();
//}
//
//void evaluate_stack_tops(stack<double>& numbers, stack<char>& operations)
//// Library facilities used: stack
//{
//	double operand1, operand2;
//
//	operand2 = numbers.top();
//	numbers.pop();
//	operand1 = numbers.top();
//	numbers.pop();
//	switch (operations.top())
//	{
//	case '+': numbers.push(operand1 + operand2);
//		break;
//	case '-': numbers.push(operand1 - operand2);
//		break;
//	case '*': numbers.push(operand1 * operand2);
//		break;
//	case '/': numbers.push(operand1 / operand2);
//		break;
//	}
//	operations.pop();
//}