/*
In the previous array class example

                  array         linked list       BST
                  ======       ============     =======
retrieve []        O(1)             O(n)        O(long n)
append +=          O(n)             O(1)        O(long n)
search             O(n)             O(n)        O(long n)
deletion
  from the end     O(1)             O(1)        O(long n)

Linked lists performance do not differ too much from arrays, but they are more efficient for insert at begining and at the end.
For that reason, Linked lists are the better structure to work with stacks and queues

*/
#include "list.h"

using namespace std;

int main(){
  list l;
  cout << l << endl;
  l += 1;
  cout << l << endl;
  l += 2;
  cout << l << endl;
  l--;
  cout << l << endl;
  l += 2;
  l += 3;
  l += 4;
  l += 5;
  cout << l << endl;
  cout << "Size-> " << l.getSize()<< endl;
  l.revert();
  cout << l << endl;
  cout << l.delete_at(2) << endl;
  cout << l << endl;
  cout << "Size-> " << l.getSize()<< endl;
  cout << l.delete_at(2) << endl;
  cout << l << endl;
  cout << "Size-> " << l.getSize()<< endl;
  cout << l.delete_at(7) << endl;
  cout << l << endl;
  cout << "Size-> " << l.getSize()<< endl;
  cout << l.delete_at(1) << endl;
  cout << l << endl;
  cout << "Size-> " << l.getSize()<< endl;
  cout << "l[0] = " << l[0] << endl;
  l[0]=10;
  cout << "l[0] = " << l[0] << endl;
  cout << l << endl;

  return 0;
}


