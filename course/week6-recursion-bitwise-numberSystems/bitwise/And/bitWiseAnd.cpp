/*
And is one of the most commonly used bitwise operations in C++
It used for masking out certain bits
  "Masking" means to remove all bits other than the one(s) you are interested in
  
*/

# include <iostream>
using namespace std;

int main(){
int x = 13;     // x   ... 0 1 1 0 1
int y = 3;      // y & ... 0 0 0 1 1
int z = x & y;  // z=  ... 0 0 0 0 1
cout << "x = " << x << "\ny = " << y << "\nx & y = " << z << endl;

x = -3;     // x   ... 1 1 1 1 1 0 1
y = 27;     // y & ... 0 0 1 1 0 1 1
z = x & y;  // z=  ... 0 0 1 1 0 0 1
cout << "\nx= " << x << "\ny= " << y << "\nx & y = " << z << endl;

cout <<"\nMasking out certain bits" << endl;
cout << "Cheking if the rightmost bit of y is set: y & 1 = " << (y & 1 ? "YES": "NO") << endl;
cout << "Cheking if the 2nd bit from the right of y is set: y & 2 = " << (y & 2 ? "YES": "NO") << endl;
cout << "Cheking if the 3nd bit from the right of y is set: y & 4 = " << (y & 4 ? "YES": "NO") << endl;

}