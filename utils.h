#ifndef UTILS_H
#define UTILS_H


using namespace std;

void vectorPrint(double* u , int rows); 

void vectorScale(double* u, int rows, double alpha , double* v); 

double vectorDotProduct(double* u, double* v, int rowsU, int rowsV);

void vectorSubtract(double* u, int rowsU, double* v, int rowsV, double* z);

double vectorNorm(double* u, int rowsU);

bool checkRows(int rowsU, int rowsV);

#endif

