//  CS 112 Spring 2023 - Week 12
//   C++ User Input and Size Formulas
//   CS 112 Spring 2023 – Extra Credit
//   Peter Rubin


/*  compile using:
        g++ ClothingSize2.cpp -o ClothingSize2
    run using:
        ./ClothingSize2                     */

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
using namespace std;

/*
Signature: ClothingSize: double double -> double
Purpose: design recipe to design functions for ClothingSize that expects user Input
of size paramters, and returns expected size for different kinds for clothes.
tests:(JacketSize(5.6,150,22)) == 2.91667;
(JacketSize (5.8,170,30)) == 3.42361;
(WaistSize (28,180)) == 31.5789;
(WaistSize (30,172)) == 30.2754;
*/



// functions

// jacket size
 
   double JacketSize(double Age, double userHeight, double userWeight) {
       double tempAge = Age;
       double adjustment = 0;
      while(tempAge >=40) {
         tempAge = tempAge - 10;
           adjustment = adjustment + 1.8;
      }

    return (((userHeight * userWeight)/288) + adjustment);
    }


// hat size
     double HatSize(double userHeight,double userWeight) {
       return ((userWeight/userHeight) * 2.9);
    }

// waist size
      double WaistSize(double userAge, double userWeight) {
      double adjustment = 0;
      double tempAge = userAge;
        while(tempAge >= 30){
            tempAge = tempAge - 2;
            adjustment = adjustment + 0.1;
        }

       return ((userWeight / 5.7) + adjustment);
     }


int main(){
    cout << boolalpha;
    double userHeight;
    double userWeight;
    double userAge;
    double tempAge;
    double Age;
    double adjustment;
    string StopProgram = "stop";
    cout << "Type 'stop' to stop calculations, or type other key to continue" << endl;
    cin >> StopProgram;                // for user to continue, while should use variable
    while (StopProgram != "stop"){

    cout << "*** Testing JacketSize ***" << endl;
    cout << "Please enter your height: " << endl;
    cin >> userHeight;
    cout << "Please enter your weight: " << endl;
    cin >> userWeight;
    cout << "Please enter your age: " << endl;
    cin >> userAge;
    cout << "Your JacketSize Is: " << JacketSize(Age, userHeight, userWeight) << endl;

    cout << "*** Testing HatSize ***" << endl;
    cout << "Please enter your height: " << endl;
    cin >> userHeight;
    cout << "Please enter your weight: " << endl;
    cin >> userWeight;
    cout << "Your HatSize Is: " << HatSize(userHeight, userWeight) << endl;

    cout << "*** Testing WaistSize ***" << endl;
    cout << "Please enter your Age: " <<  endl;
    cin >> userAge;
    cout << "Please enter your weight: " << endl;
    cin >> userWeight;
    cout << "Your WaistSize Is: " << WaistSize(userAge, userWeight) << endl;


    cout << "Type 'stop' to stop calculations, or type other key to continue" << endl;
    cin >> StopProgram;
    }

    return EXIT_SUCCESS;
}
