/*
######################################################
Implementation of link list for be used as a queue
######################################################

*/

#ifndef LIST_H
#define LIST_H
#include <iostream>
class list; //prototype

class node {
  int data;
  node *next, *prev; // 2 pointers per node
 public:
  node (int d, node *n = nullptr, node *p = nullptr): data(d), next(n), prev(p){}
  ~node() { delete next; } // recursive deletion 
  node (node const &); // copy constructor
  node &operator=(node const &); // assignment operator
  friend class list;
  friend std::ostream &operator<<(std::ostream &out, node const *); // we need a pointer here because references can not be tested for null, but pointers do
};

class list {
  node *head, *tail;
  void set_prevs_and_tail(); //private helper method
public:
  list():head(nullptr), tail(nullptr){}
  ~list() { delete head; };
  list (list const & ); // copy constructor
  list &operator=(list const &);// assignment operator
  void enqueue(int);
  int serve();
  friend std::ostream &operator<<(std::ostream &out, list const &l){
    return out << "[" << (l.head) << "]";
  }

};

#endif