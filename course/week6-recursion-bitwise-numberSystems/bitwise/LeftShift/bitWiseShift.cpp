/*
  A shift is sliding the stream of bits in one direction or the other
  It so happens that x << y will always be equal to x.2^y

  Since << can be used to multiply by a power of 2, we can do it multiply times to multiply by any number
    E.g., x * 10 can be written as (x << 3) + (x << 1)
    This works because 10 = 2^3 + 2^1

*/

# include <iostream>
using namespace std;

int main(){
int x = 7;       //x      0 0 0 0 0 1 1 1
int y = x << 1;  //x << 1 0 0 0 0 1 1 1 0
cout << x << "<< 1 = " << y << endl;

x = 6;       //x      0 0 0 0 0 1 1 0
y = x << 4;  //x << 4 0 1 1 0 0 0 0 0
cout << x << "<< 4 = " << y << endl;

x = 3;
y = (x << 3) + (x << 1);  
cout << "(x << 3) + (x << 1) = " << y << endl;

return 0;
}