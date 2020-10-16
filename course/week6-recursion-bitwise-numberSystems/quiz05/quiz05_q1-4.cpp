#include <iostream>
using namespace std;

int PriceWise1(int x){
  if (x <= 1){
    return 1;
  } else {
    return 2*(PriceWise1(x-1)) + x ;
  }
}

int PriceWise2(int x){
  if (x <= 1){
    return 2*x;
  } else {
    return 2*(PriceWise2(x-5)) - PriceWise2(x - 1);
  }
}

int Recursion1(int x, int y){
  if (x <= 0){
    return y;
  }
  return Recursion1(x - 1, y + 1) - Recursion1(x/2, y * 2);
}

int Recursion2(int x, int y){
  if (x <= 0){
    return y;
  }
  return x + Recursion2(x - 1, y + 1);
}


int main(){
  //cout << PriceWise1(4) << endl;
  //cout << PriceWise2(3) << endl;
  //cout << Recursion1(4, -1) << endl;
  cout << Recursion2(3, -2) << endl;
  return 0;
}