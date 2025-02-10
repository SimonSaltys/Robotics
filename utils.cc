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

void vectorDotProduct(float* u, float* v, int rowsU, int rowsV, float* z){ 
  
}

void vectorScale(float* u, int rows, float alpha , float* v){
  for(int i=0; i<rows; i++){
    v[i]=alpha*u[i];
  }
}


void vectorSubtract(float* u, int rowsU, float* v, int rowsV, float* z){
  for(int i = 0; i<rowsU; i++)
    z[i] = u[i] - v[i];
}

