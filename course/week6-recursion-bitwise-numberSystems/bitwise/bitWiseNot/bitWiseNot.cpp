/*
 Bitwise not is denoted ~ in C++
  - It fips all bits in a number
  - It is sometimes used in combination with & for removing/clearing a bit
 E.g., if x & 1 keeps only the last bit, then x & ~ 1 clears only the last bit

*/

# include <iostream>
using namespace std;

int main(){
int x = 13;      // x     ... 0 1 1 0 1
int y = x & ~ 1; // & ~ 1 ... 0 1 1 0 0 (= 12) clears only the last bit
                      
cout << "clearing only the last bit = " << y << endl;

return 0;
}