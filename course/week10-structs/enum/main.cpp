#include <iostream>

enum animal
{
  rat,
  ox,
  tiger,
  rabbit,
  dragon,
  snake,
  horse,
  sheep,
  monkey,
  rooster,
  dog,
  pig
};
int main()
{
  animal x = rat;     // OK
  int y = tiger;      // weirdly also OK
  int z = ox * snake; // what?
  // ...
}
