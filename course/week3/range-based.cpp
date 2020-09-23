/*
Modifying the Contents of the Vector
  If you want to modify the values in the container you're looping over, or if you want to avoid copying large objects, and the underlying iterator supports it, you can make the loop variable a reference. 
  https://www.cprogramming.com/c++11/c++11-ranged-for-loop.html

*/


#include <iostream>
#include <vector> 
using namespace std;

int main(){
vector<int> vec;
vec.push_back( 1 );
vec.push_back( 2 );

cout << "\nIncrementing vector values by 1....." << endl;
for (int& i : vec ) 
{
    i++; // increments the value in the vector
}

cout << "\nResult values: " << endl;
for (int i : vec )
{
    // show that the values are updated
    cout << i << endl;
}
  
  return 0;
}