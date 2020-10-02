/*
Question 6 (5 points)

For the following questions, please either submit, or copy and paste, your working C++ code into the boarr below.

In your main function, create an array of integers which contains the following values: 3, 1, 6, 12, 104, 361, 4, 4, 8, 12.

Your task is to make a C++ program which counts how many elements are greater than the element that comes immediately before. In this case, your output should be 6. The reason is that 6>1, 12>6, 104>12, 361>104, 8>4 and 12>8, so there are 6 elements in total which are greater than the element that comes before.

Your code should not assume anything about the array, and should work on an array of any size.

*/

#include <iostream>
using namespace std;

int main() {
  int arr[] { 3, 1, 6, 12, 104, 361, 4, 4, 8, 12 };
  int counter{0};
  for (size_t i = 0; i < (sizeof arr / sizeof arr[0]) - 1; i++) {
    if (arr[i] < arr[i+1]){
      counter++;
    }
  }
  cout << counter << endl;
  return 0;
};