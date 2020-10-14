#include <iostream>
using namespace std;
void f(int n)
{
  if (n > 0)
  {
    f(n - 1);
    cout << n << " ";
    
  }
}
int main()
{
  f(5);
  cout << endl;
  return 0;
}