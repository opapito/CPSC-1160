/*
#include <iostream>

class list;
class node {
  long data;
  node *next;
public:
  node(long x, node *n=nullptr) : data(x), next(n) {}
  ~node{} { delete next; }
  friend class list;
};

class list {
  node *head;
public:
  list() : head(nullptr) {}
  ~list() { delete next; }
  void add(long x) { head = new node(x, head); }
  T highest_value() const; 
};

int main() {
  list l;
  l.add(-3);
  l.add(-19);
  l.add(-1.5);
  l.add(-6);
  std::cout << "highest value is " << l.highest_value() << std::endl;
  return 0;
}
Write the highest_value function. For 4/4 marks, do it recursively. For 3/4 marks, do it iteratively. The highest_value function should return the highest value which is contained within the list.

In the interest of brevity, the Rule of 3 is not required for this question. You may make changes to both classes if you wish.

*/
#include <iostream>
using namespace std;

class list;

class node {
  double data;
  node *next;
public:
  node(double x, node *n=nullptr) : data(x), next(n) {}
  ~node() { delete next; }
  friend class list;
  double find_the_highest(double h){
    if (next){      
      h = next->find_the_highest(h);
    }
    if (data > h){
        h = data;
    }
    return h;
  }
};

class list {
  node *head;
public:
  list() : head(nullptr) {}
  ~list() { delete head; }
  void add(double x) { head = new node(x, head); }
  double highest_value() const{
      double h{0};
    if (head){
      h = head->data;
      h = head->find_the_highest(h);
    }
    return h;
  } 
};

int main() {
  list l;
  l.add(-3);
  l.add(-19);
  l.add(-1.4);
  l.add(-1.5);
  l.add(-6);
  std::cout << "highest value is " << l.highest_value() << std::endl;
  return 0;
}