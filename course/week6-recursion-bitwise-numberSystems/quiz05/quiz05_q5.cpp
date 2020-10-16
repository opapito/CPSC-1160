/*
Question 5 (4 points) 
This function must be done recursively!! You will not receive credit for a solution if it is not done recursively!!

Write a function which determines how many times an integer can be divided (evenly) by 3. You can complete the following code:

*/
#include <iostream>

using namespace std;

int factor_count_by_3(int n){
  if (n % 3 != 0 || n == 0){
    return 0;
  }
  return 1 + factor_count_by_3(n / 3);
}


int main() {
  using namespace std;
  cout << factor_count_by_3(3) << endl; // should be 1
  cout << factor_count_by_3(0) << endl; // should be 0
  cout << factor_count_by_3(8) << endl; // should be 0
  cout << factor_count_by_3(27) << endl; // should be 3
  cout << factor_count_by_3(162) << endl; // should be 4
  cout << factor_count_by_3(59049) << endl; // should be 10
  return 0;
}