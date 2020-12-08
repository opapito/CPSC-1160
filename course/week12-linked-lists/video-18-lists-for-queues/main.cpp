#include <iostream>
#include "list.h"

using namespace std;

int main(){
  list l;
  cout << l << endl;
  l.enqueue(1);
  l.enqueue(2);
  l.enqueue(3);
  cout << l << endl;
  cout<< l.serve()<< endl;
  cout << l << endl;

  list m = l;
  m.enqueue(4);
  cout << l << endl;
  cout << m << endl;

  l = m;
  l.enqueue(5);
  cout << l << endl;  


  return 0;
}


