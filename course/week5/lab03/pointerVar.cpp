#include <iostream>
using namespace std;

static void change_value(int *x) {
  (*x)++;
}

int main() {
  int x = 2;
  std::cout << x << std::endl;
  change_value(&x);
  std::cout << x << std::endl;
  return 0;
}