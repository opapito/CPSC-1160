#include <iostream>
#include<climits>
using namespace std;

int gcd (int m, int n){
  if (m % n == 0){
    return n;
  } 
    return gcd (n, m % n);
}


int main(){
int m{0}, n{0};
bool valid{false};
while (!valid){
  cout << "Enter 2 number for GCD:";
  cin >> m >> n;
  if (!cin){
    cout << "Invalid entry!";
    cin.clear(); 
    cin.ignore(SSIZE_MAX, '\n');
  } else {
     valid = true;
     cout << "The gcd is " << gcd(m, n) << endl;
  }

}


return 0;
}