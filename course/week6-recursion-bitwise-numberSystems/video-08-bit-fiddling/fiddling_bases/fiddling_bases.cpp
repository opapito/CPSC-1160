#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int fiddling_find(int, int);

int main(){
int n{0};
int p{1};
int result{0};
string message{""};

cout << "Enter a number to find its left fiddling shift corresponding expression: ";
cin >> n;
do {
  result = fiddling_find(n, p);
  message = (result !=0) ? "(x << " + to_string(result) + ")" :  "+ x" ;
  cout << message << endl;
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