#include <iostream>
using namespace std;

class Node
{
private:
  /* data */
public:
  int data;
  Node *next;
  Node(int data)
  {
    this->data = data;
    next = NULL;
  };
};

class LinkedList
{
private:
  // pointer which always points to the first node within our linked list
  Node *header;
  // pointer which always points to the end node within our linked list
  Node *tail;
  // keeps tracks of how many nodes are within our list
  int size;

public:
  // default constructor which initializes our private data members
  LinkedList()
  {
    header = NULL;
    tail = NULL;
    size = 0;
  }

  // deconstructor that does memory cleanup
  // deletes every node within our list when list is out of scope
  ~LinkedList()
  {
    // pointer which always points to the next node within our list
    Node *next;
    // keep going until header does not equal NULL
    while (header != NULL)
    {
      // advance to pointer to point to next node
      next = header->next;
      // delete node that header is pointing to
      delete header;
      // advance header to point to the next node
      header = next;
    }
  }

  int getSize()
  {
    return size;
  }

  // adds a new node to the end of our list
  void append(int data)
  {
    // Newly created node to be inserted
    Node *n = new Node(data);

    // Case 1: Empty List (header is NULL)
    if (header == NULL)
    { // When adding the first element into an empty list, the header and the tail will be pointing to the same place
      header = n;
      tail = n;
    }
    else
    { // Case 2: List is not empty. It has at least one element.
      tail->next = n;
      tail = n;
    }
    // Increment size counter
    size++;
  }

  // adds a new node to the beginning of our list
  void prepend(int data)
  {
    // newly created node to be inserted
    Node *n = new Node(data);
    // Case 1 : Empty List
    if (header == NULL)
    {
      header = n;
      tail = n;
    }
    else
    { // Case 2 :  List is not empty
      // temp pointer which saves what header is currently pointing to
      Node *temp = header;
      // update header to point to n, the new node that we want to prepend
      header = n;
      // make our new node n next pointer point, to the previous first node
      n->next = temp;
    }

    //Increment the size because we've successfully inserted a new node
    size++;
  }

  void toString()
  {
    //Create a temp pointer that points to first Node
    Node *temp = header;

    //Create a loop that stops when pointer is NULL
    while (temp != NULL)
    {
      //Print data
      cout << temp->data << " ";
      //Advance Pointer to next node
      temp = temp->next;
    }

    cout << endl;
  }

  void removeFirst(){
    // Case 1 : empty list
    // Case 2 : not empty list
    if (header != NULL){ //if header is NULL, the list is already empty and there is nothing to do
      Node *temp = header; // we need to store the address of memory in heap in order to delete it after
      header = header->next;
      delete temp; // preventing memory leak
      size--;
    }

  }
  void removeLast(){
    // Case 1: Empty (no need test)
    // Case 2: 1 Node
    if(header-> next == NULL){ // The node has only one node
      removeFirst();
    } else if(header != NULL) { // Case 3 : More than one
      Node *cur = header;
      Node *prev;
      while(cur->next != NULL){
        prev = cur;       // saving the current position
        cur = cur->next;  // moving for the next node
      }
      tail = prev;
      prev->next = NULL;
      delete cur; // preventing memory leak
      size --;
    }
  }

  void removeAt(int pos){
    // Case 1: check for valid position
    if (pos > size || pos < 1){
      return;
    }
    // Case 2: check if position is the first Node
    if (pos == 1){
      removeFirst();
    } else if (pos == size){ // Case 3: check if Pos is at las Node
      removeLast();
    } else if(header != NULL){ // Case 4: all other cases. The check for null is just caution
      Node *prev;
      Node *cur = header;
      for (int i = 1; i < pos; i++){ // The condition i < pos will turn cur = the node to be deleted, because it only will stop when "pos" is EQUAL to "i"
        prev = cur;       // saving the current position
        cur = cur->next;  // moving for the next node
      }
      prev->next = cur->next;
      delete cur;
      size--;
    }
  }

  void instertAt(int pos, int data){
    // Case 1: check for valid pos
    if ( pos > size + 1 || pos < 1 ){ // Here we use size + 1 instead of size alone, because we can achieve size + 1 easily using our append method
      return;
    // Case 2: check if insertion at begining of list
    } else if (pos == 1) {
      prepend(data);
    // Case 3: check if insertion at end of list
    } else if (pos == size + 1){
      append(data);
    // Case 4: all other cases
    } else if (header != NULL){
      Node *n = new Node(data);
      Node *prev;
      Node *cur = header;
      for( int i = 1; i < pos; i++){
        prev = cur;
        cur = cur->next;
      }
      prev->next = n;
      n->next = cur;
      size++;

    }
  }

};

int main()
{
  LinkedList list;
  list.append(1);
  list.append(2);
  list.append(3);
  list.prepend(10);
  list.toString();
  cout << "Linked list size-> " << list.getSize() << endl;
  list.removeFirst();
  list.toString();
  cout << "Linked list size-> " << list.getSize() << endl;
  list.prepend(11);
  cout << "Adding the number 11" << endl;
  list.toString();
  cout << "Linked list size-> " << list.getSize() << endl;
  list.removeLast();
  cout << "Removing the last" << endl;
  list.toString();
  cout << "Linked list size-> " << list.getSize() << endl;
  cout << "Removing the item on the index 2" << endl;
  list.removeAt(2);
  list.toString();
  cout << "Linked list size-> " << list.getSize() << endl;
  cout << "Inserting the item 12 on the index 2" << endl;
  list.instertAt(2, 12);
  list.toString();
  cout << "Linked list size-> " << list.getSize() << endl;
  return 0;
}