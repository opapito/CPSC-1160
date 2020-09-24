// y = ax^2 + bx +c
// x = (-b +/- sqrt(b^2 - 4ac)) / 2a
// a = 0 -> no roots
// sqrt(b^2 - 4ac) = 0 -> 1 root
// sqrt(b^2 - 4ac) > 0 -> 2 roots
// sqrt(b^2 - 4ac) < 0 -> no roots
#include "quadratic.h"

int num_roots_of_quadratic (double a, double b, double c) {
  double discriminant = b * b - 4 * a * c;
  if (discriminant < 0){
     return 0;
  }
  else if (discriminant > 0){
     return 2;
  } 
  else  {
    return 1;
  }

}
