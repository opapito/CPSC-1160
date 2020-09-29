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
  //cout << "The largest value of n which a SHORT type will not overflow is: " << factorial_limits(shortF) << endl;
  //cout << "The largest value of n which a INT type will not overflow is: " << factorial_limits(intF) << endl;
  //cout << "The largest value of n which a LONG type will not overflow is: " << factorial_limits(longF) << endl;
  //cout << "The largest value of n which a LONG LONG type will not overflow is: " << factorial_limits(longLF) << endl;

  // Start of the Octal do Decimal Function
/*   int decN{0};

  cout << "Please enter a number:";
  cin >> decN;
  if (!cin)
  {
    cout << "Sorry, that was not a valid integer number\n";
  }
  else
  {

    int rem{0}, exp{0}, num{0};
    do
    {
      rem = decN % 10;
      decN /= 10;
      num += rem * pow(8, exp);
      exp++;

    } while (decN != 0);
    cout << "Your number is: " << num << endl;
  } */

  bool valid{false};
  int k{0};
  double kp{0}, numerator{0}, denominator{0}, result{0};
  while (!valid) {

    cout << "Please enter a number:";
    cin >> k;
    if (!cin || k < 0) {
      cout << "Sorry, that was not a valid positive integer number\n";
      cin.clear(); // DOES NOT CLEAR the buffer , but clears the fail bit, sets the fail state to false
      cin.ignore(SSIZE_MAX, '\n');
    } else {
      valid = true;
      kp = k;
      //kp = factorial(kp);
      cout << "kp-> " << kp << " k->" << k << endl;
      for (int i = 1; i <= k; i++){
        numerator = factorial(kp);
        denominator =  pow(kp, i) * factorial(kp - i);
        result = 1 - (numerator/denominator);
        cout << setw(3) << i << setw(12) << fixed << setprecision(7) << result << endl;
       //cout << i << "  " << " factorial(k)-> " << kp << " factorial(k-i)-> " << factorial(pow(kp, i)*(kp - i)) << endl;
       // kp = 1 - factorial(kp)/factorial(pow(kp, i)*(kp - i));
      }
    };
  };

  return 0;
};