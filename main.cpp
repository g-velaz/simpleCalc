#include <iostream>
#include <string>
#include <regex>
#include  <bits/stdc++.h>

/***
* Author: Gemaris Velazquez
* Date: 1-27-2025
* What is it?
*
* This is a quick and small calculator in which you can type any two integers
* (whole numbers) in an equation and it will do a calculation for you. For
* example, say you want to add 6 and 7 together. The program will prompt you to
* type "6+7" and it will return the answer (13).
*
* This is version 1, which can:
* -add, multiply, subtract, and divide 2 whole numbers
* -can do negative and positive numbers
* -has a divisible by 0 check
*
***/

using namespace std;

int adding(int, int);
int subtracting(int, int);
int multiplying(int, int);
int dividing(int, int);
bool isEquationValid(string, regex);

int main()
{
    //for now the MVP will be of 2 integers
    int number1; //first number of the equation
    int number2; //second number of the equation
    string operatorSign; //can be +, -, *, or /

    //regex of having an equation of 2 numbers
    regex equationRegex ("(-?\\d+) ?(\\+|-|\\*|/) ?(-?\\d+)");

    string equation;

    cout << "Please type in an equation (i.e. \"4+5\"): ";
    getline(cin, equation);

    //Keep asking the user to input the proper equation
    while(!isEquationValid(equation, equationRegex)){
        cout << "Sorry, but the equation you have typed is not valid, please try again." << endl;
        cout << "Please type in an equation that consist of 2 whole numbers (i.e. \"4+5\"): ";
        getline(cin, equation);
    }

    //find the numbers in the equation and save them for use
    smatch partsOfEquation;
    if(regex_search(equation, partsOfEquation, equationRegex)){
        number1 = stoi(partsOfEquation[1]);
        number2 = stoi(partsOfEquation[3]);
        operatorSign = partsOfEquation[2];
    } else {
        cout << "Something went wrong, please restart and try again." << endl;
        return -1;
    }

    int result;
    string operatorWord;


    if(operatorSign == "+"){
        result = adding(number1, number2);
        operatorWord = "sum";
    }else if(operatorSign == "-") {
        result = subtracting(number1, number2);
        operatorWord = "difference";
    }else if(operatorSign == "*") {
        result = multiplying(number1, number2);
        operatorWord = "product";
    }else if(operatorSign == "/"){
        if(number2 == 0){
            cout << "Sorry about that, but " << number1 << " cannot be divisible by 0." << endl;
            return -2;
        }
        result = dividing(number1, number2);
        operatorWord = "quotient";
    }
    else {
       cout << "That is not a valid way to put these numbers together";
       return -3;
    }

    cout << "The " << operatorWord << " of " << number1 << " and " << number2 << " is " << result << endl;

    return 0;
}
//Validity regex
bool isEquationValid(string equation, regex equationRegex){
    /***regex of having an equation of 2 numbers
    examples of valid regex:
        -4+5
        45-2
        6 * 30
        500/10
    examples of invalid regex:
        r+4
        4++5
        6e0
        6     + 5
    ***/

    if(regex_match(equation, equationRegex)){
        return true;
    } else {
        return false;
    }
}

//Equations of two numbers
int adding(int num1, int num2){
    return num1 + num2;
}

int subtracting(int num1, int num2) {
    return num1 - num2;
}

int multiplying(int num1, int num2) {
    return num1 * num2;
}

int dividing(int num1, int num2) {
    return num1 / num2;
}
