/*
Exclusive or is denoted ^ in C++
It is sometimes used for toggling a bit (setting it if clear, clearing it if set)
E.g., x ^ 1 will toggle the rightmost bit

*/

# include <iostream>
using namespace std;

int main(){
int x = 13;    // x     ... 0 1 1 0 1
int y = x ^ 1; // & ~ 1 ... 0 1 1 0 0 (= 12) toggling the rightmost bit
                      
cout << "Toggling the rightmost bit = " << y << endl;

return 0;
}