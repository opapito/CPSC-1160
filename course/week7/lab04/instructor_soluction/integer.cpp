# include "integer.h"
# include <climits>

# define INT_BITS   (sizeof (unsigned int) * CHAR_BIT)

int numberOfTrailingZeroes(unsigned int x){
  if (!x) return INT_BITS; //sizeof x * CHAR_BIT;
  int power = 0;
  while (!(x & 1)){
    x >>= 1;
    power++;
  }
  return power;
}

/*

1110000 -> shift 1
0111000 -> shift 1
0011100 -> shift 1
0001110 -> shift 1
0000111 -> found an one, what means that (x & 0000001) returns 1, or "true"

  0000111
& 0000001
=========
= 0000001

*/

int numberOfLeadingZeroes(unsigned int x){
  if (!x) return INT_BITS;//sizeof x * CHAR_BIT;
  int power = 0;
  while (!(x & (1u << (INT_BITS - 1)))){
    x <<= 1;
    power++;
  }
  return power;
}

unsigned int highestOneBit(unsigned int x){
  return x ? (1u << (INT_BITS - numberOfLeadingZeroes(x) - 1)) : -1;
  /*
  if (!x) return -1;
  int power = 0;
  while (x >>= 1) {
    power++
  }
  return 1u << power;
  */
}

unsigned int lowestOneBit(unsigned int x){
  return x ? (1u << numberOfTrailingZeroes(x)) : -1;

  /*
  if (!x) return -1;
  int power = 0;
  while (x) {
    x <<= 1;
    power++
  }
  return 1u << (sizeof x * CHAR_BIT - power);
  */
}

unsigned int rotateLeft (unsigned int x, int num_shifts) {
  if (num_shifts < 0) return rotateRight (x, -num_shifts);
  return (x << num_shifts) | (x >> (INT_BITS - num_shifts));
  /*
  for (int i = 0; i < num_shifts ; i++) {
    x = (x << 1) | (x >> (INT_BITS - 1));
  }
  return x;
  */
}

unsigned int rotateRight (unsigned int x, int num_shifts) {
  if (num_shifts < 0) return rotateLeft (x, -num_shifts);
  return (x >> num_shifts) | (x << (INT_BITS - num_shifts));
  /*
  for (int i = 0; i < num_shifts ; i++) {
    x = (x >> 1) | (x << (INT_BITS - 1));
  }
  return x;
  */
}
