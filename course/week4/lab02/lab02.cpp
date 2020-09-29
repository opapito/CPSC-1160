#include <iostream>
#include <climits>
#include <cmath>
#include <iomanip>
#include "functions.h"

using namespace std;

int main() {
  short shortF = SHRT_MAX;
  int intF = INT_MAX;
  long longF = LONG_MAX;
  long long longLF = LONG_LONG_MAX; // It was necessary to create a variable for each type, otherwise, the overloaded name functions won't work.
                                    // When using the constant limits only the long version of the function is called

  // Calling factorial limits function
  cout << "The largest value of n which a SHORT type will not overflow is: " << factorial_limits(shortF) << endl;
  cout << "The largest value of n which a INT type will not overflow is: " << factorial_limits(intF) << endl;
  cout << "The largest value of n which a LONG type will not overflow is: " << factorial_limits(longF) << endl;
  cout << "The largest value of n which a LONG LONG type will not overflow is: " << factorial_limits(longLF) << endl;

  // Start of the Octal do Decimal Function
  int decN{0};

  cout << "Please enter a number in octal:";
  cin >> decN;
  if (!cin) {
    cout << "Sorry, that was not a valid integer number\n";
  }
  else {
    int rem{0}, exp{0}, num{0};
    do {
      rem = decN % 10;
      decN /= 10;
      num += rem * pow(8, exp);
      exp++;

    } while (decN != 0);
    cout << "Your number in decimal is: " << num << endl;
  } 

  bool valid{false};
  int k{0};
  while (!valid) {
    cout << "Please enter a number for probability calculation:";
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