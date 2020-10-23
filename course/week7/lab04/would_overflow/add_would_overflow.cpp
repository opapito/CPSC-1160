
# include <iostream>
# include <climits>
using namespace std;

bool add_would_overflow(unsigned int n, unsigned int m){
  return ((n + m) < n);
}

//https://stackoverflow.com/questions/199333/how-do-i-detect-unsigned-integer-multiply-overflow/1514309#1514309 
bool add_would_overflow(signed int n, signed int m) {
  if ((n > 0) && (m > INT_MAX - n)){
    return true;
  }
  if ((n < 0) && (m < INT_MIN - n)){
    return true;
  }
  return false;
}


int main(){
unsigned int n{UINT_MAX};
int o{INT_MAX};

cout << n << " + 1 " << " would overflow? " << (add_would_overflow(n, 1U) ? " YES" : "NO") << endl;
cout << o << " + 1 " << " would overflow? " << (add_would_overflow(o, 1) ? " YES" : "NO") << endl;
cout << o << " - 1 " << " would overflow? " << (add_would_overflow(o, -1) ? " YES" : "NO") << endl;

return 0;
}