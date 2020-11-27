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


set &set::operator+=(set const &s){
  size_t bigger = std::max(num_elems, s.num_elems);
  //(this->num_elems > s.num_elems ? this->num_elems : s.num_elems);
  //std::cout << "bigger->" << bigger << std::endl;
  //std::cout << "this->num_elems->" << this->num_elems << std::endl;
  //std::cout << "s.num_elements->" << s.num_elems << std::endl;
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

std::ostream &operator<<(std::ostream &out, set const &s){
  out << "[";
  
  for (size_t i = 0; i < s.num_elems; i++){
    out << (s.elems[i] ? "1": "0" )
        << (i == s.num_elems - 1 ? "": ",");
  }
  
  return out << "]";

}