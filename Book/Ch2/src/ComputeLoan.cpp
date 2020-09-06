#include <iostream>
#include <cmath>

using namespace std;

int main()
{
// Enter yearly interest rate
cout << "Enter yearly interest rate, for example 8.25: ";
double annualInterestRate;
 cin >> annualInterestRate;

 // Obtain monthly interest rate
 double monthlyInterestRate = annualInterestRate / 1200;
/*
The input for the annual interest rate is a number in percent format, such as
4.5%. The program needs to convert it into a decimal by dividing it by 100.
To obtain the monthly interest rate from the annual interest rate, divide it by
12, since a year has 12 months. To obtain the monthly interest rate in decimal
format, you must divide the annual interest rate in percentage by 1200. For
example, if the annual interest rate is 4.5%, then the monthly interest rate is
4.5/1200 = 0.00375.
*/

 // Enter number of years
 cout << "Enter number of years as an integer, for example 5: ";
 int numberOfYears;
 cin >> numberOfYears;

 // Enter loan amount
 cout << "Enter loan amount, for example 120000.95: ";
 double loanAmount;
 cin >> loanAmount;

 // Calculate payment
 double monthlyPayment = loanAmount * monthlyInterestRate /
 (1 - 1 / pow(1 + monthlyInterestRate, numberOfYears * 12));
 double totalPayment = monthlyPayment * numberOfYears * 12;

 monthlyPayment = static_cast<int>(monthlyPayment * 100) / 100.0;
 totalPayment = static_cast<int>(totalPayment * 100) / 100.0;

 // Display results
 cout << "The monthly payment is " << monthlyPayment << endl <<
 "The total payment is " << totalPayment << endl;

 return 0;
 }