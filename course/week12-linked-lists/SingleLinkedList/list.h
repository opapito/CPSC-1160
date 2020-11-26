#ifndef LIST_H
#define LIST_H
#include <iostream>
class list; //prototype

class node {
  int data;
  node *next;
 public:
  node (int d, node *n = nullptr): data(d), next(n){}
  ~node() { delete next; }
  void add (int data){
    if (next){
      next->add(data); //recursively search for the last node (the one with next equal nullptr)
    } else{
      next = new node(data);
    }
  }
  friend class list;
  friend std::ostream &operator<<(std::ostream &out, node const *n){ // we need a pointer here because references can not be tested for null, but pointers do
    if (n){
      out << n->data << (n->next ? ", " : "" ) << n->next; 
     /*
      (1) it is recursion. The n->next is a pointer to the next node, so it will keep calling the same left-shift << operator
      (2) printing backwards
     */
    }
    return out;
  }
};

class list {
  node *head;
public:
  list():head(nullptr){}
  ~list() { delete head; }
  void add_to_beginning(int data){
    node *new_node = new node(data, head); // The actual head is to where the new node "next" attribute will be pointing to, as the new node will be the first in the list now
    head = new_node;  //setting head to pointing to the new node now
  }
  void add_to_end(int data){
    if (!head){ // it is the first element of the list, call add_to_beginning
      add_to_beginning(data);
    } else {
      head->add(data);
    }
  }
  friend std::ostream &operator<<(std::ostream &out, list const &l){
    return out << "[" << (l.head) << "]";
  }

};

#endif