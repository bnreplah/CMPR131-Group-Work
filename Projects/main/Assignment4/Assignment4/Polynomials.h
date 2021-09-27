/// Team members:
///     Itz Rordigues
///
///
///


#pragma once
#include "input.h"
#include <vector>
#include <iostream>




void initiate();
void specifyCoefficients();
void evaluate();
void derive();
void integral();
int singleMenuOption();

//※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※
// Class
//※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※

class Terms
{

private:
    double coefficient;
    int exponent;
    double variable;


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
    void setExponent(int exp) {
        exponent = exp;
    }

    void setVariable(double var) {

        variable = var;
    }
    string sign() {

        if (coefficient > 0)
        {
            return "+";
        }
        else {

            return "";
        }

    }
    void printTerm(bool first, bool printSign) {

        string Varexponent = "";

        //adding the + and - signs
        if (first == false && printSign == true)
        {
            cout << sign();
        }

        //if coefficient is 1 don't print, unless there's no variable
        if (coefficient == 1 && exponent > 0)
        {
            Varexponent.append("x^ ");
            Varexponent.append(to_string(exponent));
            //Varexponent.append(" ");
            cout << Varexponent;
        }
        else if (coefficient == 1 && exponent == 0)
        {
            cout << coefficient << " ";
        }
        else if (coefficient == -1 && exponent == 0)
        {
            cout << coefficient;
        }
        else if (exponent == 0)
        {
            cout << coefficient << " ";

        }
        else if (coefficient == -1 && exponent != 0)
        {

            cout << coefficient;
            Varexponent.append("x^");
            Varexponent.append(to_string(exponent));
            cout << Varexponent << " ";
        }
        else if (coefficient != 0)
        {
            cout << coefficient;
            Varexponent.append("x^");
            Varexponent.append(to_string(exponent));
            Varexponent.append(" ");
            cout << Varexponent;
        }



    }

    double evaluation(double value)
    {
        double result;

        result = pow(value, exponent);

        result = result * coefficient;


        return result;
    }




};



//※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※
//Multiple Polynomial Methods
//※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※

void runMultiplePolynomial() {




}



//※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※
//Single Polynomial Methods
//※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※

void printEquation(vector<Terms> vect) {
    bool first = true;
    cout << "  ";
    for (int i = 0; i < vect.size(); i++)
    {
        vect.at(i).printTerm(first, true);
        first = false;
    }
}
void initiate(vector<Terms>& vect) {
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

void specifyCoefficients(vector<Terms>& vect) {

    for (int i = 0; i < vect.size(); i++)
    {
        //need to print i
        vect.at(i).setCoeff(inputDouble("Enter the coefficient for term # "));
    }
    printEquation(vect);
}

void evaluate(vector<Terms>& vect) {


    cout << "P1(x) =";
    printEquation(vect);
    double input = inputDouble("Enter the value of x to evaluate the polynomial: ");
    double sum = 0;


    for (int i = 0; i < vect.size(); i++)
    {


        if (i == vect.size() - 1)
        {
            cout << "\t+" << vect.at(i).evaluation(input) << " <-\t";
            vect.at(i).printTerm(true, false);
            cout << endl << "_________________________________________" << endl;

            sum = sum + vect.at(i).evaluation(input);
        }

        else if (i != vect.size() - 1) {

            cout << "\t" << vect.at(i).evaluation(input) << " <-\t";

            vect.at(i).printTerm(true, false);

            sum = sum + vect.at(i).evaluation(input);

        }

        cout << "\t" << sum << endl;



    }
}

void derive() {


}

void integral() {



}

int singleMenuOption() {

    int optionInteger;
    header("A polynomial...");
    string options[] = { "\n\t\t1. Enter the number of terms ",
                         "\n\t\t2. Specify the coefficients",
                         "\n\t\t3. Evaluate epxression ",
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

    do
    {

        switch (singleMenuOption())
        {
        case 0: return; break;
        case 1: initiate(poly); break;
        case 2: specifyCoefficients(poly); break;
        case 3: evaluate(poly); break;
        case 4: derive(); break;
        case 5: integral(); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        pause();
    } while (true);

}

//※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※
// Main Driver function
//※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※

int menuOption() {

    header("A polynomial...");
    string options[] = { "\n\t\t1> A Polynomial",
                        "\n\t\t2> Multiple Polynomials",
                        "\n" + string(100 , char(196)) +
                        "\n\t\t0> return "

    };
    for (string option : options)
        cout << option;
    header("");

    int optionInteger = inputInteger("\nOption: ", 0, 3);
    clrScrn();
    return optionInteger;

}//end menuOptions

void runPolynomials() {
    do
    {
        switch (menuOption())
        {
        case 0: return; break;
        case 1: runSinglePolynomial();; break;
        case 2:   runMultiplePolynomial(); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        pause();
    } while (true);


}
