#include <cmath>
unsigned int highestOneBit(unsigned int n){
  
  for (int i{7}; i >= 0; i--){
	    if (n & (1 << i)){
	        return pow(2, i);
	    }
  }
}