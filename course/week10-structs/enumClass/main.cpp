#include <iostream>

enum class animal
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
enum class phase
{
  wood,
  fire,
  earth,
  metal,
  water
};
int main()
{
  phase x = phase::wood;
  animal y = animal::pig;
  x++;              // NO
  y = phase::earth; // NO
  x == y;           // NO
}