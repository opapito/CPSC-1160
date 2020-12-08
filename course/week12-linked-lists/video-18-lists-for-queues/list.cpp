#include "list.h"

node::node (node const &other)
  : data(other.data), next(other.next ? new node(*other.next) : nullptr), prev(nullptr){}

node &node::operator=(node const &n){
  data = n.data;
  if (n.next){
    if (next){
    *next = *n.next; //recursion
    } else{
      next = new node (*n.next);
    }
  } else {
    delete next;
    next = nullptr;
  }
  //delete prev; // see 32:08 video
  prev = nullptr;
  return *this;
}

using namespace std;

ostream &operator<<(ostream &out, node const *n){
  if (!n) return out;
  return out << n->data <<(n->next ? ", " : "")<< n->next;
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

void list::set_prevs_and_tail(){
    node *p = nullptr;
    tail = head;
    while (tail->next){
      tail->prev = p;
      p = tail;
      tail = tail->next;
    }

}

list::list(list const &l)
  : head(new node (*l.head)), tail(nullptr){
    set_prevs_and_tail();
  }
  /*
    (1) head(new node (*l.head)) will recursively call node copy constructor and copy all the nodes of a list
    (2) after that, we recalculate the tail going throught all list until reach the end

  */

 list &list::operator=(list const &l){
   *head = *l.head;
   set_prevs_and_tail();
   return *this;
 }

 void list::enqueue(int new_data){
   node * const new_tail = new node(new_data, nullptr, tail);
   /* (1) as we are adding to the END, there is NO NEXT node, BUT it may have a PREVIOUS
      (2) regardless the list is empty or not, the PREVIOUS of the new node (which will became the new tail) will be the actual TAIL
   */
   if (tail){
     tail->next = new_tail;
   }
   tail = new_tail;
   if (!head){
     head = tail;
   }
 }

 int list::serve(){
   /*
    (1) we are serving from the begining of the list
    (2) if the list had only one node, the tail need to be update as well
   */
    node * const old_head = head;
    head = old_head->next;
    if (head){
      head->prev = nullptr;
    } else {
      tail = nullptr; // if we don't have a head, we also don't have a tail
    }
    int value = old_head->data;
    old_head->next = nullptr;
    delete old_head;
    return value;
 }