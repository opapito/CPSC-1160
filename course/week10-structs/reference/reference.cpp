#include <iostream>
using namespace std;

int test(int &reference){
  cout << "Printing the referenced variable directly:" << endl;
  cout << reference << endl;
  cout << "Adding one and printing again:" << endl;
  reference++;
  cout << reference << endl;
  return 0;
}

int main(){
  int r{7};
  test(r);
  cout << "Value after return:" << r << endl;
  return 0;
}