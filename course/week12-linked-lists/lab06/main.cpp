#include <iostream>
#include "set.h"
using namespace std;

int main()
{
  set s(6);
  cout << "creating set s with 6 positions.." << endl;
  cout << s << endl;
  cout << "testing copy constructor, and printing out the set b copied" << endl;
  set b(s);
  cout << b << endl;
  cout << "testing assignment operator =, and printing out the set c assingned" << endl;
  set c = s;
  cout << c << endl;
  cout << "Creating the set {1, 2, 4} in set c" << endl;
  s[1] = 1;
  s[2] = 1;
  s[4] = 1;
  cout << s << endl;
  cout << "Creating the set {0, 3, 5} in set b" << endl;
  b[0] = 1;
  b[3] = 1;
  b[5] = 1;
  cout << b << endl;
  cout << "s += b" << endl;
  s+=b;
  cout << s << endl;
  set d(2);
  cout << "Creating the set {0, 0} in set d" << endl;
  cout << d << endl;
  cout << "s += d" << endl;
  s+=d;
  cout << s << endl;
  cout << "d += b" << endl;
  d+=b;
  cout << d << endl;
  cout << "s + c" << endl;
  set sc = s + c;
  cout << sc << endl;
  return 0;
}
