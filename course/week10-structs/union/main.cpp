#include <iostream>
using namespace std;

struct number
{
  enum class number_type
  {
    integer,
    real
  } number_type;

  union number_value
  {
    int integer_value;
    double real_value;
  } number_value;
};

struct anonymous_number
{
  enum class number_type
  {
    integer,
    real
  } number_type;
  /*
  An example of an anonymous union.
  */
  union
  {
    int integer_value;
    double real_value;
  };
};

union int_or_float
{
  long x;
  double y;
};
int main()
{
  int_or_float x = {.x = 3};
  int_or_float y = {.y = 2.5};
  x.y = 1.31626;       // this is actually okay
  cout << x.x << endl; // undefined behaviour -> Attempting to read from a different field (field not initialized at struct creation) to cause undefined behaviour
  return 0;
}