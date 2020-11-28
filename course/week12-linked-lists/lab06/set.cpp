/*
* set.h file methods' implementations
* 
*Author: Pablo Bourbom Soares
* 
*/
#include "set.h"


set::set(set const &s) // copy constructor
  : elems(new bool[s.num_elems]), num_elems(s.num_elems)
  //deep copy
  {
    for (size_t i = 0; i < num_elems; i++){
      elems[i] = s.elems[i];
    }
  }

set &set::operator=(set const &s){   // assignment operator
  delete [] elems;                   // destruction
  elems = new bool [s.num_elems];    // copy  construction
  num_elems = s.num_elems;
    for (size_t i = 0 ; i < num_elems; i++ ){
      elems[i] = s.elems[i];
    }
    return *this;
}


set &set::operator+=(set const &s){  // this operator works even if arrays have different sizes
  size_t bigger = std::max(num_elems, s.num_elems);
  bool *new_array = new bool [bigger]{false};
  for (size_t i = 0; i < num_elems; i++){
    new_array [i] |= elems[i];
  }
  for (size_t i = 0; i < s.num_elems; i++){
    new_array [i] |= s.elems[i];
  }
  delete [] elems;
  elems = new_array;
  num_elems = bigger; //updating the size in case of the union of different set sizes
  return *this;
}

set set::operator+(set const &s) const {
  set a = *this;
  /*
  Invocation of the copy constructor, but as we have not defined it at this point it will invokes the default constructor which makes a shallow copy, so they both now are pointing to the same array
  */
  return a += s;

}

// The relative complement or set difference of sets A and B, denoted A – B, is the set of all elements in A that are not in B
set &set::operator-=(set const &s){ 
  bool *new_array = new bool [num_elems]{false};
  for (size_t i = 0; i < num_elems; i++){
    new_array[i] = (elems[i] && !(s.elems[i]));
  }
  delete [] elems;
  elems = new_array;
  return *this;  
}

set set::operator-(set const &s) const{
  set a = *this;
  return a -= s;
}

set &set::operator*=(set const &s){ 
  bool *new_array = new bool [num_elems]{false};
  for (size_t i = 0; i < num_elems; i++){
    new_array[i] = (elems[i] && (s.elems[i]));
  }
  delete [] elems;
  elems = new_array;
  return *this;  
}

set set::operator*(set const &s) const{
  set a = *this;
  return a *= s;
}

set set::operator~() const{ 
  set a = *this;
  for (size_t i = 0; i < a.num_elems; i++){
    a.elems[i] = !(a.elems[i]);
  }
  return a;  
}


std::ostream &operator<<(std::ostream &out, set const &s){
  out << "{";
  bool printed {false};
   for (size_t i = 0; i < s.num_elems; i++){
    if (s.elems[i]){
      if (printed){
        out << ",";
      }
      out << i;
      printed = true;
    } 
  }  
  return out << "}";
}

void set::printBinary(){
  using namespace std;
  for (size_t i = 0; i < num_elems; i++){
    cout << (elems[i] ? "1" : "0"); 
       
  }
    cout << endl;
}
