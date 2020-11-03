#include <iostream>

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
static void sort (double *xs, size_t n){
  if (n <= 1) return;
  size_t const midpoint = n / 2;
  size_t const left_n = midpoint, right_n = n - midpoint;
  double left[left_n], right[right_n];
  for (size_t i = 0; i < left_n; i++ ){
    left[i] = xs[i];
  }
  for (size_t i = 0; i < right_n; i++){
    right[i] = xs [i + left_n];
  }
  sort(left, left_n);
  sort(right, right_n);
  merge(left, left_n, right, right_n, xs);


  
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