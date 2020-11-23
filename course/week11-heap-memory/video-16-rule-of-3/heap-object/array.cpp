#include "array.h"

array &array::operator+=(int new_element){
  int *new_array = new int[++num_elements];
  for (size_t i = 0; i < num_elements - 1; i++){
    new_array[i] = elements[i];
  }
  new_array[num_elements - 1] = new_element;
  delete [] elements;    //dealocating old array
  elements = new_array;  //update the pointer to be the new array
  return *this;
}

array array::operator+(int new_element) const {
  array a = *this; 
  /*
  Invocation of the copy constructor, but as we have not defined it at this point it will invokes the default constructor which makes a shallow copy, so they both now are pointing to the same array
  */
  return a+= new_element;
}

array::array(array const &other)
  //deep copy
  : elements(new int[other.num_elements]), num_elements(other.num_elements) //allocating new region of memory
  {
    for (size_t i = 0 ; i < num_elements; i++ ){
      elements[i] = other.elements[i];
    }
  }

array &array::operator=(array const &other){
  delete [] elements;                         // destruction
  elements = new int [other.num_elements];    // copy  construction
  num_elements = other.num_elements;
    for (size_t i = 0 ; i < num_elements; i++ ){
      elements[i] = other.elements[i];
    }
    return *this;

}

using namespace std;

ostream &operator<<(ostream &out, array const &a){
  out << "[";
  for (size_t i = 0; i < a.num_elements; i++){
    out << a.elements[i] 
        << (i == a.num_elements - 1 ? "": ",");
  }
  return out << "]";

}