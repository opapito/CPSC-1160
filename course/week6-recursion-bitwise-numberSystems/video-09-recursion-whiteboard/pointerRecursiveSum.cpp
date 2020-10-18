# include <iostream>
using namespace std;

//In C++ you are allowed to have a pointer out of bounds of an array as long you do not use it.

int sum ( int const *arr, size_t n){
  int r{0};
  if (n == 0){
    return 0;
  } else {
    r = sum(&arr[1], n - 1);
  }
  return r + *arr;
}

int main(){
  int arr[]{4, 5, 6};
  cout << sum(arr, sizeof arr/sizeof arr[0]) << endl;

  return 0;
}
