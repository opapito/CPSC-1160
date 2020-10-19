/*
Question 7 (6 points) 
Your first coding question is to complete the following function:

unsigned short swap_bits(unsigned short x);

If x is even, swap the 2 rightmost bits.

If x is odd, swap the 2 leftmost bits.

For example, if a short is 16 bits in size, then swap_bits(0b10010) should return the number 0b10001.

For example, if a short is 16 bits in size, then swap_bits(0b1011100011100001) should return the number 0b0111100011100001.

Do not make unnecessary assumptions about the size of a short (it may not be exactly 16 bits).

You may copy-and-paste your solution here, or submit it as an attachment. You do not need a main() function, and it will not be tested in a compiler.

*/

# include <iostream>
# include <climits>
using namespace std;

unsigned short swap_bits(unsigned short x){
  if (!(x & 1)) {
    cout << "The number "<< x << " is even" << endl;
    unsigned short last_bit = x & 1;
    cout << "last_bit = " << last_bit << endl;
    unsigned short second_last_bit = (x & 2) >> 1;
    cout << "second_last_bit = " << second_last_bit << endl;
    x &= ~3; 
    x |= last_bit << 1;
    x |= second_last_bit;
    return x;
  } else {
     int size {sizeof x * CHAR_BIT - 1};
      unsigned short bitS = ((x >> size) ^ (x >> (size -1))) & ((1U << x) -1);
      unsigned short r = x ^((bitS << size) | (bitS << (size - 1)));
      return r;

    }
}


int main(){
unsigned short n{0};
cout << "Enter a number:";
cin >> n;

cout << "The resulting number is " << swap_bits(n) << endl; 

}