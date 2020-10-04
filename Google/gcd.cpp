/*
The greatest common divisor of two integers is the largest number that divides them both evenly. For example, gcd(12, 18) = 6, gcd(−4, 14) = 2. The most efficient way to compute gcd is with the Euclidean algorithm. Write a program with a function to compute gcd for two integers. Try doing the function without recursion first - it will help you understand how the algorithm works.
Explicitly define your sub-tasks, for example, find the code for the Euclidean algorithm; create a non-recursive function for the algorithm; etc
https://www.khanacademy.org/computing/computer-science/cryptography/modarithmetic/a/the-euclidean-algorithm 
*/

#include <iostream>
#include <climits>

using namespace std;

int main(){
int num1{0}, num2{0}, num_a{0}, num_b{0}, gcd{0}, temp{0};
bool valid{false};
do {
  cout << "Enter two integers for gcd calculation: ";
  cin >> num1 >> num2;
  if (!cin) {
    cout << "Invalid input! Please, enter integers only." << endl;
    cin.clear();
    cin.ignore(SSIZE_MAX, '\n');
  } else {
    if (num1 < num2){
      temp = num1;
      num1 = num2;
      num2 = temp;
    }
    valid = true;
    num_a = num1;
    num_b = num2;
    cout << "Starting Euclidian Algorithm...." << endl;
    while (num_a != 0 && num_b !=0 ){
      cout << "( " << num_a << " = " << num_b << " * " << (num_b !=0 ? num_a / num_b : 0) << " + " << (num_b !=0 ? num_a % num_b : 0) << " )" << endl;
      temp = num_b;
      num_b = num_a % num_b;
      num_a = temp;

    }
    cout << "The gcd of " << num1 << " and " << num2 << " is " << (num_a = 0 ? num_b : num_a)<< endl;
  }

} while (!valid); 

return 0;
}