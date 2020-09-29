#include <iostream>
#include <climits>
#include <float.h> //see --> http://www.cplusplus.com/reference/cfloat/

using namespace std;
int main()
{
  cout << "Listing actual limits:" <<endl;
  cout << "SHORT_MIN is " << SHRT_MIN << endl;
  cout << "SHORT_MAX is " << SHRT_MAX << endl;
  cout << "INT_MIN is " << INT_MIN << endl;
  cout << "INT_MAX is " << INT_MAX << endl;
  cout << "LONG_MIN is " << LONG_MIN << endl;
  cout << "LONG_MAX is " << LONG_MAX << endl;
  cout << "LONG_LONG_MAX is " << LONG_LONG_MAX << endl;
  cout << "LONG_LONG_MIN is " << LONG_LONG_MIN << endl;
  cout << "FLT_MIN is " << FLT_MIN << endl;
  cout << "FLT_MAX is " << FLT_MAX << endl;
  cout << "DBL_MIN is " << DBL_MIN << endl;
  cout << "DBL_MAX is " << DBL_MAX << endl;
 return 0;
 }