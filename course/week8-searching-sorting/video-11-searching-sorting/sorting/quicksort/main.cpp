#include <iostream>

static size_t partition (double const *xs, size_t n, double pivot, double *left, double *right){
  size_t left_i = 0, right_i = 0;
  for (size_t i = 0; i < n; i++){
    if (xs[i] < pivot) left[left_i++] = xs[i];
    else               right[right_i++] = xs[i];
  }
  return left_i;
}


// Quick sort (pick any element as pivot for the sake of simplicity)
static void sort (double *xs, size_t n){
  if (n <= 1) return;
  double const pivot = *xs;
  double left[n], right[n];
  size_t left_n = partition(&xs[1], n -1 , pivot, left, right); //It is necessary to take the pivot out. If you do not, you will always be recursing in a array with the same size of the beginig
  size_t right_n = n - left_n - 1;
  sort(left, left_n);
  sort(right, right_n);
  for (size_t i = 0; i < left_n ; i++){
    xs[i] = left[i];
  }
  xs[left_n] = pivot; // special case for putting pivot back
  for (size_t i = 0; i < right_n; i++ ){
    xs[i + left_n + 1] = right[i];
  }

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