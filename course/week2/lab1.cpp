/*
* A program to convert a temperature from Fahrenheit to Celsius
* Pablo Bourbom Soares
*/
#include <iostream>
#include <climits>
#include<iomanip>
using namespace std;

int main(){
  bool valid{false};
  do{
    cout << "Enter a temperature in Fahrenheit: ";
    double temp{0};
    cin >> temp;
    if (!cin){
      cin.clear(); // DOES NOT CLEAR the buffer , but clears the fail bit, sets the fail state to false
      cin.ignore(SSIZE_MAX, '\n');
      cout << "Please, provide a valid number" << endl;
    } else{
      valid = true;
      cout << temp << " corresponds to " << setprecision(4) << ((temp - 32) * 5/9) << " Celsius" << endl;
    }
  } while (!valid);
  return 0;
}