/*
*A program that reads in a positive integer k from the user, validates the user input, and then prints out a table of probabilities, for all
*numbers n from 1 to k, with a precision of 7 digits after the decimal point.
*
*Author: Pablo Bourbom Soares
* 
*/
#include <iostream>
#include <climits>
#include <iomanip>
#include "functions.h"

using namespace std;

int main() {
  bool valid{false};
  int k{0};
  while (!valid) {
    cout << "Please enter a number:";
    cin >> k;
    if (!cin || k < 0) {
      cout << "Sorry, that was not a valid positive integer number\n";
      cin.clear();
      cin.ignore(SSIZE_MAX, '\n');
    } else {
      valid = true;
      for (size_t i = 1; i <= (unsigned) k; i++){ 
        cout << setw(3) << i << setw(12) << fixed << setprecision(7) << probability(k, i) << endl;
      }
    };
  };

  return 0;
};