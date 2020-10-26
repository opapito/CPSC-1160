#include <iostream>
#include "integer.h"
#include "social_distancing.h"

int main(){
  using namespace std;

#define CHECK(v, exp)    if (v != exp) { cerr << #v " is " << v << ", not " << exp << endl;}

  CHECK(highestOneBit(1), 1);
  CHECK(highestOneBit(3), 2);
  CHECK(highestOneBit(0x80000000u), 0x80000000u);
  CHECK(highestOneBit(0), (unsigned int) -1);

  CHECK(lowestOneBit(1), 1);
  CHECK(lowestOneBit(3), 1);
  CHECK(lowestOneBit(0x80000000u), 0x80000000u);
  CHECK(lowestOneBit(0), (unsigned int) -1);

  CHECK(numberOfLeadingZeroes(1), 31);
  CHECK(numberOfLeadingZeroes(3), 30);
  CHECK(numberOfLeadingZeroes(0x80000000u), 0);
  CHECK(numberOfLeadingZeroes(0), 32);

  CHECK(numberOfTrailingZeroes(1), 0);
  CHECK(numberOfTrailingZeroes(3), 0);
  CHECK(numberOfTrailingZeroes(0x80000000u), 31);
  CHECK(numberOfTrailingZeroes(0), 32);

  CHECK(rotateLeft(0X80000001u, 1), 3);
  CHECK(rotateLeft(5, 2), 20);
  CHECK(rotateLeft(0xffffffffu, 17), 0xffffffffu);
  CHECK(rotateLeft(0, 12), 0);
  CHECK(rotateLeft(5, -1), 0x80000002u);
  
  CHECK(rotateRight(0X80000001u, 1), 0xc0000000u);
  CHECK(rotateRight(5, 2), 0x40000001u);
  CHECK(rotateRight(0xffffffffu, 17), 0xffffffffu);
  CHECK(rotateRight(0, 12), 0);
  CHECK(rotateRight(5, -1), 10);
  
  cout << "bit fiddling tests are all done!" << endl;
  cout << social_distancing(0,0) << endl;


}