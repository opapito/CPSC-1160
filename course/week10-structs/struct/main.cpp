#include <iostream>

struct x
{
  double y;
};

void foo (x const *z){
  //cout << (*z).y << endl;
  std::cout << z->y << std::endl;
}

//double distance(point p1, point p2)

int main(){
  /* x r;
   r.y = 2.5;
   These both statements can be replaced by one x r = { .y = 2.5 }
   Any fields not explicitly mentioned in the initializer will be implicitly initialized to 0
  */
  x r = { .y = 2.5 };
  foo(&r);
  return 0;
}