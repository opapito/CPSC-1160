/*

- basic I/O
- formatted output
   - printing in octal (base 8), hexadecimal (base 16)
   - printing to a specific width (left-aligned, right-aligned)
- input
  - in java --> Scanner kbd = new Scanner(); kbd.nextInt(); kbd.nextLine();
- checking for bad input
  - in java --> try { ... } catch (IOException|ParseNumberException e) { ... }
  - C++ allow exceptions, but is very rare because try catch is very memory expensive operation 

*/ 

#include <iostream>

using namespace std;

int main(){
  int x;
  cin >> x;
  //cout <<"cin failed? " << (cin.fail()) << endl;
  // if (cin.fail()) is the same as if(!cin)
  if (!cin){ // if we put an exclamation before cin, c++ will convert the cin object into a boolean and it will implicitly write ".fail()" for us, so we don't need write ".fail()" by ourselves
    cout << "bad input " << endl;
  } else{
    cout << x << endl;
  }
  //cout << x << endl;
  return 0;
}
