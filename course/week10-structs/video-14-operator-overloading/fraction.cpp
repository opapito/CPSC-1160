#include "fraction.h"

/*
What is the difference between operator functions and normal functions?
---------------------------------------------------------------------
Operator functions are same as normal functions.
The only differences are:
	(1) name of an operator function is always "OPERATOR" keyword followed by "SYMBOL" of operator; and
	(2) operator functions are called when the corresponding operator is used.

Can we overload all operators?
----------------------------------------------------------------------
Almost all operators can be overloaded except few. Following is the list of operators that cannot be overloaded.
   . (dot) 
   :: 
   ?: 
   sizeof 

-----------------------------------------------------------------------
Important points about operator overloading
1) For operator overloading to work, at least one of the operands must be a user defined class object.

2) Assignment Operator: Compiler automatically creates a default assignment operator with every class. The default assignment operator does assign all members of right side to the left side and works fine most of the cases (this behavior is same as copy constructor). See this for more details.

3) Conversion Operator: We can also write conversion operators that can be used to convert one type to another type.

*/



fraction::fraction(int num, unsigned denom) // as the default value for denom was already informed (denom = 0) in the prototype (fraction.h file)
                                            //, we do not need to specify it again, because the compiler already know about it
  :num(num), denom(denom)
  {
  }

//[return type] [class name] [method name = "operator+="] [explicit RHS parameter] 
//                           [implicit LHS "this" parameter]
fraction &fraction::operator+=(fraction const &other) {

    int new_num = this->num * other.denom + this->denom * other.num;
    unsigned new_denom = this->denom * other.denom;
    this-> num = new_num;
    this-> denom = new_denom;
    return *this; // we use the "star this" ("*this") because in C++ "this" is ALWAYS A POINTER TO A OBJECT and a way to convert a POINTER to a REFERENCE is by using the star "*" operator before it. A reference can be printed directly by cout. It does not need the * before like pointers.
}

fraction fraction::operator+(fraction const &other) const{
  fraction f(this->num, this->denom); // we make a copy (because the original can not be mutated), mutate the copy and then return the result
  return f += other;
}

fraction &fraction::operator*=(fraction const &other){
  num   *= other.num;
  denom *= other.denom;
  return *this;
}

fraction fraction::operator*(fraction const &other) const {
  fraction f(num, denom);
  return f *= other;
}

fraction &fraction::operator/=(fraction const &other) {
  num   *= other.denom;
  denom *= other.num;
  return *this;
}

fraction fraction::operator/(fraction const &other) const {
  fraction f(num, denom);
  return f /= other;
}



std::ostream &operator<<(std::ostream &out, fraction const &f){
  return out << f.num << "/" << f.denom;
}

/*
fraction fraction::operator+(fraction const &other) const{
  //
  //    a     c     ad + bc
  //   --  +  --  = --------
  //    b     d       bd
  //

  return fraction(this->num * other.denom + this->denom * other.num, 
    this->denom * other.denom);

}


int fraction::get_num() const {
  return num;
}

unsigned int fraction::get_denom() const {
  return denom;
}

*/