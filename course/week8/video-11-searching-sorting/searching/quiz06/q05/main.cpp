/*
Question 5 (4 points) 
Write a C++ function which will search for TWO elements. The two elements must be right next to each other, contiguously. The prototype of the function should be:

bool search_adjacent_elements(int const *x, size_t n, int target1, target2);

It will return true if target1 and target2 exist in the array x somewhere, with target1 immediately to the left of target2. For example:

int x[] = { 3, 5, 10, 14, 19, 25, 45, 60 };
cout << search_adjacent_elements(x, sizeof x / sizeof x[0], 10, 14) << endl;  // true!!
cout << search_adjacent_elements(x, sizeof x / sizeof x[0], 25. 19) << endl;  // false (wrong order)
cout << search_adjacent_elements(x, sizeof x / sizeof x[0], 25, 60) << endl;  // false (not right next to one another)

You may assume the array is ordered.

Your function must only search through your array once. If you search through your array multiple times (e.g., search once for target1, then search again for target2), you will receive a 2 mark deduction.

You may use any code we have used in class as a reference. If referencing code from online, you must include a comment with a link to where you got it from.

For a maximum 3/4 marks, do a linear search.

For a maximum 4/4 marks, do a binary search.

*/
# include <iostream>
using namespace std;

bool linear_search_adjacent_elements(int const *x, size_t n, int target1, int target2){
  for (size_t i{0}; i < n ; i++){
    if ((x[i] == target1) && (i != n - 1)) {
        if (x[i + 1] == target2){
          return true;
        }
    }
    
  }
  return false;
}

bool search_adjacent_elements(int const *x, size_t n, int target1, int target2){
  if (n == 0){
    return false;
  }
  size_t const halfIndex = n / 2;
  cout << "halfIndex-> " << halfIndex << " x[halfIndex]= " << x[halfIndex] << " n - 1 = " << n - 1 << " n = " << n << endl;
  if ((x[halfIndex] == target1) && (x[halfIndex + 1] == target2)){
    return true; 
  } else if (x[halfIndex] < target1){
    return search_adjacent_elements(&x[halfIndex + 1], n - halfIndex - 1, target1, target2);
  } else{
    return search_adjacent_elements(&x[0], halfIndex, target1, target2);
  }
  return false;
}

int main (){

int x[] = { 3, 5, 10, 14, 19, 25, 45, 60 };
//cout << linear_search_adjacent_elements(x, sizeof x/sizeof x[0], 10, 14) << endl;
//cout << linear_search_adjacent_elements(x, sizeof x/sizeof x[0], 25, 19) << endl;
//cout << linear_search_adjacent_elements(x, sizeof x/sizeof x[0], 25, 60) << endl;
//cout << linear_search_adjacent_elements(x, sizeof x/sizeof x[0], 60, 60) << endl;
cout << search_adjacent_elements(x, sizeof x/sizeof x[0], 10, 14) << endl;
cout << search_adjacent_elements(x, sizeof x/sizeof x[0], 25, 19) << endl;
cout << search_adjacent_elements(x, sizeof x/sizeof x[0], 25, 60) << endl;
//cout << search_adjacent_elements(x, sizeof x/sizeof x[0], 60, 60) << endl; // out of bounds issue
cout << search_adjacent_elements(x, sizeof x/sizeof x[0], 14, 19) << endl;
cout << search_adjacent_elements(x, sizeof x/sizeof x[0], 45, 60) << endl;
cout << search_adjacent_elements(x, sizeof x/sizeof x[0], 3, 5) << endl;

}
