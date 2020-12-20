/*
 * Your job is to complete the code for this class.
 * It is a linked list of integers.
 *
 * You may either write the code directly in this file, or put it
 * in a separate .cpp file, whichever you prefer.
 *
 * You may add things to either class (e.g., helper methods), but
 * you may *NOT* remove anything from either class.
 * Some operations MUST be done recursively, in which case you will NEED to create helper methods/functions.
 *
 * You can change the 'struct' into a 'class' if you wish.
 *
 * Total of 21 marks.
 */

#include <iostream>
using namespace std;
class node {
	int data;
	node *next;
  public:
    node (int d, node *n = nullptr): data(d), next(n){}
    ~node() { delete next; } // recursive deletion 
    friend class final_obj;
    friend std::ostream &operator<<(std::ostream &out, node const *n){
      if (!n) return out;
      return out << n->data <<(n->next ? " " : "")<< n->next;
    }; 
};

class final_obj {
	node *head;
	size_t size;	// you must keep track of the number of nodes in the list (initially 0)
public:
	final_obj():head(nullptr), size(0){};	// initialize an empty list (1 mark)
	
	// write the rule of 3 (3 marks)
  ~final_obj() { delete head; }                        // destructor

  final_obj(final_obj const &f) : head(new node(*f.head)){}   // copy constructor for the rule of 3
  final_obj &operator=(final_obj const &f){                   // assignment operator for the rule of 3
    delete head;
    head = new node(*f.head);
    return *this;
  }

	void add(int data){// add a new element at the head of the list (1 mark)
    node *new_node = new node(data, head); 
    head = new_node;
    size++;
  }	

	friend std::ostream &operator<<(std::ostream &out, final_obj const &f){ // print with spaces separating elements (2 marks)
    return out << "[" << (f.head) << "]";
  }	

	/*
	 * Allocate a new array on the heap. The array will contain every values of the list, BUT NOT IN ORDER.
	 * The element at the middle goes into index 0, element at mid+1 goes into index 1, mid-1 goes into index 2,
	 * mid+2 goes into index 3, mid-2 goes into index 4, and so on.
	 * Round down to find the midpoint.
	 * E.g., if the list contains values 3, 6, 9, 12, 15, 18, your array must contain the values 9, 12, 6, 15, 3, 18.
	 *
	 * YOUR SOLUTION MUST BE RECURSIVE!!!
	 * (5 marks, max 2/5 if non-recursive)
	 */
	int *shuffle(){
      int *arr = new int[size];
      size_t const middle = (size/2);
      allocate(int *arr, middle);
      return arr;
  };

  void allocate(int *arr, size_t middle){
    if (middle =< 1 || middle => size){
      return;
    }
    allocate(int *arr, middle/2);
    arr[middle] = 

  }

	/*
	 * Go through the list and remove all nodes which are not greater than the node that came immediately before.
	 * E.g., if the list initially contains 4, 7, 3, 5, 5, 10, 2, after this operation, your list would be 4, 7, 5, 10
	 *
	 * YOUR SOLUTION MUST BE RECURSIVE!!
	 * (4 marks, max 2/4 if non-recursive)
	 */
	void make_ascending(){
    node *prev;
    node *cur = head;
      for( int i = 0; i < size; i++){
        prev = cur;
        cur = cur->next;
        if (cur->data < prev->data){
          prev->next = cur->next;
          cur->next = nullptr;
          delete cur;
          size--;
        }
      }
  }

	/*
	 * Add a new node to the linked list such that the list will then become "partitioned".
	 * All values less than 'x' will be to the left of it (not necessarily in order, though) and
	 * all values greater than 'x' will bo the right of it.
	 *
	 * This does not need to be recursive, and will require creating ONLY ONE new node.
	 * (5 marks)
	 */
	void fun_add(int x){
    int middle = (size/2);
    node *n = new node(x);
    node *prev;
    node *cur = head;
    //inserting node in the middle
      for( int i = 0; i < middle; i++){
        prev = cur;
        cur = cur->next;
      }
      prev->next = n;
      n->next = cur;
      size++;
     //temporary list
      final_obj tmp;
      int count {0};
      cur = head;
      for( int i = 0; i < size || count < middle; i++){
        cur = cur->next;
        if ((cur->data) < x){
          tmp.add(cur->data);
          count++;
        }
      }
      int count = 0;
      cur = head;
      for( int i = 0; i < size; i++){
        cur = cur->next;
        if ((cur->data) > x && i > middle){
          tmp.add(cur->data);
          count++;
        }
      }
      this* = tmp;
      delete tmp;
    }

  /*
  ******************************************
  * Serfs version                          * 
  ******************************************
  void final_obj::fun_add(int x){
    final_obj temp;

    node* current = head;

    // create right side
    while(current){
        if(current->data > x)
            temp.add(current->data);
        current = current->next;
    }

    // add values which are equal, you didn't specify what to do with these ones
    current = head;
    while(current){
        if(current->data == x)
            temp.add(x);
        current = current->next;
    }

    temp.add(x); // add extra value

    // create left side
    current = head;
    while(current){
        if(current->data < x)
            temp.add(current->data);
        current = current->next;
    }

    (*this) = temp;
  }
*/
 
};



int main(){
  final_obj f;
  f.add(1);
  f.add(2);
  f.add(7);
  f.add(4);
  f.add(5);
  f.add(6);
  cout << f << endl;
  f.fun_add(3);
  cout << f << endl;
}


