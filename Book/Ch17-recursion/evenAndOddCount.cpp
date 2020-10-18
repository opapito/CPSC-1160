/*
**17.8 (Count even and odd digits) Write a recursive function that displays the number of even and odd digits in an integer using the following header:
void evenAndOddCount(int value)
Write a test program that prompts the user to enter an integer and displays the number of even and odd digits in it.
*/
#include <iostream>
#include<climits>
using namespace std;
int nrOfOdd{0};
int nrOfEven{0};


void evenAndOddCount (int value){
  int digit{value % 10};
  if (digit/2 == 0){
    nrOfOdd++;
  } else{
    nrOfEven++;
  }

  if (value / 10 != 0){
      return evenAndOddCount(value / 10);
  }
}

int main(){
int n{0};
bool valid{false};
while (!valid){
  cout << "Enter a number for count the number of even and odd digits:";
  cin >> n;
  if (!cin){
    cout << "Invalid entry!";
    cin.clear(); 
    cin.ignore(SSIZE_MAX, '\n');
  } else {
     valid = true;
     evenAndOddCount(n);
     cout << "The number of odd numbers is: " << nrOfOdd << "\nThe number of even numbers is " << nrOfEven << endl;
  }

}


return 0;
}