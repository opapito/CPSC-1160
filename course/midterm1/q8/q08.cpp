/*
Question 8 (6 points) 
The second problem is to complete the following recursive function:

double tetrate(double x, unsigned int y);

Tetrating a number in mathematics means to repeatedly take the exponent. The mathematical notation often used is
                                    x↑↑y
, meaning "x tetrated by y".

In the following paragraph, we use
                                     x↑↑y
to mean tetrate(x, y)

The parameter y says how many times to raise x to a power.

For example,
              x↑↑2≡x^x
.
              x↑↑3≡x(x^x)
.
              x↑↑4≡x(x^(x^x))
. And so on.

              x↑↑1
is just x.
              x↑↑0
is defined to be 1.

To write your function, I recommend using the pow function, which is included in the standard header file cmath.

Your solution must be recursive.
*/

# include <iostream>
# include <cmath>
using namespace std;

double tetrate(double x, unsigned int y){
  if (y == 0 ){
    return 1;
  } else {
    return pow(x, tetrate(x, y-1));
  }
}


int main(){
unsigned int x{0}, y{0};
cout << "Enter the numbers x and y:";
cin >> x >> y ;

cout << "The resulting number is " <<tetrate(x, y) << endl; 

}