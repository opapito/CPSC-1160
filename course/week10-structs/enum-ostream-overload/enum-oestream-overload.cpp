#include <iostream>
using namespace std;

enum animal { rat, monkey };

ostream &operator<<(ostream &out, animal a){
  return out << (a == rat ? "rat" : "monkey");
}

int main() {
  animal x = monkey;
  cout << x << endl;
  return 0;
}