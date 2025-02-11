#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <ctime>
#include <string>
#include <sstream>

using namespace std;
int SIZE_ERROR = -9999;
void vectorPrint(float* u , int rows){
  for(int i=0;i<rows;i++){
    printf( "%7.1f \n",u[i]);
  }
  printf("\n");

}

/*
* @brief Checks if number of rows for u and v are equal in length.
*
* @param rowsU The number of rows of the u vector.
* @param rowsV The number of rows of the v vector.
* @return if the two rows are of same length.
 */
bool checkRows(int rowsU, int rowsV){ 
  if (rowsU != rowsV) { 
  std::cerr << "Error, Vectors do not match in size!" << std::endl;
    return false;
  }
    return true;
  }

/*
* @brief Takes in vector u, finds it norm.
*
* @param u vector.
* @param rowsU the number of rows of the u vector.
* @return the norm of the vector.
*/
float vectorNorm(float* u, int rowsU) { 
    float sum = 0.0f;
    for (int i = 0; i < rowsU; i++)
        sum += u[i] * u[i];  
    return sqrt(sum);
}

/*
* @brief Calculates dot product of vector u and v
* 
* @param u Values in the u vector
* @param v Values in the v vector
* @param rowsU The number of rows of the u vector
* @param rowsV The number of rows of the v vector
* @return the dot product or error if rows are not equal
*/
int vectorDotProduct(float* u, float* v, int rowsU, int rowsV){ 
int result = 0;

  if(!checkRows(rowsU, rowsV))
  { return SIZE_ERROR; } // dont change my godamn code
  

  for(int i = 0; i < rowsU; i++)
    result += u[i] * v[i];
  return result;
  
}

void vectorScale(float* u, int rows, float alpha , float* v){
  for(int i=0; i < rows; i++){
    v[i]=alpha*u[i];
  }
}

/*
* @brief Subtracts values in vector v from vector u, then stores the result in vector z
* 
* @param u Values in the u vector
* @param v Values in the v vector
* @param rowsU The number of rows of the u vector
* @param rowsV The number of rows of the v vector
* @param z Storage vector for post-processed u and v vector
*/
int vectorSubtract(float* u, int rowsU, float* v, int rowsV, float* z){ 

  if(!checkRows(rowsU, rowsV)) { 
    return SIZE_ERROR; 
  }
  
  for(int i = 0; i < rowsU; i++)
    z[i] = u[i] - v[i];
  return 0;
}
