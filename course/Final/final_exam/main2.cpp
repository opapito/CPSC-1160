/*
 * Your job is to complete the code for this class.
 * It is a linked list of integers.
 *
 * You may either write the code directly in this file, or put it
 * in a separate .cpp file, whichever you prefer.
 *
 * You may add things to either class (e.g., helper methods), but
 * you may *NOT* remove anything from either class.
 * Some operations MUST be done recursively, in which case you will NEED to create helper methods/functions.
 *
 * You can change the 'struct' into a 'class' if you wish.
 *
 * Total of 21 marks.
 */

#include <iostream>
#include <sstream>
#include "1160-final.h"

using namespace std;

int main() {
	using namespace std;
#define CHECK(a, b)	if (a != b) { cerr << "line " << __LINE__ << ": expected " << b << ", not " << a << endl; }
#define CHECKSTR(a, b)	{ stringstream s; s << a; CHECK(s.str(), b); }
	
	final_obj a;
	CHECKSTR(a, "");
	a.make_ascending();
	CHECKSTR(a, "");
	a.add(5);
	a.add(7);
	a.add(8);
	CHECKSTR(a, "8 7 5 ");

	int *z = a.shuffle();
	CHECK(z[0], 7);
	CHECK(z[1], 5);
	CHECK(z[2], 8);
	delete [] z;

	a.add(2);
	CHECKSTR(a, "2 8 7 5 ");
	z = a.shuffle();
	CHECK(z[0], 8);
	CHECK(z[1], 7);
	CHECK(z[2], 2);
	CHECK(z[3], 5);
	delete [] z;

	a.make_ascending();
	CHECKSTR(a, "2 8 ");
	z = a.shuffle();
	CHECK(z[0], 2);
	CHECK(z[1], 8);
	delete [] z;

	a.add(10);
	a.add(0);
	a.add(20);
	a.add(-12);
	CHECKSTR(a, "-12 20 0 10 2 8 ");
	z = a.shuffle();
	CHECK(z[0], 0);
	CHECK(z[1], 10);
	CHECK(z[2], 20);
	CHECK(z[3], 2);
	CHECK(z[4], -12);
	CHECK(z[5], 8);
	delete [] z;

	a.fun_add(5);
	CHECKSTR(a, "-12 0 2 5 20 10 8 ");
	a.make_ascending();
	CHECKSTR(a, "-12 0 2 5 20 ");

	return 0;
}
