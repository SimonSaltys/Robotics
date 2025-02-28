#ifndef MATRIXUTILS_H
#define MATRIXUTILS_H
using namespace std;


void matrixPrint(double* matrix, int rows, int cols);

void matrixProduct(double* a, int rows_a, int cols_a, double* b, int rows_b, int cols_b, double* c);

void matrixTimesVector(double* a, int rows, int cols, double* v, int rows_v, double*w);

void matrixTranspose(double* a, int rows, int cols, double* aTranspose);

void matrixExtractCol(double*a, int rows, int cols, int col, double* column);

void matrixBackSubstitution(double* R, int rows, int cols, double* d, double* p);

void matrixUpperTriangularInverse(double* A, int rows, int cols, double* invA);

void matrixInternalCameraParameters(double* p,int rows,int cols,double* k);

void matrixQR(double* a, int rows, int cols, double* q, double*r);

#endif
