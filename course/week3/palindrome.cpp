/*
  Macro preprocessing example (run gcc -E to see the preprocessor output)
  This code will generate a bunch of if statements (one for each CHECK)
    #expr \stringifies" the expr parameter (puts double quotes around it)
    __LINE__ is replaced by the line of code where the macro was invoked
  See https://en.cppreference.com/w/cpp/preprocessor/replace
*/

#include <iostream>
using namespace std;

bool is_palindrome(string);

int main() {
#define CHECK(expr, expected) \
  if ((expr) !=(expected)) {\
    cerr << #expr << "failed on line "<<\
     __LINE__<< endl;\
     }

CHECK(is_palindrome("radar"), true);
CHECK(is_palindrome("trampoline"), false);
} 