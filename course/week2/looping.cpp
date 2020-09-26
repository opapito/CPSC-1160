// Looping for until a good input is typed

#include <iostream>
#include <climits> // necessary to use cin.ignore()

using namespace std;

// 'a' 'b' 'c' '\n' '1' '7'
//  ^

/* 

When we type an input there is a little cursor in the first letter " ^ " and this cursor indicates which character is about to read next.
Initially, it is in the very beginning in the input, and then it tries to read the character 'a', but as 'a' is NOT a number and it FAILS
and when it fails C++ REFUSES to advance the cursor, so the cursor remains STUCK in the same position it was before. So the loop run again
and tries to read in one more time, BUT the cursor still the first letter 'a' even if there are numbers after it.

So we need to use cin.ignore which will advance the cursor for a size we specify (SSIZE_MAX) until the point we want it to STOP ignoring '\n".

However, this does not fix the problem because cin FAILS to read a valid number to the integer x it ALSO sets the FAIL STATE, another hidden 
ariable in C++ called FAIL BIT or FAIL STATE which initially is set to FALSE but as soon cin fails it sets that bit to TRUE and ANY OPERATION
we try to perform with cin WILL FAIL. It will not even try to do anything. It will immediately fail.

So what we have to do BEFORE ignore is to CLEAR (cin.clear()) the FAIL BIT and set the FAILS STATE TO FALSE

*/

int main(){
  int x;
  while (true){
    cout << "please enter a number: " << flush;
    cin >> x;
    if (!cin) {
      cin.clear(); // DOES NOT CLEAR the buffer , but clears the fail bit, sets the fail state to false
      cin.ignore(SSIZE_MAX, '\n');
    } else{
      break;
    }
  }
  
  cout << x << endl;
  return 0;
}