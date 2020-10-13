/*
  A shift is sliding the stream of bits in one direction or the other
  Right shift is denoted >> and works as the inverse to <<
    Note that the rightmost bits will be discarded
      E.g., 13 >> 1 will be 6
        x >> y will always be x.2^-y
    
    If the operand is signed, it does an arithmetic shift, and the sign bit will be extended (copied)

*/

# include <iostream>
using namespace std;

int main(){
int x = -2;       
int y = x >> 1;   // note: arithmetic shift

// x | 1 1 1 0
// y | 1 1 1 1
cout << "y = x >> 1 = " << y << endl;

return 0;
}