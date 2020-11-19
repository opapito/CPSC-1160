# include <iostream>
using namespace std;

int *factors(int x, size_t *n) {
  int *f = new int[20];
  *n = 0;
  while (x > 1){
    for (int i = 2; i <= x; i++){
      if (x % i == 0){
        f[*n] = i;
        //f[*(n++)] = i; // This code used by instructor example did nor work as expected. It was performing some crazy operation, probably pointer arithmetic and leading to out of bounds indexes
        *n += 1;
        x /= i;
      }
    }
  }
  return f;
}

int main() {
  size_t n;
  int *f = factors(6, &n);
  cout << "Array memory address->" << f << " fist element->" << *f << endl;
  cout << "The factors are:" << endl;
  for (int i{0}; (unsigned) i < n; i++){
    cout << f[i] << endl;
  }
  delete[] f;
}