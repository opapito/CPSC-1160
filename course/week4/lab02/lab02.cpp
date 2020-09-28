#include <iostream>
#include <climits>
#include "functions.h"

using namespace std;

int main() {
cout << "Starting factorial with " << SHRT_MAX << endl;
short shortF = SHRT_MAX;
int intF = INT_MAX;
factorial(shortF);
factorial(intF);
//factorial(LONG_MAX);
//factorial(LONG_LONG_MAX);


return 0;
}