#include <iostream>


static void insert(double new_val, double *ss, size_t n){
  size_t i;
  for (i = 0; i < n; i++){
    if (ss[i] > new_val) break;
  }
  for (size_t j = n; j > i; j--){ // besides j = n, it will not cause out of bounds because when the function insert starts, double *ss will have length n,
                                  // but when finishes, the length will be n + 1(28m:35s video)
    ss[j] = ss[j - 1];
  }
  ss[i] = new_val;
}

// Insertion sort
static void sort(double *xs, size_t n){
  for(size_t already_sorted = 0; already_sorted < n; already_sorted++){
    insert (xs[already_sorted], xs, already_sorted);
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