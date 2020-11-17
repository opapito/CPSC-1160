#ifndef   FRACTION_H
#define   FRACTION_H

#include <string>
#include <iostream>

class fraction {
  int num;
  unsigned denom;
public:
  fraction(int num, unsigned denom=1); //default parameter value (denom = 1)
  fraction &operator+=(fraction const &other); 
  /* 
  *  It DOES NOT have "const" keyword in the return type definition because it MUTATES the LEFT hand operator.
   * We also need to return a REFERENCE to the object mutated, this is why we put the & before the LEFT hand side
  */
  fraction operator+(fraction const &other) const; 
  /*
  *  It HAS "const" in the return type definition because it DOES NOT mutate the LEFT hand operator. Plus operators always have CONST in the return type
  *  When leading with BINARY operators(those with two operands, one of the left of the plus sign "+" and one on the right)
  * , the operator on the LEFT hand side will be the IMPLICIT PARAMETER THIS, the parameter on the RIGHT hand side will
  *  be the EXPLICIT PARAMETER
  */
  fraction &operator-=(fraction const &other){return *this += -other; }
  fraction operator-(fraction const &other) const {return *this + -other; }
  fraction operator-() const {return fraction(-num, denom); } //unary operator (negation operator)

  friend std::ostream &operator<<(std::ostream &, fraction const &);
  /*
  The keyword friend does two things:
  (1) it is going to indicate that the ostream operator << is NOT a function, BUT a method
  (2) is going to declare a friend relationship (only one way, the friend function will be friend of the class, with access to its private variables, BUT the class will not be friend of the ostream operator. The class will not have access to ostream operator variables)
  */
  fraction &operator*=(fraction const &other);
  fraction operator*(fraction const &other) const;

  fraction &operator/=(fraction const &other); 
  fraction operator/(fraction const &other) const; 


/*
  int get_num() const;
  unsigned int get_denom() const;
*/
};

#endif