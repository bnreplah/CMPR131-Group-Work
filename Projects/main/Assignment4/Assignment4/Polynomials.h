// File: Polynomials.h
// Assigned: 
//Itz Rodriguez
//Jose Chavez
//	Team Members:
//		Ben Halpern [Reviewed: 9/30/21]
//		Itz Rodriquez
//		Tony Cheng
//		Jose Chavez
//		Thien Nguyen
//     Jesus Sierra
//	Professor Q
//	CMPR 131
//	Assignment 4
//	9/23/21
// [Reviewed] 9/30/21

#pragma once
#include <iostream>
#include "input.h"
#include <vector>
#include <iomanip>

using namespace std;


//※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※
// Class
//※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※

class Terms
{
private:
    double coefficient = double();
    int exponent = int();

public:
    Terms()
    {
        coefficient = 1;
        exponent = 1;
    }

    Terms(int exp, double coef)
    {
        coefficient = coef;
        exponent = exp;
    }

    void setCoeff(double coef) {
        coefficient = coef;
    }

    double  getCoeff() {
        return coefficient;
    }

    int  getExponent() {
        return exponent;
    }

    void setExponent(int exp) {
        exponent = exp;
    }

    string sign() {

        if (coefficient >= 0)
        {
            return "+";
        }
        else {

            return "";
        }
    }

    //precondition: two boolean values
    //postcondition: this will print out the term with its x as a variable and depending on the exponent and coefficient value, 
    //and will print out the "+" depending on the boolean values
    void printTerm(bool first, bool printSign) {

        string Varexponent = "";

        //adding the + and - signs
        if (first == false && printSign == true)
        {
            cout << sign();
        }

        if( exponent == 0)
        {
            cout << coefficient << " ";
        }

        
        else if ( exponent == 1)
        {
            cout << coefficient<<"x ";
        }

        else if ( exponent >1)
        {
            cout << coefficient;
            Varexponent.append("x^");
            Varexponent.append(to_string(exponent));
            Varexponent.append(" ");
            cout << Varexponent;
        }
    }

    //precondition: must be a double value
    //postcondition: will calculate and returning the result that will put the value to the power 
    //of the exponent and multiplied by the coefficient
    double evaluation(double value)
    {
        double result = double();

        result = pow(value, static_cast<double>(exponent));

        result = result * coefficient;


        return result;
    }

    //precondition: must be two Terms objects
    //postcondition: will add the two coefficients and keep the exponent values the same 
    Terms operator + (const Terms& right) {

        Terms temp;

        temp.coefficient = coefficient + right.coefficient;
        temp.exponent = exponent;

        return temp;
    }


    //precondition: must be two Terms objects
    //postcondition: will subtract the two coefficients and keep the exponent values the same
    Terms operator - (const Terms& right) {

        Terms temp;


        temp.coefficient = coefficient - right.coefficient;
        temp.exponent = exponent;

        return temp;
    }


    //precondition: must be two Terms objects
    //postcondition: will multiply the two coefficients and add the exponent values    
    Terms operator * (const Terms& right) {
        
        Terms temp;
        
        temp.coefficient = coefficient * right.coefficient;
        temp.exponent = exponent + right.exponent;

        return temp;
    }


};

//Prototypes
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°


void initiate(vector<Terms>& vect);
void specifyCoefficients(vector<Terms>& vect);
void evaluate(vector<Terms>& vect, bool coefBool);
void derive(vector<Terms> vect, bool coefBool);
void integral(vector<Terms> vect, bool coefBool);
int singleMenuOption();
void printEquation(vector<Terms>vect);
void applyConstants(vector<Terms>vect, double num);
void addPolynomials(vector<Terms> vectOne, vector<Terms> vectTwo);
void subtractPolynomials(vector<Terms> vectOne, vector<Terms> vectTwo);
void multiplyPolynomials(vector<Terms> vectOne, vector<Terms> vectTwo);
Terms addAllElements(vector<Terms> vect);



//※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※
//Multiple Polynomial Methods
//※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※

