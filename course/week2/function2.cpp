// Functions


#include <iostream>
#include <climits>
#include <iomanip> // includes setw

using namespace std;
/*

int geometric_sum(int n){ // int causes overflow afther 46000 due to 2's complement
// 1 + 2 + 2 + 4 + ......+ n
  return n * (n + 1) / 2;

}

*/

/*
long long geometric_sum(long long n){  // this solution of transforming the argument n long long worked for the overflow problem
// 1 + 2 + 2 + 4 + ......+ n
  return n * (n + 1) / 2;

}
*/

long long geometric_sum(int n){  
// 1 + 2 + 2 + 4 + ......+ n
  return n * (n + 1LL) / 2; // LL promotes 1 to long long and, as consequence, all others numbers will also be promoted

}



int main(){
  //cout.width(10);
  for (int i = 0; i < 1000000; i+=1000){
    cout << setw(12) << i << setw(16) << geometric_sum(i) << endl;
  }
  
  return 0;
}