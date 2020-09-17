// Manipulating input stream to read in base sixteen 

// integer can not be store in decimal

#include <iostream>
#include <climits>

using namespace std;

// 'a' 'b' 'c' '\n' '1' '7'
//  ^


int main(){
  int x;
  while (true){
    cout << "please enter a number: " << flush;
    cin >> hex >> x;
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