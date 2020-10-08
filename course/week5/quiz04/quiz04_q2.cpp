/*
Question 2 (1 point) 
Saved
Consider the following partially complete C++ function:

void swap_first_and_last(int* x, size_t n) {
    int* last_p = &x[n - 1];
    int last_v = x[n - 1];
    // FILL IN NEXT 2 LINES
}

Which 2 lines of code will successfully swap the first and last values in the array?

Question 2 options:

*last_p = x[0];
x[0] = last_v;


x[0] = *last_p;
last_p = &x[0];


last_p = &x[0];
x[0] = *last_p;


x[0] = last_v;
*last_p = x[0];


*/



#include <iostream>

using namespace std;

void swap_first_and_last(int* x, size_t n) {
    int* last_p = &x[n - 1];
    int last_v = x[n - 1];
    *last_p = x[0];
    x[0] = last_v;
}

int main(){
int arr[]{0, 1, 2, 3};
swap_first_and_last(arr, 4);
cout << "Initial array { 0, 1, 2, 3 }" << endl;
cout << "New array: { ";

for (size_t i = 0; i < 4; i++ ) {
  cout << arr[i] << (i == 3 ? "": ", ");
}
  cout << " }" << endl;
  return 0;
}