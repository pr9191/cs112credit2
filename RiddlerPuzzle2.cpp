//   CS 112 Spring 2023 - Week 12
//   C++ Number Loop and Combination
//   CS 112 Spring 2023 – Extra Credit
//   Peter Rubin


/*  compile using:
        g++ RiddlerPuzzle2.cpp -o RiddlerPuzzle2
    run using:
        ./RiddlerPizzle2                     */


#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
using namespace std;


/*
Signature: RiddlerPuzzle: double double -> double
Purpose: design recipe for RiddlerPuzzle that expects a Number Input of four digits thats
representing a combination set, and uses a function for returning the correct riddler address.
// address found for each Input
(RiddlerPuzzle(5,8,6,8)) == (9,8,3,7);
(RiddlerPuzzle(9,4,8,6)) == (9,8,3,7);
(RiddlerPuzzle(6,9,7,5)) == (9,8,3,7);
(RiddlerPuzzle(8,3,9,7)) == (9,8,3,7);
*/


// functions
double AddressDigits[4];

     bool IsDifferent(double new0, double new1, double new2, double new3) {
     double AddressSum = (AddressDigits[0] + AddressDigits[1] + AddressDigits[2] + AddressDigits[3]);
      if (AddressSum == 27){ //
        if(AddressDigits[0] != AddressDigits[1] && AddressDigits[1] != AddressDigits[2] && AddressDigits[2] != AddressDigits[3] && AddressDigits[3] != AddressDigits[0])
        {
         return true;
        }

         else{
            cout << "Not correct order" << endl;
            return false;
         }
        }
        else{

        return false;
      }
   }

// the number is odd
      bool AddressOdd(double new0, double new1, double new2, double new3) {
      double AddressSum = (AddressDigits[0] + AddressDigits[1] + AddressDigits[2] + AddressDigits[3]);

         if (AddressSum == 27){       // use int() conversion for same value
       if (int(AddressDigits[3]) % 2 == 0) {
          cout << "Address type Is even" << endl;
          return false;
       }
          else{
          cout << "Address type Is Odd" << endl;
          return true;
          }
         }
         else{
            return false;
         }
      }

// first digit is 3 times third digit
bool AddressMultiple(double new0, double new1, double new2, double new3) {
double AddressSum = (AddressDigits[0] + AddressDigits[1] + AddressDigits[2] + AddressDigits[3]);
   if (AddressSum == 27){
      if(AddressDigits[0] == (3 * AddressDigits[2])) {
      return true;
      }
      else{
         cout << "not correct order" << endl;
         return false;
      }
   }
      else{

      return false;
      }
   }

int main(){

    cout << boolalpha;


    string StopProgram = "stop";
    cout << "Type 'stop' to stop calculations, or type other key to continue" << endl;
    cin >> StopProgram;
    while (StopProgram != "stop") {

    cout << "*** Testing four digit Find Address ***" << endl;
    cout << "Please enter a number (from 0 to 9), press enter: " << endl;
    cin >> AddressDigits[0];
    cout << "Enter 2nd number (from 0 to 9), press enter: " << endl;
    cin >> AddressDigits[1];
    cout << "Enter 3rd number from 0 to 9: " << endl;
    cin >> AddressDigits[2];
    cout << "Enter 4th number press enter: " << endl;
    cin >> AddressDigits[3];
    cout << "The Address Input Is: (" << AddressDigits[0] << ", " << AddressDigits[1] <<
    ", " << AddressDigits[2] << ", " << AddressDigits[3] << ")" << endl;

    while(IsDifferent(AddressDigits[0], AddressDigits[1], AddressDigits[2], AddressDigits[3]) == false ||
    AddressOdd(AddressDigits[0], AddressDigits[1], AddressDigits[2], AddressDigits[3]) == false ||
    AddressMultiple(AddressDigits[0], AddressDigits[1], AddressDigits[2], AddressDigits[3]) == false){
      AddressDigits[3]++;
      while(AddressDigits[3] > 9){ // increment until Its 9
         AddressDigits[3] -= 10; // and then 4th place Is 0
         AddressDigits[2]++;     // and incement the 3rd place
      }
      while(AddressDigits[2] > 9){
         AddressDigits[2] -= 10;
         AddressDigits[1]++;
      }
      while(AddressDigits[1] > 9){
         AddressDigits[1] -= 10;
         AddressDigits[0]++;
      }
      while(AddressDigits[0] > 9){
         AddressDigits[0] = 0;
         AddressDigits[1] = 0;
         AddressDigits[2] = 0;
         AddressDigits[3] = 0;
      }
    }
    cout << "The solved address Is: ";
    cout << to_string(AddressDigits[0]) << ", " << to_string(AddressDigits[1]) <<
    ", " << to_string(AddressDigits[2]) << ", " + to_string(AddressDigits[3]) << endl;

    cout << "Type 'stop' to stop calculations, or type other key to continue" << endl;
    cin >> StopProgram;
    }

    return EXIT_SUCCESS;
}
