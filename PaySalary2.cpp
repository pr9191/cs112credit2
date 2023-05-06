//   CS 112 Spring 2023 - Week 12
//   C++ Decleration and Pay Increase
//   CS 112 Spring 2023 – Extra Credit
//   Peter Rubin

/*  compile using:
        g++ PaySalary2.cpp -o PaySalary2
    run using:
        ./PaySalary2                     */

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
using namespace std;

/*
Signature: PaySalary: double double -> double
Purpose: design recipe to design a C++ function monthlySalary and retroactivePay that expects a number Input
representing a given salary, and outputs the amount of retroactive pay Increase and per month.
tests:(RetroactivePay 40,000) == 1,520;
(RetroactivePay 70,000) == 2,660;
(MonthlySalary 86,000) == 7,439;
(MonthlySalary 90,000) == 7,785;
*/


// functions

     double retroactivePay(double payIncrease, double annualSalary){
       payIncrease += (annualSalary / 2) * .076;
       return payIncrease;
 }

     double MonthlySalary(double payIncrease, double annualSalary){
        payIncrease += (annualSalary / 2) * .076;
       return (annualSalary/12) + (payIncrease/12);
 }

int main(){
    double payIncrease;
    double annualSalary;
    cout << boolalpha;

    string StopProgram = "stop";
    cout << "Type 'stop' to stop calculations, or type other key to continue" << endl;
    cin >> StopProgram;
    while (StopProgram != "stop"){

    // when doing with numbers than conversion cant override with same variable
    cout << "*** Testing retroactivePay ***" << endl;
    cout << "Please enter your annual salary(over 10,000): " << endl;
    cin >> annualSalary;
    cout << "Your 7.6 perecent increase retroactivePay Is: " << retroactivePay(payIncrease, annualSalary) << endl;

    cout << "*** Testing monthlySalary ***" << endl;
    cout << "Your monthlySalary Is: " << MonthlySalary(payIncrease, annualSalary) << endl;

    cout << "Type 'stop' to stop calculations, or type other key to continue" << endl;
    cin >> StopProgram;
    }

    return EXIT_SUCCESS;
}
