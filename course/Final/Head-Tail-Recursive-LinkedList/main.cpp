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
  l.add_to_beginning(1);
  l.add_to_beginning(0);
  l.add_to_end(2);
  cout << l << endl;
}


