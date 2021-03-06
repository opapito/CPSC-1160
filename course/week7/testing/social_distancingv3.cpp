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



 bool isSafe(size_t, size_t, int); // isSafe prototype
 int findPath(size_t, size_t);     // findPath prototype
 

 int paperPath(){
   cout << (isSafe(1, 8, N) ? "Yes": "NO") << endl;
   size_t row_aux{0};
   int count{0};
   for (size_t col{0}; col < 1; col ++){
     for (size_t row{0}; row < 12; row++){
       //row_aux = ((row + 1) > 12 ? 11 : row + 1);
       count+=findPath(row, col);
     }
   }

   

   /*
   findPath(1, 5);
   findPath(1, 6);
   findPath(1, 7);
   findPath(1, 8);
   */
   /*
   findPath(0, 0);
   findPath(1, 0);
   findPath(1, 4);
   findPath(1, 5);
   findPath(1, 6);
   findPath(1, 7);
  */
  return count;
   }

 int findPath(size_t row, size_t col){
   int pathCount{0};
   size_t last_valid_row{0};
   size_t row_aux{0};

    //for (size_t row{row}; row < 12; row++){
     row_aux = row;
     //col = 0;
     
      while (col < 12 && row_aux < 12){
        if (!isSafe(row_aux, col, N)){
          //cout << "\nNOT SAFE [" << row_aux << "," << col << "]\n";
          if (row_aux < 11){
            row_aux++;
          } else{
            cout << "\nbreak row_aux= " << row_aux <<" \n";
            return 0; // no path found from left to right up to down
          }

          if (!((col - 1) > col)){ // checking if size_t (as unsigned integer) will NOT overflow 
            col --;                // rollback a column to keep social distance of to squares 
          }
            
        } else {
          last_valid_row = row_aux;
          cout << "[" << row_aux << "," << col << "]->"; //<< (col == 11 ? "\n|*** col = 11 ****|":"->");
          if (col < 11){
            col++;
          } else{
            row_aux++;
            if (row_aux > 11) {
              cout << endl;
            }
          }
        }
        
        if ((int) row_aux - (int) last_valid_row > 1){
          cout << "\nbreak row_aux - last_valid_row > 1 " << ((int) row_aux - (int) last_valid_row ) <<" \n";
          return 0;
        }
      }
      //cout << "row_aux = " << row_aux << " col= " << col << endl;
      if (col >= 11){
        pathCount++;
        cout << "Found path: " << pathCount << endl;
      }
    //}  // for loop

  return pathCount;

 }    


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
        // map[row][col]
        if (map[row][j]){
          return false;
        }
      }
    return true;

   }

 