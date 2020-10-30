#include <iostream>

static bool search(int const *xs, size_t n, int target){
  for (size_t i = 0; i < n ; i++){
    if (xs[i] == target) {
      return true;
    }
  }
  return false;
}

int main(){
  int const xs[] = {5, -3, -7, 10, 12, -9, 150, 14 };
  using namespace std;
  cout << search(xs, sizeof xs / sizeof xs[0], -9) << endl;
  cout << search(xs, sizeof xs / sizeof xs[0], -10) << endl;
  return 0;


}