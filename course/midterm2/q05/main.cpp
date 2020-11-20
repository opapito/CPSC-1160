/*
Question 5 (3 points) 
Saved
Write a "fibonnacis" function to complete the following code. It should generate the first "n" Fibonacci numbers and return an array of them (allocated on the heap).

The definition of a Fibonacci number:

fib(0) = 1
fib(1) = 1
fib(n) = fib(n - 1) + fib(n - 2) (if n is greater than 1)

Here is the code to complete:

#include <iostream>

int main() {
  using namespace std;
  int *fibs = fibonaccis(15);
#define SHOULD_BE(i, v) if (fibs[i] != v) cerr << i << " should be " << v << " not " << fibs[i] << endl
  SHOULD_BE(0, 1);
  SHOULD_BE(1, 1);
  SHOULD_BE(2, 2);
  SHOULD_BE(3, 3);
  SHOULD_BE(4, 5);
  SHOULD_BE(5, 8);
  SHOULD_BE(6, 13);
  SHOULD_BE(7, 21);
  SHOULD_BE(8, 34);
  SHOULD_BE(9, 55);
  SHOULD_BE(10, 89);
  SHOULD_BE(11, 144);
  SHOULD_BE(12, 233);
  SHOULD_BE(13, 377);
  SHOULD_BE(14, 610);
  cout << "everything (else) was okay" << endl;
  delete [] fibs;
  return 0;
}


*/


#include <iostream>
using namespace std;
// The function for finding the Fibonacci number
int *fibonaccis(int index);
int fib(int index);


int main()
{
  // Prompt the user to enter an integer

  int *fibs = fibonaccis(15);
  for (int i = 0; i < 15; i++){
    cout <<"index->" << i <<" = " << fibs[i] << endl;
  }
  delete [] fibs;
  return 0;
}

// The function for finding the Fibonacci number
int *fibonaccis(int index)
{
  int *f = new int[index];
  for ( int i = 0; i < index; i++){
    f[i] = fib(i);
  }
  return f;
}

int fib (int index)
{
  if (index == 0) // Base case
    return 1;
  else if (index == 1) // Base case
    return 1;
  else // Reduction and recursive calls
    return fib(index - 1) + fib(index - 2);
}