//https://www.geeksforgeeks.org/operator-overloading-c/?ref=lbp

#include<iostream> 
using namespace std; 

class Complex { 
private: 
	int real, imag; 
public: 
	Complex(int r = 0, int i =0) {real = r; imag = i;} 
	
	// This is automatically called when '+' is used with 
	// between two Complex objects 
	Complex operator + (Complex const &obj) { 
		Complex res; 
		res.real = real + obj.real; 
		res.imag = imag + obj.imag; 
		return res; 
	} 
	void print() { cout << real << " + i" << imag << endl; } 
}; 
/*
What is the difference between operator functions and normal functions?
---------------------------------------------------------------------
Operator functions are same as normal functions. The only differences are, name of an operator function is always operator keyword followed by symbol of operator and operator functions are called when the corresponding operator is used.

Can we overload all operators?
----------------------------------------------------------------------
Almost all operators can be overloaded except few. Following is the list of operators that cannot be overloaded.
   . (dot) 
   :: 
   ?: 
   sizeof 

-----------------------------------------------------------------------
Important points about operator overloading
1) For operator overloading to work, at least one of the operands must be a user defined class object.

2) Assignment Operator: Compiler automatically creates a default assignment operator with every class. The default assignment operator does assign all members of right side to the left side and works fine most of the cases (this behavior is same as copy constructor). See this for more details.

3) Conversion Operator: We can also write conversion operators that can be used to convert one type to another type.

*/

int main() 
{ 
	Complex c1(10, 5), c2(2, 4); 
	Complex c3 = c1 + c2; // An example call to "operator+" 
	c3.print(); 
} 
