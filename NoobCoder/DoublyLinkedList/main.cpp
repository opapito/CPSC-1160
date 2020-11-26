#include <iostream>
using namespace std;

class Node
{
private:
  /* data */
public:
  int data;
  Node *next;
  Node *prev;
  Node(int data)
  {
    this->data = data;
    next = NULL;
    prev = NULL;
  };
};

class DoublyLinkedList
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
  DoublyLinkedList()
  {
    header = NULL;
    tail = NULL;
    size = 0;
  }

  // deconstructor that does memory cleanup
  // deletes every node within our list when list is out of scope
  ~DoublyLinkedList()
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
      // Make the current last node point to the node we want to append to the list
      tail->next = n;
      // Make our newly appended node point to the previous last node
      n->prev = tail;
      // Make Tail point to the newly appended Node, Because N is the new last Node
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
      /*
      Make first Node within our list point to the node that we want to prepend to the list
      ***********************************************************************************************
      Firstly, remember that HEADER and TAIL are just pointers to the FIRST and LAST linked list nodes.
      They actually don't hold any data. Only nodes they are pointing to holds a field with data, and 
      two other pointers: prev and next 
      ***********************************************************************************************

      (1) As header is always pointing to the FIRST node of the list, we need to make the PREV pointer
      of this node points to the new created node, because this newly created node will now be the
      FIRST node of the list.
      (2) after that, we need that the NEXT pointer of the newly create node points to former first node
      which will be the second now (newly->next = former)
      (3) then we need update the header to point to the newly create node which is now the first node of 
      the list.
      */
      header->prev = n;
      // Make the Node that we want to prepend point to the previous first node within the list
      n->next = header;
      // Update header pointer to point to the newly prepended Node n, Since n is the new first node
      header = n;
    }
    // increment size because we've successfully prepended a new Node to our list
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

  void toStringReverse(){
    // Create a temp pointer that points to the tail
    Node *temp = tail;
    // Create a loop that keeps executing till pointer is NULL (that is when header is reached as the node header is pointing to has NULL in its attribute PREV)
    while (temp != NULL) {
        // print data
        cout << temp->data << " ";
        // advance pointer to next node
        temp = temp->prev;
    }
    cout << endl;
  }

  void removeFirst()
  {
    // Case 1 : check if only one node within list
    if (header->next == NULL){
      delete header;
      header = NULL;
      tail = NULL;
      size--;
    }
    // Case 2 : check if more than one node within list
    else if (header != NULL)
    {                      //if header is NULL, the list is already empty and there is nothing to do
      
      header = header->next;
      delete header->prev;
      header->prev = NULL;
      size--;
    }
  }

  void removeLast()
  {
    // Case 1: check if list has 1 node
    if(header->next == NULL){
      // delete the node
      delete header;
      //set header and tail to NULL
      header = NULL;
      tail = NULL;
      size--;
    }
    // Case 2: check if list has more than 1 Node (if the header->next is NOT equal to NULL and header is NOT NULL, so we can assume there is MORE THAN ONE)
    else if (header != NULL)
    { 
      // advance tail pointer to previous node before it
      tail = tail->prev; // this statement will delete the node tail->prev is pointing to
      // delete the previous last node
      delete tail->next;
      //set the current last node next pointer to NULL
      tail->next = NULL;
      //decrement the size
      size--;
    }
  }

  void removeAt(int pos)
  {
    // Case 1: check if position is a valid position
    if (pos > size || pos < 1)
    {
      return;
    }
    // Case 2: check if position is the first Node
    if (pos == 1)
    {
      removeFirst();
    }
    else if (pos == size)
    { // Case 3: check if Pos is the last Node
      removeLast();
    }
    else if (header != NULL)
    { // Case 4: check if position is between first and last node. The check for null is just for caution, to make sure the list is NOT empty
      Node *cur = header;
      for (int i = 1; i < pos; i++)
      {                  // The condition i < pos will turn cur = the node to be deleted, because it only will stop when "pos" is EQUAL to "i"
        cur = cur->next; // moving for the next node
      }
      cur->prev->next = cur->next;                  
      /*
        "cur->prev" give us the previous node, the one "BEFORE" the current(the one to be deleted).
        Now we want this previous node "BEFORE" to point to the next node "AFTER" the current node, 
        so we need that BEFORE.next(the next pointer stored in BEFORE) to point to AFTER.prev, so we
        do cur->prev->next = cur->next;
      */
      cur->next->prev = cur->prev;
      /*
        Now we need to do the point AFTER the current to point to the node BEFORE the current, so
        cur->next give us the node AFTER the current. 
        Now we want to access the previous pointer and makes it points to node BEFORE the current, so
        whe do cur->next->prev = cur->prev;
      */
      delete cur;
      size--;
    }
  }

  void instertAt(int pos, int data)
  {
    // Case 1: check to see if the possition is valid 
    if (pos > size + 1 || pos < 1)
    { // Here we use size + 1 instead of size alone, because we can achieve size + 1 easily using our append method
      return;
      
    }
    // Case 2: check if insertion at begining of list
    else if (pos == 1)
    {
      prepend(data);
      // Case 3: check if insertion at end of list
    }
    else if (pos == size + 1)
    {
      append(data);
      
    }
    // Case 4: If position is between the begining and end of the list
    else if (header != NULL) // just double checking to making sure list is not empty
    {
      Node *n = new Node(data);
      Node *cur = header;
      for (int i = 1; i < pos; i++)
      {
        cur = cur->next; // transversing the list until achieve the target node
      }
      // these two nodes are now pointing to each other
      cur->prev->next = n;
      n->prev = cur->prev;

      // these two nodes are now also pointing to each other
      n->next = cur;
      cur->prev = n;
      size++;
    }
  }
};

int main()
{
  DoublyLinkedList list;
  list.prepend(3);
  list.prepend(2);
  list.prepend(1);
  list.toString();
  cout << "Linked list size-> " << list.getSize() << endl;
  list.append(4);
  list.append(5);
  list.append(6);
  list.toString();
  cout << "Linked list size-> " << list.getSize() << endl;
  cout << "Printing in revers order" << endl;
  list.toStringReverse();
  cout << "Removing the first item" << endl;
  list.removeFirst();
  list.toString();
  cout << "Linked list size-> " << list.getSize() << endl;
  cout << "Removing the last item" << endl;
  list.removeLast();
  list.toString();
  cout << "Linked list size-> " << list.getSize() << endl;
  cout << "Removing the item in position 2" << endl;
  list.removeAt(2);
  list.toString();
  cout << "Linked list size-> " << list.getSize() << endl;
  cout << "Inserting the item 7 in position 2" << endl;
  list.instertAt(2, 7);
  list.toString();
  cout << "Linked list size-> " << list.getSize() << endl;



  return 0;
}