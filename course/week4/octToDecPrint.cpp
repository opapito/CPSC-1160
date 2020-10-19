// Manipulating input stream to read in base octal

// integer can not be store in octal

#include <iostream>
#include <climits>

using namespace std;

/*
Oct is an iostream manipulator. It will manipulate cin to say for now on all inputs will regarding to be in octal, base 8.
It will read the number in base oct and store it in binary in the integer variable x 
Integers can NOT be stored in decimals or octal; Integers can ONLY be stored in binary, so what we can manipulate though is 
whether they are INTERPRETED from the keyboard or whether they are PRESENTED on the screen, we can affect the EXTERNAL representation
of an integer, so when we read cin it would be in base 8, the external representation when we use cout is in base 10.
So cout is going to take our binary integer oct and will interpret it in base 10 
*/


int main(){
  int x;
  while (true){
    cout << "please enter a number: " << flush;
    cin >> oct >> x;
    //cout << "The value of x is " << x;
    if (!cin) {
      cin.clear(); // DOES NOT CLEAR the buffer , but clears the fail bit, sets the fail state to false
      cin.ignore(SSIZE_MAX, '\n');
    } else{
      break;
    }
  }
  
  cout.width(10); // the width will remain UNTIL it is EXPLICITLY CHANGED

  cout << x << endl; // Was not manipulated so it will print out in base 10
  return 0;
}