#include <iostream>
using namespace std;

int main(){
  cout <<"Celsius 35 is Fahrenheit degree " << (9 / 5) * 35 + 32 << endl;
 /*
  You will get Fahrenheit 67 degree, which is wrong. It should be 95. In C++, the division for integers is the quotient. The fractional part is truncated. So 9 / 5 is 1. 
  To get the correct result, you need to use 9.0 / 5, which results in 1.8.
 */
}