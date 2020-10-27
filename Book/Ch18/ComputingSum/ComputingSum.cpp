/*
18.3.4 Design an O(n) time algorithm for computing the sum of numbers from n1 to n2 for (n1 < n2). Can you design an O(1) for performing the same task?
*/
# include <iostream>
using namespace std;

int main(){
  int sum = 0;
  int n1{1}, n2{8};
  for (int i = n1; i <=  n2; i++){
    sum += i;
  }
  cout << "The sum of numbers from " << n1 << " to " << n2 << " is " << sum << endl;

  sum = (n2 * (n2 + 1) / 2 ) - (n1 * (n1 - 1) / 2);

  cout << "The sum of numbers from " << n1 << " to " << n2 << " is " << sum << endl;
  
  return 0;        
}