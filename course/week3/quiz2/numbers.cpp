/*
Question 5 (4 points) 
Write a C++ program which will reads in an integer n from the user, then prints out all integers from -n to n, their squares, their cubes, and the octal representation of n. (4 columns in total). You may assume n is positive and less than 1000. The output should be nicely formatted in a table with fixed-width columns. Example usage:

Please enter a number: 3
 -3   9   -27 37777777775
 -2   4    -8 37777777776
 -1   1    -1 37777777777
  0   0     0           0
  1   1     1           1
  2   4     8           2
  3   9    27           3
You do not have to check for bad input. No comments are necessary. Copy-and-paste the contents of your .cpp file here when finished. Keep in mind the 2 hour time limit. This question is worth 50% of your quiz 02

*/

# include <iostream>
# include <iomanip>
# include <math.h>

using namespace std;

int main(){
 int n{0};
 cout << "Please enter a number: ";
 cin >> n;
  for (int i{-n}; i <= n; i++){
    cout << setw(3) << i << setw(4) << pow(i, 2) << setw(6) << pow(i, 3) << setw(12) << oct << i << endl;
    cout << dec;
  }

  return 0;
}
