# include <iostream>
using namespace std;

int main(){
  int x = 5;          // x is of type "int"
  int* y = &x;        // y is of type "pointer to int"
  cout << x << endl;
  cout << y << endl; // printing memory address to which y is pointing (the one occupied by the variable x)
  cout << *y << endl; // printing the value memory "*" located in memory address pointed by y (the one occupied by x)
return 0;
}
 