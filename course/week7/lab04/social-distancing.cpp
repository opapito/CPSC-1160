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

 bool isSafe(size_t, size_t, int);

 int paperPath(){
   size_t row_aux{0},col{0};
   int pathCount{0};
    for (size_t row{0}; row < 12; row++){
     row_aux = row;
     col = 0;
      while (col < 12 || row_aux < 12){
        if (!isSafe(row, col, N)){
          if (row_aux < 11){
            row_aux++;
          } else{
            cout << "break";
            break; // no path found from left to right up to down
          }
          if (col == 11){
            row_aux++;
          }
        }
        cout << "[" << col << "," << row << "]->";
        col++;
      }
      if (row_aux == 11){
        pathCount++;
        cout << endl;
      }
    }

  return pathCount;
   }

 

 bool isSafe(size_t i, size_t j, int N){
    size_t j_s = (j - 3 > j ? 0 : j - 3); // checking boundaries
    size_t j_e = ((j + 3) >= (unsigned) N ? N : j + 3);
    size_t i_s = (i - 3 > i ? 0 : i - 3); // checking boundaries
    size_t i_e = ((i + 3) >= (unsigned) N ? N : i + 3);

    for (size_t col{j_s}; col < j_e ; col++ ){ //checking safe col
        if (map[i][col]){
          return false;
        }
    }

    for (size_t row{i_s}; row < i_e ; row++){ //checkinf safe row
        // map[row][col]
        if (map[row][j]){
          return false;
        }
      }
    return true;

   }

 