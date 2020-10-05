#include <iostream>
using namespace std;

void divide(int dividend, int divisor, int *quotient, int *remainder) {
  *quotient = dividend / divisor;
  *remainder = dividend % divisor;
}

int main() {
  int q, r;
  divide(305, 17, &q, &r);
  cout << q << " " << r << endl;
  return 0;
}