#include <iostream>
#include <cmath>
#include <climits>
#include "functions.h"

using namespace std;

int main(){
  size_t n {0};
  double arr[100] {0};
  

  cout << "How many numbers should be read? ";
  cin >> n;
  if (!cin){
    cout << "Invalid entry! \nQuitting...\n";
    return 0;
  }

  cout << "Type the " << n << " numbers:"<< endl;
  for (size_t i = 0; i < n ; i++){
    cin >> arr[i];
    if (!cin){
      cin.clear(); // DOES NOT CLEAR the buffer , but clears the fail bit, sets the fail state to false
      cin.ignore(SSIZE_MAX, '\n');
      arr[i] = NAN;
    }
  }
  
  double *max_val = maximum_value(arr, n);
    
  cout << "Excluding the max value " << *max_val << endl;
  *max_val = NAN;


  for (size_t i = 0; i < n; i++){
    if (isnan(arr[i])){
      cout << "The index " << i << " is NAN" << endl;
      //break;
    } else {
      cout << "The number " << arr[i] << " is valid!" << endl;
    }
  }

  mean (arr, n);

  return 0;
}
