#include <iostream>
#include <climits>
#include "integer.h"

using namespace std;

int main(){
int n{2147483647 };
cout << "Maximum integer: " << INT_MAX << endl;
cout << sizeof n << endl;
cout << highestOneBit(n) << endl;

return 0;
}