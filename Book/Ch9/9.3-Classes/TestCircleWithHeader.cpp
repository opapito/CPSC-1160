#include <iostream>
#include "Circle.h"
using namespace std;

int main()
{
  Circle circle1;
  Circle circle2(5.0);

  cout << "The area of the circle of radius "
       << circle1.radius << " is " << circle1.getArea() << endl;
  cout << "The area of the circle of radius "
       << circle2.radius << " is " << circle2.getArea() << endl;

  // Modify circle radius
  circle2.radius = 100;
  cout << "The area of the circle of radius "
       << circle2.radius << " is " << circle2.getArea() << endl;

  Circle c1;
  Circle c2(6);
  cout << "c2.getArea() equal = " << c2.getArea() << endl;
  c1 = c2;
  cout << "c1.getArea() equal = " << c1.getArea() << endl;
  cout << Circle(8).getArea()  << endl;

  return 0;
}