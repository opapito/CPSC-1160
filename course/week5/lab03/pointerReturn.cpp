/*
Consider the following C++ main function:
  #include <iostream>
  int main()  {
    double vals[] = { 7.5, 3e-6, 1.2'3'4e2, 117.555 };
    double* max = maximum_value(vals, sizeof vals / sizeof vals[0]);
    std::cout << "The maximum is " << *max << std::endl;
  return 0;
  }
Write a maximum value function which will make this code work. Think about what the return type of
the function should be. Think about what the types of the function's 2 parameters must be. The function
should nd the maximum value in an array and then, instead of returning the value, will return a pointer
to that value.

*/


#include <iostream>
using namespace std;
 
double *maximum_value(double *vals, size_t n){
  double max{0};
  size_t maxInd{0};

  for (size_t i = 0; i < n; i++){
    if (vals[i] > max){
      max = vals[i];
      maxInd = i;
    }
  }
return &vals[maxInd];
}
 
int main() {
 double vals[] = { 7.5, 3e-6, 1.2'3'4e2, 117.555 };
 double* max = maximum_value(vals, sizeof vals / sizeof vals[0]);
 std::cout << "The maximum is " << *max << std::endl;
 return 0;
}