//precondition: none
//postcodition: will output two polynomials and perform basic arithmetic, by using two vectors of Terms
void runMultiplePolynomial() {

    cout << endl << "Enter the information for the first polynomial: " << endl;
    cout << "------------------------------------------------------" << endl;


    vector<Terms> polyOne;

    initiate(polyOne);
    specifyCoefficients(polyOne);

    pause();
    clrScrn();
    cout << endl << "Enter the information for the second polynomial: " << endl;
    cout << "------------------------------------------------------" << endl;

    vector<Terms> polyTwo;
    initiate(polyTwo);
    specifyCoefficients(polyTwo);
    pause();
    clrScrn();

    //Printing out the two polynomials
    cout << "P(1) = ";
    printEquation(polyOne);
    cout << endl << endl;
    cout << "P(2) = ";
    printEquation(polyTwo);

    //The addition of the two polynomials
    cout << endl << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Addition:\t";

    addPolynomials(polyOne, polyTwo);

    //The subtraction of the two polynomials
    cout << endl << endl;
    cout << "Subtraction:\t";

    subtractPolynomials(polyOne, polyTwo);

    //The multiplication of the two polynomials
    cout << endl << endl;
    cout << "Multiplication:\t";


    multiplyPolynomials(polyOne, polyTwo);

    //Applying the constant to both polynomials
    cout << endl << endl;
    cout << "--------------------------------------------" << endl;
    double constant = inputDouble("Enter a constant value: ");
    cout << endl << endl;

    cout << "P(1) *" << constant << " = ";

    applyConstants(polyOne, constant);


    cout << endl << endl;
    cout << "P(2) *" << constant << " = ";
    applyConstants(polyTwo, constant);

}



//precondition: must be a vector of Terms and a double value
//postcondition: will output the equation if the coefficients were multiplied by a constant value
void applyConstants(vector<Terms>vect, double num)
{

    double product;

    for (int i = 0; i < vect.size(); i++)
    {
        product = num * (vect.at(i).getCoeff());

        vect.at(i).setCoeff(product);
    }
    printEquation(vect);
}

//precondition: must have elements in the vector of Terms
//postcondition: will output the terms in the vector simulating a polynomial function
void printEquation(vector<Terms> vect) {
    bool first = true;
    cout << "  ";
    for (int i = 0; i < vect.size(); i++)
    {
        vect.at(i).printTerm(first, true);
        first = false;
    }
}

//precondition: a vector of Terms must be passed in here
//postcondition: will store an amount of elements inputted by the user
void initiate(vector<Terms>& vect) {
    vect.clear();

    Terms temp(1, 1.0);
    int num = inputInteger("Enter the number of terms: ", true);

    for (int i = 0; i < num; i++)
    {
        vect.push_back(temp);
    }

    for (int i = 0; i < num; i++)
    {
        vect.at(i).setExponent(num - 1 - i);
    }
}

//precondition: a vector of Terms must be passed in here with elements stored in it
//postcondition: will print out and store the coefficients specified by the user
void specifyCoefficients(vector<Terms>& vect) {
  
    if (vect.empty())
    {
        cout << "ERROR: Please verify the number of terms" << endl;
        return;
    }

    if (vect.empty())
    {
        cout << "ERROR: Please verify the number of terms" << endl;
        return;
    }

    for (int i = 0; i < vect.size(); i++)
    {
        vect.at(i).setCoeff(inputDouble("Enter the coefficient for term #" + to_string(i + 1) + ": "));
    }
    printEquation(vect);
}



//precondition: the two vectors of Terms must have elements
//postcondition: will add the two polynomials, if two vectors have the same exponent value and output the result
void addPolynomials(vector<Terms> vectOne, vector<Terms> vectTwo) {


    int diffSize = vectOne.size() - vectTwo.size();
    vector<Terms> sum;

    if (vectOne.size() > vectTwo.size())
    {
        for (int i = 0; i < diffSize; i++)
        {
            sum.push_back(vectOne.at(i));

        }
    }
    else if (vectTwo.size() > vectOne.size())
    {

        diffSize = diffSize * -1;

        for (int i = 0; i < diffSize; i++)
        {
            sum.push_back(vectTwo.at(i));
        }
    }

    for (int i = 0; i < vectOne.size(); i++)
    {

        for (int j = 0; j < vectTwo.size(); j++)
        {

            if (vectOne.at(i).getExponent() == vectTwo.at(j).getExponent())
            {
                sum.push_back(vectOne.at(i) + vectTwo.at(j));
            }
        }
    }
    printEquation(sum);
}

