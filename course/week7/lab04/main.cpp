#include <iostream>
#include <climits>
#include "integer.h"
#include "social_distancing.h"

using namespace std;

int pathCounter{0};

int main(){
int n{2147483647};

cout << "Maximum system integer: " << INT_MAX << endl;
cout << "System bit size: " << CHAR_BIT << endl;

cout << "Highest one bit of " << n << " -> "<< highestOneBit(n) << endl;
cout << "Highest one bit of " << 0 << " -> "<< highestOneBit(0) << endl;
cout << "Highest one bit of " << 1 << " -> "<< highestOneBit(1) << endl;
cout << "Highest one bit of " << 8 << " -> "<< highestOneBit(8) << endl;

cout << "Lowest one bit of " << 157 << " -> "<< lowestOneBit(157) << endl;
cout << "Lowest one bit of " << 64 << " -> "<< lowestOneBit(64) << endl;
cout << "Lowest one bit of " << 0 << " -> "<< lowestOneBit(0) << endl;
cout << "Lowest one bit of " << 8 << " -> "<< lowestOneBit(8) << endl;

cout << "Number of leading zeros of " << 155 << " -> "<< numberOfLeadingZeroes(155) << endl;
cout << "Number of leading zeros of " << 10 << " -> "<< numberOfLeadingZeroes(10) << endl;
cout << "Number of leading zeros of " << 0 << " -> "<< numberOfLeadingZeroes(0) << endl;
cout << "Number of leading zeros of " << 1 << " -> "<< numberOfLeadingZeroes(1) << endl;

cout << "Number of trailing zeros of " << 170 << " -> "<< numberOfTrailingZeroes(170) << endl;
cout << "Number of trailing zeros of " << 24 << " -> "<< numberOfTrailingZeroes(24) << endl;
cout << "Number of trailing zeros of " << 0 << " -> "<< numberOfTrailingZeroes(0) << endl;
cout << "Number of trailing zeros of " << 8 << " -> "<< numberOfTrailingZeroes(8) << endl;

cout << "Rotating left of " << 12 << " by 1 -> "<< rotateLeft(12, 1) << endl;
cout << "Rotating left of " << 16 << " by 2 -> "<< rotateLeft(16, 2) << endl;
cout << "Rotating left of " << 32 << " by 1 -> "<< rotateLeft(32, 1) << endl;
cout << "Rotating left of " << 8 << " by 3 -> "<< rotateLeft(8, 3) << endl;

cout << "Rotating Right of " << 12 << " by 1 -> "<< rotateRight(12, 1) << endl;
cout << "Rotating Right of " << 32 << " by 1 -> "<< rotateRight(32, 1) << endl;
cout << "Rotating Right of " << 16 << " by 2 -> "<< rotateRight(16, 2) << endl;
cout << "Rotating Right of " << 1 << " by 3 -> "<< rotateRight(1, 3) << endl;

paperPath(0,0, &pathCounter);
cout << "Number of paths from top-left corner (0,0) to bottom-right corner (N-1, N-1) -> " << pathCounter << endl;
return 0;
}