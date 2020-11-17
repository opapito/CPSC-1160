#ifndef PERSON_H
#define PERSON_H

#include <string>

enum class gender {
  male, female
};

class person {
private: 
  std::string first_name, last_name;
  gender g;
  std::string title()const;
public:
  person(std::string first, std::string last, gender); // only the prototype
  std::string salutation() const; // const after a method means the method won't modify the object itself, the method will not modify the person object. Makes the method a pure accessor (getter)

}; // must have a semicollon at the end of the end

#endif
