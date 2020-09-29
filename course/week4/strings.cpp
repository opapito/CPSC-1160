/*
  In C, there are no strings
    - there is only arrays of characters (char *)
  In C++, there ara TWO forms of strings
    - char * (from C)
    - 'string' class:
      - it is written in lower case;
      - strings are MUTABLE in C++ unlike in Java

Java code
String x = "cat";
x+="dog"; in java it is not possible to change the string. What happens is that Java creates a new string and point it to "dog". It is like x = new String (x+"dog");

C++ code
string x = "cat";
x[1] = 'o'; The string is changed

*/

# include <iostream>
# include <string>
# include "palindrome.h"

using namespace std;

int main() {
  string x;
  //cin >> x; // reads only one word
  getline(cin, x); // reads an entire line
  cout << x << (is_palindrome(x) ? " is" : " is not" ) << " a palindrome" << endl;
  return 0;
  

} // namespace std;

