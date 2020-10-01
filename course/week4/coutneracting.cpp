# include <iostream>
using namespace std;

int main(){
  int x = 5;
  cout << x << endl;
  cout << &x << endl; // printing memory address of the variable x
  cout << *&x << endl; // printing the value memory "*" located in memory address "&" occupied by x
return 0;
}
 