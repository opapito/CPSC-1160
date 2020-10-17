/*
* bit fiddling instructions:
* - CPU has registers (and addressable memory)
* - values are stored as fixed-width sequences of bits:
*   - characters, booleans, intructions, pointers 
* - some instructions applies only for integers: add, substract, multiply, divide
* - instructions for logical operations: OR, AND, NOT, XOR, shifts
*
* x << y == x * 2^y
* x >> y == x / 2^y 
* 
* 235
* 2350
* 23500
*/
# include <iostream>
using namespace std;

int main(){
  int x = 0b101011;
  int y = 0b110010;
  int a = x | y; //OR
  int b = x & y; //AND
  int c = x ^ y; //XOR
  int d = ~x; //binary NOT/NEG
  int e = x << 3; //left shift
  int f = x >> 1; //right shift
  //cout << a << b << c << d << e << f;

  int z;
  cin >> z;
  // multiply by 21
 // cout << "Multiply by 21 = " << ((z << 4) + (z << 2) + z) << endl; //***********************************************
                                 //  z * 16  +  z * 4  + z            // important for the midterm 1
                                                                      //***********************************************
  // 0      0000000000
  // 8      0000001000
  // 16     0000010000
  // 24     0000011000
  // 32     0000100000
  // 40     0000101000
  // 48     0000110000
  // How do I determine if the last three bits are 000 in order to check if the number is divisible by 8, instead of using (n % 8 == 0)?

  // 0      00000
  // 1      00001
  // 2      00010
  // 4      00100
  // 6      00110
  // 8      01000
  // 10     01010
  // 12     01100
  // How I know determine if the last bit is 0 in order to conclude the number is divisible by 2, instead of using (n % 2 == 0)?

  cout << (((z >> 1) << 1) == z) << endl; // (1) first method: all last right digit is dropped and then a zero is added at the end, 
                                          // if the number remains the same (the operation returns true "1"), it is divisible by 2, 
                                          // even number
  cout << !(z & 1) << endl;               // (2) second method, any EVEN number will give ZERO when used in a AND operation with the
                                          // number one
                                          // 8        0000001000            7     0000000111
                                          // 1        0000000001      #     1     0000000001
                                          //=====================           ====================
                                          //0         00000000000           1     0000000001                               

  return 0;
}
