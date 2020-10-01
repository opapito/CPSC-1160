# include <iostream>
using namespace std;

int main(){
  int x =  5 ;
  int* y = &x;
  cout << y[0] << endl;      // prints the memory addres of the first element of the array
  
  return 0;
}
 