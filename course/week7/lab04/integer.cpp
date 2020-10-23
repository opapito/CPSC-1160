/*
*A C++ program that implements the following java functions:
* 1. unsigned int highestOneBit(unsigned int);
* 2. unsigned int lowestOneBit(unsigned int);
* 3. int numberOfLeadingZeroes(unsigned int);
* 4. int numberOfTrailingZeroes(unsigned int);
* 5. unsigned int rotateLeft(unsigned int, int);
* 6. unsigned int rotateRight(unsigned int, int);
*
*Author: Pablo Bourbom Soares
* 
*/


#include <cmath>
#include <climits>
#include "integer.h"

unsigned int highestOneBit(unsigned int n){
	for (int i{sizeof n * CHAR_BIT - 1}; i > 0; i--){ //size * number of bits in a byte (CHAR_BIT) 
	    if (n & (1U << i)){
					return pow(2, i);
	    }
  }
	return 0;
}

// 0111 1111 1111 1111 1111 1111 1111 1111 = 2147483647
// 0100 0000 0000 0000 0000 0000 0000 0000 = 1 << 30
// 0100 0000 0000 0000 0000 0000 0000 0000 = 1073741824

// 0000 0000 0000 0000 0000 0000 0000 0001 = 1
// 1000 0000 0000 0000 0000 0000 0000 0000 = 1 << 31
// 0001 0000 0000 0000 0000 0000 0000 0000 = 1 << 32 (overflow)

// 0111 1111 1111 1111 1111 1111 1111 1111 = 2147483647
// 0001 0000 0000 0000 0000 0000 0000 0000 = 1 << 32 (overflow integer type), 2^32 = 4.294.967.296,so the function returns 0 if started with 32 (i{32})
//========================================
// 0001 0000 0000 0000 0000 0000 0000 0000 = 65536

unsigned int lowestOneBit(unsigned int n){
	for (unsigned int i{0}; i < sizeof n * CHAR_BIT; i++){
	    if (n & (1U << i)){
					return pow(2, i);
	    }
  }
	return 0;
}

unsigned int numberOfLeadingZeroes(unsigned int n){
	unsigned int count {0};
	for (int i{sizeof n * CHAR_BIT - 1}; i >= 0; i--){ 
	    if (n & (1U << i)){
					return count;
	    } else {
				count++;
			}
  }
	return count;
}

unsigned int numberOfTrailingZeroes(unsigned int n){
	unsigned int count {0};
	for (unsigned int i{0}; i < sizeof n * CHAR_BIT; i++){ 
	    if (n & (1U << i)){
					return count;
	    } else {
				count++;
			}
  }
	return count;
}

unsigned int rotateLeft(unsigned int n, int shifts){
	return (n << shifts) | (n >> ((sizeof n * CHAR_BIT) - shifts));
}

unsigned int rotateRight(unsigned int n, int shifts){
	return (n >> shifts) | (n << ((sizeof n * CHAR_BIT) - shifts));
}