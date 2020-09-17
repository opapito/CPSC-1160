/*
Question 4 (1 point) 
In your IDE of choice (maybe https://repl.it), write a C++ program which:

Prints out your name
Reads in an integer. (You do not have to check for errors)
Prints out the negative of that integer (e.g., if the user enters 3, print out -3)
Take a screenshot of your program running and submit it here. You should be able to submit an image to this question by clicking on the "camera" icon at the top.

To be clear, I do not want you to write code here. I want you to submit a screenshot. That will help me feel confident that everybody in the class has an environment set up that will let them do work.
*/

#include <iostream>

using namespace std;

int main(){
  cout << "Soares, Pablo Bourbom\n";
  int number{0};
  cout << "Enter a integer: ";
  cin >> number;
  cout << -(number) << endl;
  return 0;
}
