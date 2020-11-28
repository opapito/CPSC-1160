/*
*A main file with 3 testing cases for each set.h method
*
*Author: Pablo Bourbom Soares
* 
*/
#include <iostream>
#include "set.h"
using namespace std;

int main()
{
  set s(6);
  cout << "Creating an empty set named \"s\" with 6 positions." << endl;
  cout << "s->" << s << endl;
  cout << "# Testing copy constructor, and printing out the set \"b\" copied." << endl;
  set b(s);
  cout << "b->" << b << endl;
  cout << "# Testing assignment operator =, and printing out the set \"c\" assingned." << endl;
  cout << "#1 c = s" << endl;
  set c = s;
  cout << "c->" << c << endl;
  cout << "Filling set \"s\" for 2 more assignment operator tests." << endl;
  cout << "Creating the set {1, 2, 4} in set \"s\"" << endl;
  s[1] = 1;
  s[2] = 1;
  s[4] = 1;
  cout << "s->" << s << endl;
  cout << "Assinging set \"s\" to sets \"s1\" and \"s2\"" << endl;
  cout << "#2 s1 = s " << endl;
  set s1 = s;
  cout << "s1->" << s1 << endl;
  cout << "#3 s2 = s" << endl;
  set s2 = s;
  cout << "s2->" << s2 << endl;
  cout << "Assignment operator test completed ----------------------------------->" << endl;
  cout << "Creating the set {0, 3, 5} in set \"b\"" << endl;
  b[0] = 1;
  b[3] = 1;
  b[5] = 1;
  cout << "b->" << b << endl;
  cout << "# Testing += operator and printing out the result set" << endl;
  cout << "#1 s += b" << s << " += " << b << " = ";
  s+=b;
  cout << s << endl;;
  set d(6);
  cout << "#2 s += d" << s << " += " << d << " = ";
  s+=d;
  cout << s << endl;;
  cout << "#3 d += b" << d << " += " << b << " = ";
  d+=b;
  cout << d << endl;
  cout << "+= operator test completed ----------------------------------->" << endl;
  cout << "# Testing + operator and printing out the result set" << endl;
  set sc = s + c;
  cout << "#1 s + c = " << s << " += " << c << " = " << sc << endl;
  set bd = b + d;
  cout << "#2 b + d = " << b << " + " << d << " = " << bd << endl;
  set ds1 = d + s1;
  cout << "#3 d + s1 = " << d << " + " << s1 << " = " << ds1 << endl;
  cout << "+ operator test completed ----------------------------------->" << endl;
  cout << "# Testing -= operator and printing out the result set" << endl;
  cout << "#1 sc -= d = " << sc << " -= " << d << " = ";
  sc-=d;
  cout << sc << endl;
  cout << "#2 s2 -= b " << s2 << " -= " << b << " = ";
  s2-=b;
  cout << s2 << endl;
  cout << "#3 ds1 -= b " << ds1 << " -= " << b << " = ";
  ds1-=b;
  cout << ds1 << endl;
  cout << "-= operator test completed ----------------------------------->" << endl;
  cout << "# Testing - operator and printing out the result set" << endl;
  cout << "#1 sc - b = " << sc << " - " << b << " = ";
  set e = sc - b;
  cout << e << endl;
  cout << "#2 d - b = " << d << " - " << b << " = ";
  set d_b = d - b;
  cout << d_b << endl;
  cout << "#3 d - s1 = " << d << " - " << s1 << " = ";
  set d_s1 = d - s1;
  cout << d_s1 << endl;
  cout << "- operator test completed ----------------------------------->" << endl;
  cout << "# Testing *= operator and printing out the result set" << endl;
  set f = s - b;
  cout << "#1 f *= s " << f << " *= " << s << " = ";
  f *= s;
  cout << f << endl;
  cout << "#2 f *= b " << f << " *= " << b << " = ";
  f *= b;
  cout << f << endl;
  cout << "#3 ds1 *= b " << ds1 << " *= " << s << " = ";
  ds1 *= s;
  cout << ds1 << endl;
  cout << "*= operator test completed ----------------------------------->" << endl;
  cout << "# Testing * operator and printing out the result set" << endl;
  cout << "#1 s * b " << s << " * " << b << " = ";
  set g = s * b;
  cout << g << endl;
  cout << "#2 s * ds1 " << s << " * " << ds1 << " = ";
  set sd = s * ds1;
  cout << sd << endl;
  cout << "#3 ds1 * b " << ds1 << " * " << b << " = ";
  set dsb = ds1 * b;
  cout << dsb << endl;
  cout << "* operator test completed ----------------------------------->" << endl;
  cout << "# Testing ~ operator and printing out the result set" << endl;
  cout << "#1 g~ =" << g << " ~ = ";
  set h(f);
  h = ~g;
  cout << h << endl;
  cout << "#2 ds1~ =" << ds1 << " ~ = ";
  set hds1(ds1);
  hds1 = ~ds1;
  cout << hds1 << endl;
  cout << "#3 c~ =" << c << " ~ = ";
  set hc(c);
  hc = ~c;
  cout << hc << endl;
  return 0;
}
