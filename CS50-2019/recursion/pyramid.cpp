#include <iostream>
using namespace std;

void draw(int h);

int main(){
int h{0};
cout << "Enter a height: ";
cin >> h;
draw(h);
}

void draw(int h){
  if (h == 0){
    return;
  }
  
  draw(h - 1);
  for (int i{0}; i < h; i++){
    cout << "#";
  }
  cout << endl;

}
