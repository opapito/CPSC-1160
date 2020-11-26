#ifndef LIST_H
#define LIST_H
#include <iostream>

class list; //prototype

class node {
  int value;
  node *next;

public:
  node(int v, node *n) : value(v), next(n) {}
  ~node() { delete next; } 
  /*
  Recursively deletion. 
  If it is not the last node, the destructor will keep calling the next node deleting them all until reach the last one
  */
 node(node const &n): value(n.value), next(new node(*n.next)){} //recursively copy constructor
 node &operator=(node const &n){ // assignment operator
   delete next;
   next = new node (*n.next);
   return *this;
 }

  friend std::ostream &operator<<(std::ostream &out, node const *n){ // we need a pointer here because references can not be tested for null, but pointers do
    if (n){
      out << n->next << (n->next ? ", " : "" ) << n->value; 
     /*
      (1) it is recursion. The n->next is a pointer to the next node, so it will keep calling the same left-shift << operator
      (2) printing backwards
     */
    }
    return out;
  }
  friend class list; //necessary for the function of -- operator as it needs to have access to private members

};

class list {
  node *head;
  // as the example to be used is a queue, the instructor decided the HEAD will always be pointing to the END of the list
public:
  list(): head(nullptr){}
  ~list() { delete head; } // destructor

  list(list const &l) : head(new node(*l.head)){} //copy constructor for the rule of 3
  list &operator=(list const &l){ // assignment operator for the rule of 3
    delete head;
    head = new node(*l.head);
    return *this;
  }

  list &operator+=(int x){
    head = new node(x, head); 
    /*
      Here, the head will always be pointing to the last node added
      (1) when adding the first node, the head will be pointing to it and the old head which has a nullpointer will be added to the "next" attribute. The nullpointer at the "next" attribute indicates that node is the last node of tha list, and one list with only one node in fact must have only one node with a nullpointer. An empty list, by its turn, has a nullpointer as head.
      (2) the next nodes added will always pointing to the previous one which is where the old head was pointing to

    */
    return *this;
  }
  friend std::ostream &operator<<(std::ostream &out, list const &l){
    return out << "[" << (l.head) << "]";
  }

  list &operator--(int){ 
  /*
  (1) unary operator which removes the head (last element);
  (2) it is necessary to put int type inside de parethesis in order to -- to work as a postfix operator l--. Without int, it will be prefix operator --l.
  */  
    node * const old_head = head;
    head = old_head->next;
    old_head->next = nullptr; // before to delete it is necessary to set the old head pointer to nullprt
    delete old_head;
    return *this;
  }

};


#endif