# include "palindrome.h"

bool is_palindrome(std::string x){
    // dad, mom, radar, racecar, noon, deed
  size_t n = x.length();
  for (size_t i = 0; i <  n / 2; i++ ){
      if (x[i] != x[n - i - 1]){
        return false;
      }
  }
return true;
}