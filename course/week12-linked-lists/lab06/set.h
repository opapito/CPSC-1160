/*
*A h file with functions prototypes
*
*Author: Pablo Bourbom Soares
* 
*/

#ifndef SET_H
#define SET_H
/*
 * A 'set' as a collection of positive integers in which
 * order doesn't matter and duplicates are not considered.
 * We represent a 'set' as an array of booleans. If a number
 * is in the set, its position in the array will be true; if
 * it is not in the set, its position in the array will be
 * false.
 */

#include <iostream>

class set {
	bool *elems;
	size_t num_elems;
public:
	/*
	 * Constructs a new set which can store numbers from 0 to n-1
	 * 'n' is the size of the array to construct
	 */
	set(size_t n): elems(new bool[n]{false}), num_elems(n){};                      // OK
	/*
	 * Copy constructor. Makes *this a copy of s
	 * 's' the set to copy
	 */
	set(set const &s); 																															// OK
	/*
	 * Deallocates any dynamically-allocated memory
	 */
	~set(){ delete [] elems; };																											// OK
	/*
	 * Assignment operator. Makes *this a copy of s
	 * 's' the set to copy
	 */
	set &operator=(set const &s);																										//OK
	/*
	 * Mutates the current set by doing a set union
	 * with s. All numbers set in s will be added to
	 * this set.
	 * 's' the set to union with
	 */
	set &operator+=(set const &s);																									//OK
	/*
	 * As +=, but constructs and returns a new set
	 */
	set operator+(set const &s) const;																							//OK
	/*
	 * Mutates the current set by doing a set removal.
	 * All numbers set in s will be removed.
	 * 's' the set to do a removal with
	 */
	set &operator-=(set const &s);																									//OK
	/*
	 * As -=, but constructs and returns a new set
	 */
	set operator-(set const &s) const;																							//OK
	/*
	 * Mutates the current set by doing a set
	 * intersection. All numbers not set in s will
	 * be removed.
	 * 's' the set to intersect with
	 */
	set &operator*=(set const &s);																									//OK
	/*
	 * As *=, but constructs and returns a new set
	 */
	set operator*(set const &s) const;																							//OK
	/*
	 * Negates the set. All numbers set will become
	 * unset, and vice versa. Constructs and returns
	 * a new set.
	 */
	set operator~() const;																												//OK
	/*
	 * Returns a reference to the given number in the
	 * set.
	 * 'i' the number to return a reference to
	 */
	bool &operator[](size_t i) { return elems[i] ; };															//OK
	/*
	 * Print out a set
	 */
	friend std::ostream &operator<<(std::ostream &out, set const &s);
	/*
	 * Print out a set's binary digits
	*/
	void printBinary();
};

#endif