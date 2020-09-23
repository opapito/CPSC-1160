/*
  Example of a function call
*/

#include <iostream>
using namespace std;

// function declaration (prototype)
double profit (int cost, double price);

int main (){

  double a, b;
  int c;
  cout << "Enter the manufacturing cost of the item: ";
  cin >> c;
  cout << "Enter the retail price of the item: ";
  cin >> b;

  //function call to profit with cost = c and price = b
  a = profit (c, b);
  cout << a << endl;
  return 0;
}

// function definition
double profit (int cost, double price){
  double p; // temporary variable
  p = price - cost ; // calculate the profit
  return p; // return the result to the calling function
}