#include <iostream>
#include <climits>
#include <cmath>
#include <iomanip>
#include "functions.h"

using namespace std;

int main() {
  bool valid{false};
  int k{0};
  double result{0};
  while (!valid) {

    cout << "Please enter a number:";
    cin >> k;
    if (!cin || k < 0) {
      cout << "Sorry, that was not a valid positive integer number\n";
      cin.clear();
      cin.ignore(SSIZE_MAX, '\n');
    } else {
      valid = true;
      for (size_t i = 1; i <= k; i++){
        result = 1 - factorial(k)/(pow(k, i) * factorial(k - i));
        cout << setw(3) << i << setw(12) << fixed << setprecision(7) << result << endl;
      }
    };
  };

  return 0;
};