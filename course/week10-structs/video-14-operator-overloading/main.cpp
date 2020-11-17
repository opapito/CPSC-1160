#include <iostream>
#include "fraction.h"

using namespace std;

int main(){
  fraction f(7,2);
  fraction g(6);
  fraction h = f + g;
  fraction i(3,4);
  fraction i2(3,4);
  i += g;
  i2-=g;

  cout << h << endl
       << i << endl
       << i2 << endl
       << (h * i) << endl;

  /*
  cout << f.get_num() << "/" << f.get_denom()<< endl
       << g.get_num() << "/" << g.get_denom() << endl
       << h.get_num() << "/" << h.get_denom() << endl
       << i.get_num() << "/" << i.get_denom() << endl;
  cout << i2.get_num() << "/" << i2.get_denom()<< endl;
  */
  return 0;
}