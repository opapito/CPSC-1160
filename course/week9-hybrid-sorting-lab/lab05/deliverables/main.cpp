#include <iostream>
#include "functions.h"
#include "lab05-nums.h"


int main(){
  using namespace std;
  size_t const n = 500000;
  hybrid_sort(array, n);

 for (size_t i = 0; i < 26; i++){
      //selection_sort(array, n);
      //sort(array, n);
      cout << array[i] << " ";
  }
  cout << endl;
  return 0;

}