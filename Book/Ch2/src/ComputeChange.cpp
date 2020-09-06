#include <iostream>
using namespace std;

int main()
{
// Receive the amount
cout << "Enter an amount in double, for example 11.56: ";
double amount;
cin >> amount;

 int remainingAmount = static_cast<int>(amount * 100);

 /*
  One serious problem with this example is the possible loss of precision when casting a
  double amount to an int remainingAmount. This could lead to an inaccurate result. If you
  try to enter the amount 10.03, then 10.03 * 100 becomes 1002.9999999999999. You
  will find that the program displays 10 dollars and 2 pennies. To fix the problem, enter the
  amount as an integer value representing cents (see Programming Exercise 2.24).
 */

 // Find the number of one dollars
 int numberOfOneDollars = remainingAmount / 100;
 remainingAmount = remainingAmount % 100;

 // Find the number of quarters in the remaining amount
 int numberOfQuarters = remainingAmount / 25;
 remainingAmount = remainingAmount % 25;

 // Find the number of dimes in the remaining amount
 int numberOfDimes = remainingAmount / 10;
 remainingAmount = remainingAmount % 10;

 // Find the number of nickels in the remaining amount
 int numberOfNickels = remainingAmount / 5;
 remainingAmount = remainingAmount % 5;

 // Find the number of pennies in the remaining amount
 int numberOfPennies = remainingAmount;

 // Display results
 cout << "Your amount " << amount << " consists of " << endl <<
 " " << numberOfOneDollars << " dollars" << endl <<
 " " << numberOfQuarters << " quarters (0.25)" << endl <<
 " " << numberOfDimes << " dimes (0.10)" << endl <<
 " " << numberOfNickels << " nickels (0.05)" << endl <<
 " " << numberOfPennies << " pennies (0.01)" << endl;

 return 0;
 }