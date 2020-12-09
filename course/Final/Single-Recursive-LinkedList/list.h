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
      next = new node(data); //
    }
  }
  friend class list;
  friend std::ostream &operator<<(std::ostream &out, node const *n){ // we need a pointer here because references can not be tested for null, but pointers do
    if (n){
      out << n->data << (n->next ? ", " : "" ) << n->next; 
     /*
      (1) it is recursion. The n->next is a pointer to the next node, so it will keep calling the same left-shift << operator
      (2) printing forward
      (3) to print backwards just call the next node first recursively, so when the base case is reach it will start to print from the last node to the first.
      Using this format is better visualize the recursion
        out << n->next                // keep checking the next node recursively until reach nullptr (operator left shift operator "<<" keep calling itself)
            << (n->next ? ", " : "" ) // condition check if there is a next node for choose what to print
            << n->data;               // after reach the end, start printing data
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
    if (!head){ // if it is the first element of list which was empty, call add_to_beginning
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