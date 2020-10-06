/*
*A program that reads in a list of temperatures from standard input and prints out the average temperature, ignoring the highest temperature.
*
*Author: Pablo Bourbom Soares
* 
*/

#include <iostream>
#include <cmath>
#include <iomanip>
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
  
  if (n < 2) {
      cout << "\nIt is necessary at least 2 valid entries!\nExiting..." << endl;
      return 0;
  }
  
  cout << "Type the " 
       << n 
       << " numbers:"
       << endl;

  for (size_t i = 0; i < n ; i++){
    cin >> arr[i];
    if (!cin){
      cin.clear(); 
      cin.ignore(SSIZE_MAX, '\n');
      arr[i] = NAN;
    }
  }
  
 
  double *max_val = maximum_value(arr, n);
 
  *max_val = NAN;  //setting the max value to NAN
  
  double result{mean (arr, n)};

  if (!result){
    cout << "\nAll entries were invalid!\nExiting..."
         << endl;
  } else{
    cout << "The average temperature is " 
          << fixed
          << setprecision(1)
          << result
          << endl; 
  }

  return 0;
}
