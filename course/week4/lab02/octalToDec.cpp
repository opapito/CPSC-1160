/*
A program that prompts the user to enter an octal number and displays its decimal equivalent value.
Pablo Bourbom Soares

For example, octalNumber 345 is 229 (3 * 8^2 + 4 * 8^1 + 5 * 8^0 = 229). So, octal2Dec("345") returns 229
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {

int decN{0};

  cout << "Please enter a integer number in octal to be converted to decimal:";
  cin >> decN;
  if (!cin) {
      cout << "Sorry, that was not a valid integer number\n";
  } else {
  
    int rem{0}, exp{0}, num{0};
    do {
      rem = decN % 10;
      decN /= 10;
      num+=rem*pow(8, exp);
      exp++;

    } while (decN != 0);
      cout << "Your number is: " << num << endl;

  }

return 0;
}