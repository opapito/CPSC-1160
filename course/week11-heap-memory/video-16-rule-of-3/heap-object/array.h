#ifndef ARRAY_H
#define ARRAY_H

/*
  You might want to have a class that represent an array in C++ (it is more convinient) because regular arrays are quite awkward in C++, they have a fixed size, decay in pointers and so on
*/

#include <iostream>
class array {
    int *elements; // we gonna represent an array as a pointer into the heap
    size_t num_elements; // it is gonna to be a dinamically sized array
  public:
    array(): elements(nullptr), num_elements(0){}
    ~array(){delete [] elements ;}    // (1) destructor
    /*
      If you do not implement the rule of 3 your code might behave strage with memory leaks errors and so on, and without clearly error messages 
    */
    array(array const &);            //(2) overrinding the copy constructor
    array &operator=(array const &); //(3) overriding the default assignment operator
    array &operator+=(int);
    array operator+(int) const;
    int &operator[](size_t i) { return elements [i] ;} 
    /* 
    Kind of getter and setter (because it is returning a reference "&"). In C++ if you want something work like a getter or setter you must return a reference to it
    */

    friend std::ostream &operator<<(std::ostream &, array const &);
  };


#endif