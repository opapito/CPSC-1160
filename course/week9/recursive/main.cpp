#include <iostream>
#include <string>
using namespace std;

static int f(int const *xs, size_t n, int y)
{
  if (n == 0)
  {
    return y;
  }
  int f1 = f(xs, n / 2, y + 1);
  int f2 = f(xs + n / 2, n / 2, y);
  if (y % 2 == 0)
  {
    return (*y) + f1 + f2;
  }
  else
  {
    return f1 - f2;
  }
}

int main (){
 int arr[]{9, 3, 4, -1};
 cout << f(arr, sizeof arr/sizeof arr[0], 1) << endl;

}