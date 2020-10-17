#include <iostream>
#include <cmath>
using namespace std;

int fiddling_find(int, int);

int main(){
int n{0};
int p{1};
int result{0};
cout << "Enter a number to find fiddling bases 2 composition: ";
cin >> n;
do {
  result = fiddling_find(n, p);
  cout << (result !=0) ? "(x << " << result << ")" << : << "+ x" << endl;
  n = n - pow(2, result);

} while (n > 0);
return 0;
}

int fiddling_find(int n, int p){
  if ( n < pow(2, p)){
    return p-1;
  }
  fiddling_find(n, p + 1);
}