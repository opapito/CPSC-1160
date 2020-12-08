#include "set.h"

set::set(size_t n): elems(new bool[n]), num_elems(n){
  for (size_t i = 0; i < n; i++){
    elems[i] = false;
  }
}
set::~set(){
  delete [] elems;
}

set::set(set const &s): elems(new bool[s.num_elems]), num_elems(s.num_elems){
  for (size_t i = 0; i < num_elems; i++){
    elems[i] = s.elems[i];
  }
}

set &set::operator=(set const &s){
  if (num_elems < s.num_elems){
    delete[] elems;
    elems =  new bool[s.num_elems];
  }
  num_elems = s.num_elems;
  for (size_t i = 0; i < num_elems; i++) {
    elems[i] = s.elems[i];
  }
  return *this;
}

void set::size_to(set const & other){
  if (num_elems < other.num_elems) {
    bool *n = new bool[other.num_elems];
    for (size_t i = 0; i < num_elems; i++){
      n[i] = elems[i];
    }
    for (size_t i = num_elems; i < other.num_elems; i++){
      n[i] = false;
    }
    delete [] elems;
    elems = n;
    num_elems = other.num_elems;
  }
}

set set::operator+(set const &s) const {
  set t = *this;
  return t += s;
}

#define N std::min(num_elems, s.num_elems)

set &set::operator+=(set const &s){
  size_to(s);
  for (size_t i = 0; i < N; i++ ){
    elems[i] |= s.elems[i];
  }
  return *this;
}

set set::operator-(set const &s) const {
  set t = *this;
  return t-= s;
}

set &set::operator-=(set const &s){
  size_to(s);
  for (size_t i = 0; i < N ; i++ ){
    elems[i] &= !s.elems[i];
  }
  return *this;
}

set set::operator*(set const &s) const {
  set t = *this;
  return t *= s;
}

set &set::operator*=(set const &s){
  size_to(s);
  for (size_t i = 0; i < N; i++ ){
    elems[i] &= s.elems[i];
  }
  
  for (size_t i = N; i < num_elems; i++ ){
    elems[i] = false;
  }

  return *this;
}

set set::operator~() const {
  set t = *this;
  for (size_t i = 0; i < num_elems; i++ ){
    t[i] = !t[i];
  }
  return t;
}

bool &set::operator[](size_t i){
  return elems[i];
}

using namespace std;

ostream &operator<<(ostream &out, set const &s){
  out << "{";
  for (size_t i = 0; i < s.num_elems; i++) {
    if(s.elems[i])    out << " " << i;
  }
  return out << " }";
}