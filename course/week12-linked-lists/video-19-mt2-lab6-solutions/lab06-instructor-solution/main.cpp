#include <iostream>
#include <sstream>
#include "set.h"

int main(){
  using namespace std;

  #define CHECK(a, b) if ( a != b ) cerr  << __LINE__ << ": should be " << b << " , not" << a << endl
  #define CHECKSTR(a, b) { stringstream ss; ss << a; CHECK(ss.str(), b); }
  set s(5);
  CHECKSTR(s, "{ }");
  s[0] = true;
  CHECKSTR(s, "{ 0 }");
  s[3] = true;
  CHECKSTR(s, "{ 0 3 }");
  set t(7);
  t[0] = true;
  t[1] = true;
  CHECKSTR(s + t, "{ 0 1 3 }");
  CHECKSTR(s, "{ 0 3 }");
  set u = s;
  u+= t;
  CHECKSTR(u, "{ 0 1 3 }");
  t[6] = true;
  CHECKSTR(s + t, "{ 0 1 3 6 }");
  
  CHECKSTR(u - s, "{ 1 }");
  CHECKSTR(s - s, "{ }");
  CHECKSTR(t - t, "{ }");
  CHECKSTR(u - u, "{ }");
  u -= t;
  CHECKSTR(u, "{ 3 }");
  
  CHECKSTR(t * s, "{ 0 }");

  CHECKSTR(~t , "{ 2 3 4 5 }");
  CHECKSTR(~(s * t) , "{ 1 2 3 4 5 6 }");
  CHECKSTR(~(t * s) , "{ 1 2 3 4 5 6 }");

  return 0;
}