/*
**17.6 (Sum series) Write a recursive function to compute the following series:
  m(i) = 1/2 + 2/3 + ... i/i+1
*/
# include <iostream>
using namespace std;

double SumSeries(double n){
  if (n == 0) {
    return 0;
  }
  return n/(n+1) + SumSeries(n-1);
}


int main(){
  for (int i{1}; i < 11; i++){
    cout << SumSeries(i) << endl;
  }
  return 0;
}