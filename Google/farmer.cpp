/*
https://developers.google.com/edu/c++/getting-started#example-5:-math-puzzles 
Example 5: Math Puzzles
One of the powers of computing is being able to do a brute-force search for a solution to a problem. Trial and error works just fine for some problems. In fact, computers can be especially good at such problems. Consider this:

Horses cost $10, pigs cost $3, and rabbits are only $0.50. A farmer buys 100 animals for $100, How many of each animal did he buy? 

*/

#include <iostream>

using namespace std;

int main(){
for (int h{1}; h < 101; h++){
  for (int p{1}; p < 101; p++ ){
    for (int r{1}; r < 101; r++){
      if ((10*h + 3*p + r*0.5) == 100 && (h + p + r) == 100){
        cout << "The farmer bought " << h << " horses, " << p << " pigs and " << r << " rabbits." << endl;
        break;
      }
    }
  }
}

}