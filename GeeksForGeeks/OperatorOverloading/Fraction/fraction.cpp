#include <iostream> 
using namespace std; 
class Fraction 
{ 
	int num, den; 
public: 
	Fraction(int n, int d) { num = n; den = d; } 

	// conversion operator: return float value of fraction 
	operator float() const { 
		return float(num) / float(den); 
	} 
}; 

/*
  https://www.geeksforgeeks.org/operator-overloading-c/?ref=lbp
 
  Overloaded conversion operators MUST be a MEMBER method. OTHER operators can EITHER be member method or global method.
  
*/

int main() { 
	Fraction f(2, 5); 
	float val = f; 
	cout << val << endl; 
	return 0; 
} 
