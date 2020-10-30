#include <iostream>

/*
Example of linear search recursive

static bool search(int const *xs, size_t n, int target){
  if (n == 0)             return false;
  else if (*xs == target) return true;
  else                    return search(&xs[1], n - 1, target);
  
}
*/

static bool search(int const *xs, size_t n, int target){
  if (n == 0)                 return false;
  size_t const midpoint = n/2; // the midpoint was defined as a constant because it will not change in the same stackframe
  if (xs[midpoint] == target) return true;
  else if (xs[midpoint] < target) {
    return search(&xs[midpoint + 1], n - midpoint - 1, target);
  } else {
    return search(&xs[0], midpoint, target); // it is not including the midpoint
  }

  
}

int main(){
  int const xs[] = { -20, -15, -10, -5, -2, -1, 8, 150, 199, 287, 4147 };
  using namespace std;
  cout << search(xs, sizeof xs / sizeof xs[0], -9) << endl;
  cout << search(xs, sizeof xs / sizeof xs[0], -10) << endl;
  return 0;


}