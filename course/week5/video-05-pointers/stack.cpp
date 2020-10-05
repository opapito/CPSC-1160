#include <iostream>
using namespace std;

int main(){
int x {5};
int y {6};
int z[] {3, 4};
int *a = &x;

cout << a << endl;   // memory addres of the pointee stored in a
cout << *a << endl;  // follow the arrow -> value stored in the pointee variable x
cout << &a << endl;  // memory address of the pointer itself

a=&z[1];              // a now is pointing to the second element of the array z
cout << a << endl;    // memory addres of the new pointee z[1] stored in a
cout << &a << endl;   // memory address of the pointer itself
cout << a[0] << endl; // value of the second element of the array z
cout << a[-1] << endl; // value of the first element of the array z



  return 0;
}
