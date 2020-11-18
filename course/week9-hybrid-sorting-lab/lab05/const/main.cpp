#include <iostream>
using namespace std;
static void categorize(const long *xs, const size_t n, size_t *num_neg, size_t *num_zero, size_t *num_pos)
{
  *num_neg = 0;
  *num_zero = 0;
  *num_pos = 0;
  for (size_t i = 0; i < n; i++)
  {
    if (xs[i] < 0)
      (*num_neg)++;
    else if (xs[i] > 0)
      (*num_pos)++;
    else
      (*num_zero)++;
  }
}

int main()
{
  long vals[] = {7, 9, 12, -5, -2, 0, 6, -3, 1, 2, 0, 4, -12};
  size_t n, z, p;
  categorize(vals, sizeof vals / sizeof vals[0], &n, &z, &p);
  cout << "neg: " << n << "; zero: " << z << "; pos: " << p << endl;
  return 0;
}