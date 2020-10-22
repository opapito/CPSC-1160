#include <iostream>
#include <cstring>
using namespace std;
int const N = 12;
int pathCounter{0};

int map[N][N] = {
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


void findPath(int row, int col, int backTrack[N][N])
{
  /*
  if (!(isSafe(row,col,N))){
  cout << "[" << row << "," << col << "]" << endl;
  }
 */
	if (row == N - 1 && col == N - 1)
	{
		pathCounter++;
		return;
	}

	// mark current cell as backTrack
	backTrack[row][col] = 1;

	// if current cell is a valid and open cell,
	
	if (isSafe(row, col, N))
	{
		// go down (row, col) --> (row + 1, col)
		if (row + 1 < N && !backTrack[row + 1][col])
			findPath(row + 1, col, backTrack);

		// go up (row, col) --> (row - 1, col)
		//if (row - 1 >= 0 && !backTrack[row - 1][col])
		//	findPath(map, row - 1, col, backTrack, pathCounter);

		// go right (row, col) --> (row, col + 1)
		if (col + 1 < N && !backTrack[row][col + 1])
			findPath(row, col + 1, backTrack);

		// go left (row, col) --> (row, col - 1)
		//if (col - 1 >= 0 && !backTrack[row][col - 1])
		//	findPath(map, row, col - 1, backTrack, pathCounter);
	} 

	// backtrack from current cell and remove it from current path
	backTrack[row][col] = 0;
}

int main()
{
/*
	int map[N][N] =
	{
		{ 1, 1, 1, 1 },
		{ 1, 1, 0, 1 },
		{ 0, 1, 0, 1 },
		{ 1, 1, 1, 1 }
	};
*/
/*	
  int map[N][N] =
	{
		{ 0, 0, 0, 0 },
		{ 0, 0, 1, 0 },
		{ 1, 0, 1, 0 },
		{ 0, 0, 0, 0 }
  };
*/
/*
int map[N][N] = {
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
*/
	// stores number of unique paths from source to destination
	

	// 2D matrirow to keep track of cells involved in current path
	int backTrack[N][N]{0};
	
	findPath(0, 0, backTrack);

	cout << "Total number of unique paths are " << pathCounter << endl;

	return 0;
}