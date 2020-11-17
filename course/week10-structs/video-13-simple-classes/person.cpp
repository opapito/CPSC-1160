#include "person.h"

using namespace std;

string person::title() const {
  switch (g){
    case gender::male:     return "Mr.";
    case gender::female:   return "Ms.";
  }
}

person::person(string first, string last, gender g)
      :first_name(first), last_name(last), g(g)  // initializers
      {
        //There is no code because the only thing we are doing in our constructor is just to initialize those values
        // what we've done in our initialize list
      }

string person::salutation() const {
  return title() + " " + last_name;
}