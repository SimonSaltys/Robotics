#ifndef UTILS_H
#define UTILS_H


using namespace std;

void vectorPrint(float* u , int rows); 

void vectorScale(float* u, int rows, float alpha , float* v); 

void vectorDotProduct();

void vectorSubtract(const float* u, const float* v, const float* z);

void vectorNorm(float* u, float* v, float* z, int rows);

#endif

