#include <iostream>

// Selection sort
static void sort(double *xs, size_t n){
  if (n <= 1) return; // Every array of size 0 is sorted. Every array of size 1 is also sorted
    double *smallest = &xs[0];
    for (size_t i = 0; i < n; i++) {
      if (xs[i] < *smallest){  // Selection sort is a comparison based sorting algorithm
        smallest = &xs[i];
      }
    }
    double smallest_val = *smallest;
    *smallest = xs[0];
    xs[0] = smallest_val;
    sort(&xs[1], n - 1);
}



int main(){
  double xs[] = { 7.3, - 6.5, 10.9, 14.3, - 6.6, -7.2, 0, 19, 347, 3e-1 };
  using namespace std;
  sort(xs, sizeof xs / sizeof xs[0]);
  for (size_t i = 0; i < sizeof xs/sizeof xs[0]; i ++) {
    cout << xs[i] << " ";
  }
  cout << endl;
  
  return 0;


}