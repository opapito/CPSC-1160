/*
Example 7: Next steps with decomposition - Your first day on the job
You have just gotten a position as a salesperson for the ExerShoe company, specializing in high-end exercise shoes costing around $225 per pair. Your boss has given you three options for compensation, which you must choose before you begin your first day:

Straight salary of $600 per week;
A salary of $7.00 per hour plus a 10% commission on sales;
No salary, but 20% commissions and $20 for each pair of shoes sold
You, being an expert C++ programmer, figure you can write a program to help decide the best choice of compensation.

A common approach in doing decomposition for a larger program is to create a main function that reads like an outline to solving the problem. Then, we write the functions to do each task.

Here is a first pass at the main program:

  GetInput(WeeklySales);
  CalcMethod1(WeeklySales);
  CalcMethod2(WeeklySales);
  CalcMethod3(WeeklySales); 

*/


#include <iostream>
#include <climits>
#include <iomanip>
using namespace std;

int GetInput ();
int CalcMethod1 ();
double CalcMethod2 (int);
double CalcMethod3 (int);

int main(){
  GetInput();
return 0;
}

int GetInput (){
  int weeklySales{0};
  bool valid{false};

  while (!valid){
    cout << "Type an integer representing weekly sales: ";
    cin >> weeklySales;

    if (!cin) {
      cout << "Invalid entry!" << endl;
      cin.clear(); // DOES NOT CLEAR the buffer , but clears the fail bit, sets the fail state to false
      cin.ignore(SSIZE_MAX, '\n');
    } else {
      cout << "Based the weekly sales of " << weeklySales << " shoe(s), your compensation would be: " << endl;
      cout << "Option (1) straight salary of $600 per week: " << fixed << setprecision(2) << CalcMethod1() << endl;
      cout << "Option (2) salary of $7.00 per hour plus a 10% commission on sales: " << fixed << setprecision(2) << CalcMethod2(weeklySales) << endl;
      cout << "Option (3) No salary, but 20% commissions and $20 for each pair of shoes sold: " << fixed << setprecision(2) << CalcMethod3(weeklySales) << endl;

      valid = true;
    }
  }
return 0;
}

int CalcMethod1 (){
  return 600;
}
double CalcMethod2 (int w){ 
  return (40*7.0)+(225*0.1*w);
}
double CalcMethod3 (int w){
  return (20.0*w)+(225*0.2*w);
}

