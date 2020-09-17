#include <iostream>
using namespace std;

/*1.3 (Display a pattern) Write a program that displays the following pattern:

    *   ********* 
   ***   *******  
  *****   *****   
 *******   ***    
*********   *      

*/
 
int main (){
  int b, e;
    b=5;
    e=5;  
  for (int line = 1; line <=5; line++){
    for (int column = 1; column <=18; column++){
      if ((column >= b && column <= e) || (column >= e + 4 && column <= (18 - line))){
        cout <<"*";
        }
      else{
        cout <<" ";
        }
    }
    b--;
    e++;
    cout << endl;
  }
}
