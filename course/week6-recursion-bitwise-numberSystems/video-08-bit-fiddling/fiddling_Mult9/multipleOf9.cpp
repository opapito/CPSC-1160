#include<iostream>
using namespace std;
 
// Bitwise operator based function to check multiple of 9
bool isMulOf9(int n)
{
    // Base cases
    if (n == 0 || n == 9)
        return true;
    if (n < 9)
        return false;
 
    // if the number is greater than 9, then do this 
    return isMulOf9((int)(n>>3) - (int)(n&7));
}
 
int main()
{
  int n{0};
  cout << "Type a number to check if it is a multiple of 9:";
  cin >> n;
    if( isMulOf9(n) )
          cout << "The number is " << n << " a multiple of 9 \n" << endl;
    else
          cout << "The number " << n << " is NOT a multiple of 9 \n" << endl;
 
    return 0;
}