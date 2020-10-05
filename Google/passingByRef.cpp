// Passing parameters by reference.
#include <iostream>
using namespace std;

void Duplicate(int& a, int& b, int& c) {
  a *= 2;
  b *= 2;
  c *= 2;
}

int main() {
  int x = 1, y = 3, z = 7;
  cout << "Passing values"<<" x="<< x << ", y="<< y << ", z="<< z << " BY REFERENCE to the function Duplicate."<< endl;
  Duplicate(x, y, z);
  // The following outputs: x=2, y=6, z=14.
  cout << "Result " << "x="<< x << ", y="<< y << ", z="<< z << endl;
  return 0;
}