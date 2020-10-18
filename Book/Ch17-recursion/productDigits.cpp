/*
***17.11 (Product of digits in an integer using recursion) Write a recursive function that computes the product of the digits in an integer. Use the following function header:
int productDigits(int n) 
For example, productDigits(912) returns 9 * 1 * 2 = 18. Write a test program that prompts the user to enter an integer and displays the product of digits.
*/

#include <iostream>
#include<climits>
using namespace std;

int productDigits (int n){
  if (n / 10 == 0){
    return n;
  } 
    return (n % 10) * productDigits(n / 10);
}


int main(){
int n{0};
bool valid{false};
while (!valid){
  cout << "Enter a number for compute the product of the its digits:";
  cin >> n;
  if (!cin){
    cout << "Invalid entry!";
    cin.clear(); 
    cin.ignore(SSIZE_MAX, '\n');
  } else {
     valid = true;
     cout << "The product of digits is " << productDigits(n) << endl;
  }

}


return 0;
}