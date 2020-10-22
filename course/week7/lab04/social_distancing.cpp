/*
* A program that finds path to the toilet paper while keeping a 2m distance from other shoppers to practice good social distancing.
* The toilet paper is in (N􀀀1;N􀀀1), the bottom-right corner. A 1 in the map represents another shopper that must be avoid.
* The program count how many paths there are to the toilet paper, while staying 2 squares away from other shoppers.
* The program only moves down or to the right. It does not consider diagonals either moving up or moving left around shoppers.
* 
*Author: Pablo Bourbom Soares
* 
*/

#include <iostream>
using namespace std;

int const N = 12;

bool const map[N][N] = {
{ 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
{ 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
{ 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, },
{ 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, },
{ 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
};

int backTrack[N][N]{0}; // array for path tracking

// social distancing and boundaries function check
bool isSafe(size_t i, size_t j, int N){
    size_t j_s = (j - 2 > j ? 0 : j - 2); // checking boundaries
    size_t j_e = ((j + 3) >= (unsigned) N ? N : j + 3);
    size_t i_s = (i - 2 > i ? 0 : i - 2); // checking boundaries
    size_t i_e = ((i + 3) >= (unsigned) N ? N : i + 3);

    for (size_t col{j_s}; col < j_e ; col++ ){ //checking safe col
        if (map[i][col]){
          return false;
        }
    }

    for (size_t row{i_s}; row < i_e ; row++){ //checkinf safe row
        if (map[row][j]){
          return false;
        }
      }
    return true;
}

void paperPath(size_t row, size_t col, int* counter)
{

	if (row == N - 1 && col == N - 1)
	{
		*counter = *counter + 1;
		return;
	}


	backTrack[row][col] = 1;

	
	if (isSafe(row, col, N)) // checking if is safe to proceed
	{

		if (row + 1 < N && !backTrack[row + 1][col])
			paperPath(row + 1, col, counter);

		if (col + 1 < N && !backTrack[row][col + 1])
			paperPath(row, col + 1, counter);
	} 

	backTrack[row][col] = 0;
}