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
int pathCount{0};

 int paperPath(size_t row, size_t col){
   cout << "[" << row << "," << col << "]" << endl;
   if (row == 11 && col == 11){
     return 1; // secure path to destination found
   }
   
   size_t col_limit = ((col + 3) >= (unsigned) N ? N - 1 : col + 3);
   size_t row_limit = ((row + 3) >= (unsigned) N ? N - 1 : row + 3);

   if (!map[row_limit][col]){
      return pathCount += paperPath(row + 1, col);
   }
   
   if (!map[row][col_limit]){
      return pathCount += paperPath(row, col + 1);
   }



 
  return pathCount;
 }    

