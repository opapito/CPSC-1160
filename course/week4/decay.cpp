# include <iostream>
using namespace std;

int main(){
  int x[] = { 2, 3, 4, 5 };
  cout << x << endl;      // prints the memory addres of the first element of the array
  cout << &x[0] << endl;  // prints the memory addres of the first element of the array
  cout << &x[1] << endl;  // prints the memory addres of the second element of the array
  cout << &x[2] << endl;  // prints the memory addres of the third element of the array
  cout << &x[3] << endl;  // prints the memory addres of the fourth element of the array

  return 0;
}
 