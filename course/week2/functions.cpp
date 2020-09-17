// Functions


#include <iostream>
#include <climits>

using namespace std;
/*


*/

int geometric_sum(int n){
// 1 + 2 + 2 + 4 + ......+ n
  return n * (n + 1) / 2;

}


int main(){
  int x;
  while (true){
    cout << "please enter a number: " << flush;
    cin >> x;
    //cout << "The value of x is " << x;
    if (!cin) {
      cin.clear(); // DOES NOT CLEAR the buffer , but clears the fail bit, sets the fail state to false
      cin.ignore(SSIZE_MAX, '\n');
    } else{
      break;
    }
  }
  
  cout.width(10);
  //cout << hex << x << endl; // Going back to hex. Typing "fah" will print only "fa" as "h" is NOT a valid base 16 number 
  cout << geometric_sum(x) << endl; // Was not manipulated so it will print out in base 10
  return 0;
}