//precondition: the two vectors of Terms must have elements
//postcondition: will subtract the two polynomials, if two vectors have the same exponent value and output the result
void subtractPolynomials(vector<Terms> vectOne, vector<Terms> vectTwo) {

    int diffSize = vectOne.size() - vectTwo.size();
    vector<Terms> difference;

    if (vectOne.size() > vectTwo.size())
    {
        for (int i = 0; i < diffSize; i++)
        {
            difference.push_back(vectOne.at(i));

        }
    }
    else if (vectTwo.size() > vectOne.size())
    {

        diffSize = diffSize * -1;

        for (int i = 0; i < diffSize; i++)
        {
            difference.push_back(vectTwo.at(i));
            difference.at(i).setCoeff(difference.at(i).getCoeff() * -1);

        }
    }

    for (int i = 0; i < vectOne.size(); i++)
    {

        for (int j = 0; j < vectTwo.size(); j++)
        {

            if (vectOne.at(i).getExponent() == vectTwo.at(j).getExponent())
            {
                difference.push_back(vectOne.at(i) - vectTwo.at(j));
            }
        }
    }
    printEquation(difference);


}

//precondition: the two vectors of Terms must have elements
//postcondition: will perform the proper way to multiply two polynomials and return the result by reference
void multiplyTheTwoPolynomials(vector<Terms>& product, vector<Terms> vectOne, vector<Terms>vectTwo) {

    for (int i = 0; i < vectOne.size(); i++)
    {

        for (int j = 0; j < vectTwo.size(); j++)
        {
            product.push_back(vectOne.at(i)* vectTwo.at(j));
        }
    }
}

//precondition: will need a vector with Terms to pass by reference for the result, another with the uncombined vector Terms
// and an int value that has the highest exponent value in the equation
//postcondition: will return the equation that has added the Terms with the same exponent value
void combineLikeTerms(vector<Terms>&result, vector<Terms> product, int highestExp) {

    vector <Terms> tempVect;
    Terms tempTerm;
    tempTerm.setCoeff(0);

    bool storeBool = false;
    int polyNumber = highestExp;


    for (int a = 0; a < product.size(); a++)
    {

        for (int i = 0; i < product.size(); i++)
        {
            if (product.at(i).getExponent() == polyNumber && product.at(i).getCoeff() !=0)
            {
                tempVect.push_back(product.at(i));
                product.at(i).setCoeff(0);
                storeBool = true;
            }
        }

        if (storeBool == true)
        {
            tempTerm = addAllElements(tempVect);
            tempTerm.setExponent(polyNumber);
            result.push_back(tempTerm);
            storeBool = false;
        }
        tempVect.clear();
        polyNumber = polyNumber - 1;
    }

}

//precondition: the two vectors of Terms must have elements
//postcondition: will perform to multiply the two polynomials and output a simplified polynomial
void multiplyPolynomials(vector<Terms> vectOne, vector<Terms> vectTwo) {

    vector<Terms> product;
    vector<Terms> result;
    int highestExp = vectOne.size() + vectTwo.size();

    multiplyTheTwoPolynomials(product, vectOne, vectTwo);
        
    combineLikeTerms(result,product,highestExp);
    printEquation(result);
    if (result.empty())
    {
        cout << "0";
    }
}

//precondition: the vector of Terms must have elements
//postcondition: will out put the sum of all the Terms in the vector
Terms addAllElements(vector<Terms> vect)
{

    Terms sum(1, 0);

    //add the terms in the temp vector
    for (int i = 0; i < vect.size(); i++)
    {
        sum = sum + vect.at(i);
    }
    return sum;
}

//※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※
//Single Polynomial Methods
//※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※

//precondition: a vector of Terms must be passed in here with elements stored in it
//postcondition: will output the terms in the equation with their result if a value is stored in the variable,
//and will return the total
void evaluate(vector<Terms>& vect, bool coefBool) {

    if (vect.empty())
    {
        cout << "ERROR: Please verify the number of terms" << endl;
        return;
    }
    
    if (coefBool == false)
    {
        cout << "ERROR: Please specify the coefficients" << endl;
        return;
    }

    cout << "P1(x) =";
    printEquation(vect);
    cout << endl;
    double input = double();
    input = inputDouble("Enter the value of x to evaluate the polynomial: ");
    cout << endl;
    double sum = 0;

    for (int i = 0; i < vect.size(); i++)
    {


        if (i == vect.size() - 1)
        {
            cout << '\t'  << "+    " << right << vect.at(i).evaluation(input) << setw(5) << "    <-" << '\t';
            vect.at(i).printTerm(true, false);
            cout << endl  << '\t' << "___________________________" << endl;

            sum += (vect.at(i)).evaluation(input);
        }else {

            cout << '\t' << "     " << right  << vect.at(i).evaluation(input) <<setw(5) << "   <-" << '\t';
            
            setw(10);
            vect.at(i).printTerm(true, false);
            cout << endl;
            sum += vect.at(i).evaluation(input);
        }
    }
    cout  << "\t\t" << sum << endl;
}

