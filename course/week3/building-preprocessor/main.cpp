# include <iostream>
# include "quadratic.h" //including head file in the current directory (it is necessary to use "" instead of <>)

#define GET(prompt, var) cout << "Enter " prompt << flush; cin >> var // Macro
#define ADD(x) x * x


int main(){
  using namespace std;

  double a, b, c;
  //cout << "Enter a b and c: "<< flush;
  GET("a: ", a);
  GET("b: ", b);
  GET("c: ", c);
  //cin >> a >> b >> c;
  if (!cin){
    cerr << "Your input was bad and your should fell bad" << endl;
    return 1;
  }
  cout << ADD(2 + 2) << endl; // preprocessor will translate to cout << 2 + 2 * 2 + 2 << endl; which will result in 8
  cout << "There are " << num_roots_of_quadratic(a, b, c) << " real roots" << endl;
  return 0;
}