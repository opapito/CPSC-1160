
# include <iostream>
using namespace std;

int main(){
int x[]{ 9, 12, 3, -6, 14, 8, 7, 3 };
cout << "array size = " << sizeof x << endl;
cout << "first element size = " << sizeof x[0] << endl;
cout << "number of elements (sizeof x / sizeof x[0]) = " << sizeof x / sizeof x[0] << endl;

  for (size_t i = 0; i < sizeof x / sizeof x[0]; i++) {
    cout << x[i] << endl;
  }
} 