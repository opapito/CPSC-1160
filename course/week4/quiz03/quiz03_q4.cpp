/*
  What is the output of the following code?
*/
#include <iostream>
using namespace std;

int main() {
  int x[] = { 6, 7, 8, 9, 10 };
  int *y = x + 1;
  cout << "x = " << x << " [memory address of the array as well as of its first element] " << endl;
  cout << "adding 1, x + 1 = \n" << x + 1 << " [adding a integer result in the contiguous memory address located after that position] " << endl;
  cout << " In this case, it is the second element of the array" << endl;

  // *y is pointing to the memory address of the second element of the array
  cout << "*y = " << *y << endl;
  
  *y += 2; /* The second element of the array pointed by *y, 7, is added by 2 and becomes 9. The array is now { 6, 9, 8, 9, 10 }
              Here, the arithmetic operation is being performed in the VALUE stored in the memory location pointed by y
            */

  cout << "*y is now pointing for the second element of the array which now has the value of " << *y << endl;
  
  y += 2; /* The memory address stored inside the pointer is added by 2, and now points to fourth element of the array which is also 9
            y[0] now is pointing to fourth element of the array, index 3, which is 9
            Here, the arithmetic operation is being performed in the memory address itself, NOT in the value stored in the memory location
          */
  
  cout << "y [-2]= "<< y[-2] << endl;
  cout << "y [0]= "<< y[0] << endl;
  cout << "y [1]= "<< y[1] << endl;
  cout << "y [-1]= "<< y[-1] << endl;
  cout << "y [-3]= "<< y[-3] << endl;
  
  cout << y[-2] + y[0]  << endl; // as y[0] is pointing to index 3 which is the number 9, y[-2] will point to index 1, which is also the number 9 

return 0;
}
