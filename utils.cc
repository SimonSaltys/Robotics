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

void vectorNorm(float* u, int rowsU, float* z){
  float sum = 0;
  float scalar = 0;
  
  for (int i = 0; i <= rowsU; i++)
    sum += pow(u[i]);
  scalar = sqrt(sum);
  for (int j = 0; j<=rowsU; j++)
    z[j] = (u[j] / scalar);
    
}

int vectorDotProduct(float* u, float* v, int rowsU, int rowsV){ 
int result = 0;

  if(!checkRows(rowsU, rowsV))
  { return SIZE_ERROR; } // dont change my godamn code
  

  for(int i = 0; i <= rowsU; i++)
    result += u[i] * v[i];
  return result;
  
}

void vectorScale(float* u, int rows, float alpha , float* v){
  for(int i=0; i<rows; i++){
    v[i]=alpha*u[i];
  }
}


void vectorSubtract(float* u, int rowsU, float* v, int rowsV, float* z){

  if(!checkRows(rowsU, rowsV))
  { return SIZE_ERROR; }
  
  for(int i = 0; i<rowsU; i++)
    z[i] = u[i] - v[i];
}

bool checkRows(int rowsU, int rowsV){
if (rowsU != rowsV) {
std::cerr << "Error, Vectors do not match in size!" << std::endl;
  return false;
}
  return true;
}
