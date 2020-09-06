#include <iostream>
using namespace std;
int main()
{
// Enter purchase amount
double purchaseAmount;
cout << "Enter purchase amount: ";
cin >> purchaseAmount;

 double tax = purchaseAmount * 0.06;
 cout << "Sales tax is " << static_cast<int>(tax * 100) / 100.0 << endl;
 cout << "Sales tax WITHOUT CASTING would be " << (tax * 100) / 100.0 << endl;
/*
  Variable purchaseAmount stores the purchase amount entered by the user (lines 7–9).
Suppose the user entered 197.55. The sales tax is 6% of the purchase, so the tax is evaluated
as 11.853 (line 11). The statement in line 12 displays the tax 11.85 with two digits after the
decimal point. Note that
  
  tax * 100 is 1185.3
  static_cast<int>(tax * 100) is 1185
  static_cast<int> (tax * 100) / 100.0 is 11.85
  
  So, the statement in line 12 displays the tax 11.85 with two digits after the decimal point.
*/

 return 0;
 }