#include <iostream>
using namespace std;

static void merge(double const *l, size_t ln, double const *r, size_t rn, double *x){
  for (size_t left_i = 0, right_i = 0; left_i < ln || right_i < rn; x++){
    if (left_i >= ln)           *x = r[right_i++];
    else if (right_i >= rn)    *x = l[left_i++]; // from this point forward is now possible to make comparissons 
    else if (l[left_i] < r[right_i])
      *x = l[left_i++];
    else
      *x = r[right_i++];
  }
    

}

// Merge sort: in worst case scenarios merge sort is as efficient as quicksort
// The idea behind merge sort is that every array of size 1 (with only one element) is already sorted.
static void sort (double *xs, size_t n){
  if (n <= 1) return;
  size_t const midpoint = n / 2;
  size_t const left_n = midpoint, right_n = n - midpoint;
  
  sort(xs, left_n);
  sort(&xs[left_n], right_n);

  double *merged = new double[n]; //We should allocate this on the heap !! (it's safer this way)
  merge(xs, left_n, &xs[left_n], right_n, merged);

  for (size_t i = 0; i < n; i++){
    xs[i] = merged[i];
  }
  delete [] merged;
 
}


int main(){
  //double xs[] = { 7.3, - 6.5, 10.9, 14.3, - 6.6, -7.2, 0, 19, 347, 3e-1 };
  double xs[] = { 7.3, - 6.5, 10.9 };

  sort(xs, sizeof xs / sizeof xs[0]);
  for (size_t i = 0; i < sizeof xs/sizeof xs[0]; i ++) {
    cout << xs[i] << " ";
  }
  cout << endl;
  
  return 0;

}