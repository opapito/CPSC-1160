#include <iostream>
#include <climits>
#include "integer.h"

using namespace std;

int main(){
int n{2147483647 };
cout << "Maximum system integer: " << INT_MAX << endl;
cout << "System bit size: " << CHAR_BIT << endl;
//cout << sizeof n << endl;
cout << "Highest one bit of " << n << " -> "<< highestOneBit(n) << endl;
cout << "Highest one bit of " << 0 << " -> "<< highestOneBit(0) << endl;
cout << "Lowest one bit of " << 157 << " -> "<< lowestOneBit(157) << endl;
cout << "Lowest one bit of " << 64 << " -> "<< lowestOneBit(64) << endl;
cout << "Lowest one bit of " << 0 << " -> "<< lowestOneBit(0) << endl;
cout << "Number of leading zeros of " << 155 << " -> "<< numberOfLeadingZeroes(155) << endl;
cout << "Number of leading zeros of " << 10 << " -> "<< numberOfLeadingZeroes(10) << endl;
cout << "Number of leading zeros of " << 0 << " -> "<< numberOfLeadingZeroes(0) << endl;
cout << "Number of trailing zeros of " << 170 << " -> "<< numberOfTrailingZeroes(170) << endl;
cout << "Number of trailing zeros of " << 24 << " -> "<< numberOfTrailingZeroes(24) << endl;
cout << "Number of trailing zeros of " << 0 << " -> "<< numberOfTrailingZeroes(0) << endl;

return 0;
}