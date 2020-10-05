#include <iostream>
using namespace std;

double sum(double *vals, size_t n)
{
  double s = 0;
  for (size_t i = 0; i < n; i++)
  {
    s += vals[i];
  }
  return s;
}
int main()
{
  double x[] = {7e2, 3.1e-5, -6};
  cout << sum(x, sizeof x / sizeof x[0]) << endl;
  return 0;
}