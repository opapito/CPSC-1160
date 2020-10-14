#include <iostream>
using namespace std;
void f(int n)
{
  if (n > 0)
  {
    cout << n << " ";
    f(n - 1);
  }
}
int main()
{
  f(5);
  cout << endl;
  return 0;
}