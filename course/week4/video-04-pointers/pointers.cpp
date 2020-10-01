#include <iostream>

using namespace std;

int main(){
  // There is only one way to store data in a computer: IN BINARY
  // booleans don't exist (sort of)
  // C++ treats booleans and integers very similarly (0 is false, everything else is true)
  // Characters also don't exits! Characters are represented by integers (in C++, this is actually true!)

  char x = 65; // will print 'A' (char is equal "very small integer" x = 65, a integer that fits in only a byte)
  int y = 'A'; // will print 65 (it is equal y = 65 due the single quote '65')
  int z {0b1000001}; // 65 in binary
  int w {0x41};      // 65 in hexadecimal. All those are different syntaxes to say the same thing. 
  int *p = &y;      // p was declared as a pointer to a memory address containing an integer also refered to variable y
                // 
  cout << x << endl
       << y << endl
       << z << endl
       << w << endl;
  cout << p << " " << *p << endl;
  p = &z;
  cout << p << " " << *p << endl;
  
  int a[] = { 5, 10, -5 };
  cout << a << " " << *a << endl; //The "a" will print the memory address of the first element of the array, the second "*a" will print the first element of the array
                                  // You can not store an array in the register. You can only store one element of the array. The others elements must be stored 
                                  // in physical contiguos memory (RAM).
                                  // There is only one situation where the array do NOT decay into a point (first element). 


   
  return 0;
}