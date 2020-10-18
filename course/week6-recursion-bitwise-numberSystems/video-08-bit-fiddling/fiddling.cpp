/*
* bit fiddling instructions:
* - CPU has registers (and addressable memory)
* - values are stored as fixed-width sequences of bits:
*   - characters, booleans, intructions, pointers 
* - some instructions applies only for integers: add, substract, multiply, divide
* - instructions for logical operations: OR, AND, NOT, XOR, shifts
*
* x << y == x * 2^y
* x >> y == x / 2^y (it is an integer division, the same of int/int, the remainder is discarded)
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
  cout << "Type a number to check if it is (1) divisible by 2 | (2) divisible by 8 | (3) power of 2:";
  int z;
  cin >> z;
  int number = z;
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

  
  cout << "The number " << number << ((((z >> 1) << 1) == z) ? " is " : " is NOT ");
  cout << " divisible by 2 " << endl; 
  /*
  (1) first method: the last right digit is dropped and then a zero is added at the end, 
  if the number remains the same as before (the operation returns true "1"), it is divisible by 2, 
  so it is an even number
  */
  cout << "The number " << number << (!(z & 1) ? " is " : " is NOT ");
  cout << " divisible by 2 " << endl;                
  /* 
  (2) second method, any EVEN number will give ZERO when used in a AND operation with the
   number one (0000000001)

  8        0000001000            7     0000000111
  1        0000000001     AND    1     0000000001
  =====================        ====================
  0        0000000000            1     0000000001                               
  */
  
  z = number; //returning to original value typed
  
  cout << "The number " << number << (!(z & 7) ? " is " : " is NOT ");
  cout << " divisible by 8 " << endl;                
  /* 
  Method to check division by 8. Any MULTIPLE of 8 will give ZERO when used in a AND operation with the
  number 7 (0000000111)

  8        0000001000           15     0001001111
  7        0000000111     AND    7     0000000111
  =====================        ====================
  0        0000000000            1     0000000111                               
  
  ******************************************************************
  * Check if n is divisible by power of 2 without using arithmetic *
  * ****************************************************************
  Approach: If a number is divisible by 2 then it has its least significant bit (LSB) set to 0, if divisible by 4 then two LSB's set to 0, if by 8 then three LSB's set to 0 and so on. If a number is divisible by 4, the 2 lowest bits are not set therefore (number & 3) should be 0. Similarly, if it is divisible by 2, the lowest bit is not set ((number & 1) == 0) and if it is divisible by 8, the 3 lowest bits are not set ((number & 7) == 0) etc.
  https://www.xspdf.com/resolution/51726767.html
  
  
  */
  z = number; //returning to original value typed
  
  cout << "The number " << number << (!(z & z - 1) ? " is " : " is NOT ");
  cout << " a power by 2 " << endl;                
  /* 
  A number that is a power of two, should only have one 1 set.
  if we subtract 1, all the zeros following will be set to one. 
  If we AND that with the original number we get 0
  

  8        0000001000           8     0000001000
  1        0000000001           7     0000000111
  -                             &
  =====================        ====================
  7        0000000111           0     0000000000                               
  */
  
  z = number; //returning to original value typed
  /*
    Round down to the nearest power of 2.
    e.g., if x is 54, output 32

  */
  int power_of_two {0};
  while ((z >>= 1)){
    power_of_two++;
  }
  cout << "The nearest power of 2 of the number " << number << " is " << ( 1 << power_of_two) << endl;

  

  cout << "Type two number to see the smallest number greater/equal than the first which is divisible by second (which is a power of 2):";
  cin >> x >> y;
  /*
    Output the smallest number greater/equal than x which is divisible by y (y is a power of 2)
    e.g.,
        x = 26    0011010
        y =  4    0000100
            28    0011100
        z = 30    0011110
       ym = y-1   0000011
      ymn = ~y    1111100
  */
  z = ( x | y ) & ~ (y - 1);
  cout << "The number is " << z << endl;


return 0;
}
