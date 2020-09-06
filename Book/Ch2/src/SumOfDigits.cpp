#include <iostream>
using namespace std;

int main()
{
  cout << "Enter a integer between 0 and 1000: ";
  int number{0};
  cin >> number;
  int sum{0};
  sum+= number % 10;
  number= number / 10;
  sum+= number % 10;
  number= number / 10;
  sum+= number % 10;
  cout << "The sum of digits is: " << sum << endl;
  
  return 0;

}