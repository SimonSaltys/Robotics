#ifndef UTILS_H
#define UTILS_H


using namespace std;

void vectorPrint(float* u , int rows); 

void vectorScale(float* u, int rows, float alpha , float* v); 

int vectorDotProduct(float* u, float* v, int rowsU, int rowsV);

void vectorSubtract(float* u, int rowsU, float* v, int rowsV, float* z);

void vectorNorm(float* u, int rowsU, float* z);

bool checkRows(int rowsU, int rowsV);

#endif

