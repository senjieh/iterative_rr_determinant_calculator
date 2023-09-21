#include <iostream>
using namespace std;

int main() {
   int matrix_size;
   cin >> matrix_size;

   // allocate memory for the matrix
   double **matrix = new double*[matrix_size];
   for (int row = 0; row < matrix_size; row++) {
      matrix[row] = new double[matrix_size];
   }

   for (int row = 0; row < matrix_size; row++) {
      for (int col = 0; col < matrix_size; col++) {
         cin >> matrix[row][col];
      }
   }

   for (int i = 0; i < matrix_size; i++) {

      // for each diagonal matrix value
      if (matrix[i][i] != 0){

         // for each row below the diagonal entry
         for (int v = i + 1; v < matrix_size; v++) {

            if ( matrix[v][i] == 0 ){
               continue;
            }
            
            // add multiple diagonal entry row to the subsequent rows
            double multiple = matrix[v][i]/matrix[i][i];

            // for each remaining number in the row mulitply by mutliple
            for (int r = i; r < matrix_size; r++){
               matrix[v][r] = matrix[v][r] - ( matrix[i][r] * multiple);
            }

         }
      }
      else {
         // loop through the remaining column to see if any values are not == 0

         for (int c = i; c < matrix_size; c++)
         {
            if (matrix[c][i] != 0 ){
               
              // swap the row
               for (int s = i; s < matrix_size; s++)
               {
                  int temp = matrix[c][s];
                  matrix[c][s] = matrix[i][s];
                  matrix[i][s] = temp;
               }
               break;
            }
         }

         
         // otherwise return 0
      }

   }

   double determinant = 1;
   for (int i = 0; i < matrix_size; i++) {
      determinant = determinant * matrix[i][i];
   }

   cout << determinant;

   // free memory
   for (int row = 0; row < matrix_size; row++) {
      delete[] matrix[row];
   }
   delete[] matrix;

   return 0;
}

