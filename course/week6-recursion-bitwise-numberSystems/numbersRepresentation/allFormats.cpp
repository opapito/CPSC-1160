

# include <iostream>
# include <iomanip>
# include <math.h>
#include <bitset>

using namespace std;

int main(){
 int n{0};
 cout << "Please enter a decimal integer number to be represented in octal, binary and hexadecimal : ";
 cin >> n;
  cout <<"\nDecimal: " << n 
       <<"\nOctal: " << oct << n 
       <<"\nBinary: " << bitset<8>(n)  
       <<"\nHexadecimal: " << hex << n 
       << dec << endl;

  return 0;
}

/*
The good solution

While a looping solution still has applicability in some other languages, there is a much more elegant way to do it in C++ that is often overlooked:

int v = 0x12345678;
std::cout << std::bitset<32>(v);
The C++ standard library includes a container type bitset whose first non-type template parameter specifies the number of bits to store. It includes an overload for operator<< and a conversion constructor for ints, making printing binary numbers a piece of cake! This is a much preferred solution to the messy for loop construct above.

To use bitset, remember to add:

#include <bitset>

at the top of your code.
https://katyscode.wordpress.com/2012/05/12/printing-numbers-in-binary-format-in-c/
*/