#include<iostream> 
using namespace std; 

class Point 
{ 
private: 
	int x, y; 
public: 
	Point(int i = 0, int j = 0) { // constructor with default parameters?
		x = i; y = j; 
	} 
	void print() { 
		cout << endl << " x = " << x << ", y = " << y << endl; 
	} 
}; 

int main() { 
	Point t(20, 20); 
	t.print(); 
	t = 30; // Member x of t becomes 30 
	t.print(); 
	return 0; 
}
/*
 Output
 ---------
 x = 20, y = 20
 x = 30, y = 0
*/
