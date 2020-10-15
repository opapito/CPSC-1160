#include <iostream>
#include <climits>

using namespace std;

void revert(int n) {
  if (n > 0 ){
    cout << n % 10;
    revert(n / 10);
  } 
}

int main (){
  int n {0};
  cout << "Type a integer to be reverted (e.g. 1234567):" ;
  cin>> n;
  if (!cin){
    cin.clear(); 
    cin.ignore(SSIZE_MAX, '\n');
    cout << "Invalid entry!" << endl;
  }
  revert(n);
  cout << endl;

  return 0;
}