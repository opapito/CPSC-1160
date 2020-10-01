# include <iostream>
using namespace std;

int main(){
  bool isCovered[99]{false};
  int number{0};
  
  cin >> number;
  while (number != 0 ){
    isCovered[number - 1] = true;
    cin >> number;
  }
  
  bool allCovered{true}; 
  for (size_t i = 0; i < 99; i++ ){
    if (!isCovered[i]){
      allCovered = false;
      break;
    }
  }
  
  if (allCovered) {
    cout << "The tickets conver all numbers" << endl;
  } else {
    cout << "The tickets don't conver all numbers" << endl;
  }

  
  return 0;
}