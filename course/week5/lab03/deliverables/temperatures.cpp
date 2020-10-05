/*
*A program that reads in a list of temperatures from standard input and prints out the average temperature, ignoring the highest temperature.
*
*Author: Pablo Bourbom Soares
* 
*/

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
  
  size_t valid_entries{n};

  cout << "Type the " << n << " numbers:"<< endl;
  for (size_t i = 0; i < n ; i++){
    cin >> arr[i];
    if (!cin){
      cin.clear(); 
      cin.ignore(SSIZE_MAX, '\n');
      arr[i] = NAN;
      valid_entries--;
    }
  }
  
  if (!valid_entries){ // checking if at least one entry is valid in order to prevent division by 0 in mean function
      cout << "\nAll entries are invalid!\nExiting..." << endl;
      return 0;
  }

  double *max_val = maximum_value(arr, sizeof arr / sizeof arr[0]);
    
  
  *max_val = NAN;  //excluding the max value from the average
  valid_entries--; //updating the number of valid entries to calculate the average

  mean (arr, sizeof arr / sizeof arr[0], valid_entries);

  return 0;
}
