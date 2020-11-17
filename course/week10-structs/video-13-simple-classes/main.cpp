#include <iostream>
#include "person.h"

int main(){
  person joe("Joe", "Smith", gender::male);  //there is no new keyword
  std::cout << joe.salutation() << std::endl;
  return 0;
}