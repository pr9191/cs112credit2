//   CS 112 Spring 2023 - Week 12
//   C++ Number Conversion and Char Input
//   CS 112 Spring 2023 – Extra Credit
//   Peter Rubin


/*  compile using:
        g++ TimeChange2.cpp -o TimeChange2
    run using:
        ./TimeChange2                     */


#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
using namespace std;


/*
Signature: TimeChange: double double -> string
Purpose: a design recipe to a c++ function TimeChange that expects a input of
24 hour form and uses a function then to convert Into a 12 hour notation standard display.
tests:(TimeChange 14:50) == 2:50;
 (TimeChange 13:30) == 1:30;
 (TimeChange 7:40) == 7:40;
 (TimeChange 9:20) == 9:20;
*/

// functions

// full time notation


    string TimeConversion(int TimeMinutes, int TimeHours) {
        string TimePeriod = "A";
        if(TimeHours > 12) {
           TimePeriod = "P";
           TimeHours = (TimeHours - 12);
        }
          return (to_string(TimeHours) + ":" + to_string(TimeMinutes) + TimePeriod + "M");
    } // confuses when converting tostring from char

    string TimeOutput(int TimeMinutes, int TimeHours) {
       return (to_string(TimeHours) + ":" + to_string(TimeMinutes));
    }


int main(){
    int TimeMinutes;
    int TimeHours;
    cout << boolalpha;

    string StopProgram = "stop";
    cout << "Type 'stop' to stop calculations, or type other key to continue" << endl;
    cin >> StopProgram;
    while (StopProgram != "stop"){

    cout << "*** Testing TimeOutput ***" << endl;
    cout << "Please enter your Time In hours: " << endl;
    cin >> TimeHours;
    cout << "Please enter your Time In minutes: " << endl;
    cin >> TimeMinutes;
    cout << "Your current Time Is: " << TimeOutput(TimeMinutes, TimeHours) << endl;

    cout << "*** Testing TimeConversion ***" << endl;
    cout << "Please enter your Time In hours: " << endl;
    cin >> TimeHours;
    cout << "Please enter your Time In minutes: " << endl;
    cin >> TimeMinutes;
    cout << "Your Standard Time Is: " << TimeConversion(TimeMinutes, TimeHours) << endl;

    cout << "Type 'stop' to stop calculations, or type other key to continue" << endl;
    cin >> StopProgram;
    }

    return EXIT_SUCCESS;
}