//precondition: there must be elements in the vector 
//postcondition: will output the derivative
void derive(vector<Terms> vect, bool coefBool) {

    if (vect.empty())
    {
        cout << "ERROR: Please verify the number of terms" << endl;
        return;
    }
    if (coefBool == false)
    {
        cout << "ERROR: Please specify the coefficients" << endl;
        return;
    }

    cout << "Polynomial(x) = ";
    printEquation(vect);
    cout << endl << endl;
    cout << "Derivative(x) = ";

    for (int i = 0; i <= vect.size() - 1; i++) {
        double newexp = static_cast<double>(vect.at(i).getExponent());

        double newcoeff = vect.at(i).getCoeff() * newexp;

        newexp--;

        if (newexp >= 2)
            cout << newcoeff << "x^" << newexp << " + ";

        else if (newexp == 1)
            cout << newcoeff << "x + ";

        else if (newexp == 0)
            cout << newcoeff << endl;

    }
}

//precondition: there must be elements in the vector 
//postcondition: will output the integral
void integral(vector<Terms> vect,bool coefBool) {
    
    if (vect.empty())
    {
        cout << "ERROR: Please verify the number of terms" << endl;
        return;
    }    

    if (coefBool == false)
    {
        cout << "ERROR: Please specify the coefficients" << endl;
        return;
    }

    cout << "Polynomial(x) = ";
    printEquation(vect);
    cout << endl << endl;
    cout << "Integral = ";

    for (int i = 0; i <= vect.size() - 1; i++) {

        double newexp = static_cast<double>(vect.at(i).getExponent() + 1);

        double newcoeff = vect.at(i).getCoeff() / newexp;

        if (newexp >= 2)
            cout << newcoeff << "x^" << newexp << " + ";

        else if (newexp == 1)
            cout << newcoeff << "x + C" << endl;

    }
}


int singleMenuOption() {

    int optionInteger;
    header("A polynomial...");
    string options[] = { "\n\t\t1. Enter the number of terms ",
                         "\n\t\t2. Specify the coefficients",
                         "\n\t\t3. Evaluate expression ",
                         "\n\t\t4. Solve for the derivative ",
                         "\n\t\t5. Solve for the integral",
                         "\n" + string(100 , char(196)) +
                         "\n\t\t0> return "
    };

    for (string option : options)
        cout << option;

    header("");

    optionInteger = inputInteger("\nOption: ", 0, 5);
    clrScrn();

    return optionInteger;
}


void runSinglePolynomial() {
    int optionInteger;
    vector<Terms> poly;
    bool coefBool = false;

    do
    {
        switch (singleMenuOption())
        {
        case 0: return; break;
        case 1: initiate(poly); break;
        case 2: specifyCoefficients(poly); coefBool = true; break;
        case 3: evaluate(poly,coefBool); break;
        case 4: derive(poly,coefBool); break;
        case 5: integral(poly,coefBool); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        pause();
        clrScrn();
    } while (true);

}

//※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※
// Main Driver function
//※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※


char menuOptionRat() {

    header("A polynomial...");
    string options[] = { "\n\t\tA> A Polynomial",
                        "\n\t\tB> Multiple Polynomials",
                        "\n" + string(100 , char(196)) +
                        "\n\t\t0> return "
    };
    for (string option : options)
        cout << option;
    header("");

    char optionChar = inputChar("\nOption: ", static_cast<string>("ab0"));
    clrScrn();
    return optionChar;

}//end menuOptions

void runPolynomials() {
    do
    {
        switch (menuOptionRat())
        {
        case '0': return; break;
        case 'A': runSinglePolynomial(); break;
        case 'B': runMultiplePolynomial(); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        pause();
    } while (true);
}