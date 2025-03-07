#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <ctime>
#include <string>
#include <sstream>
#include "readParams.h"
#include "readData.h"
#include "utils.h"
#include "matrixUtils.h"

using namespace std;

// This code was written by Ken Owens 2/11/2025
// to solve Ap=b using QR decomposition.
// A = mT*m is a real symmetric matrix
// and p is the camera projection matrix.
// Matrix M is composed of world calibration data
// and the vector b is composed of pixel calibration data.
// We sove A=QR which gives QRp=b and reduces to Rp=QT*b. 
// which we sove by back substitution since R is upper triagular.

int main(){

int numPoints = 0;
string inputFile;

// read the camera calibration parameters 
cout << "Enter the name of the calibration file: ";
    getline(std::cin, inputFile); // Read a line

numPoints = readParams(inputFile);

printf( "Number of Points %d \n",numPoints);

if(numPoints<12){
	printf("Not enough points. Min of 12 are needed \n");
	exit(0);
}

//define input vectors
double   u[numPoints];
double   v[numPoints];
double   x[numPoints];
double   y[numPoints];
double   z[numPoints];
double  zc[numPoints];

//read calibration data
readData(inputFile, u, v, x ,y, z, zc);

// build m matrix of world coordinates three rows at a time
// for each data point

const int rows= 3*numPoints;
const int cols = 12;

double* m = new double[rows * cols]();
double* mTranspose = new double[cols * rows]();
double* a = new double[cols * cols]();
double* c = new double[rows]();
double* b = new double[cols]();
double* d = new double[cols]();
double* q = new double[cols * cols]();
double* qT = new double[cols * cols]();
double* r = new double[cols * cols]();
double* p = new double[cols]();
double* test = new double[cols * cols]();
double* k = new double[9]();


// initialize the M matrix 
int row=0;
int col=0;
for (int i = 0; i < numPoints; i++) {
    col = 0;
    for (int j = 0; j < 3; j++) {
        printf("\nPoint %d (Before Storing): x=%f, y=%f, z=%f", i, x[i], y[i], z[i]);

        m[row * cols + col] = x[i];
        col++;
        m[row * cols + col] = y[i];
        col++;
        m[row * cols + col] = z[i];
        col++;
        m[row * cols + col] = 1.0;
        col++;

        // Debugging output
        printf("\nRow %d: ", row);
        for (int k = 0; k < cols; k++) {
            printf(" %f", m[row * cols + k]);
        }
        printf("\n");

        row = row + 1;
    }
}



// compute the right hand side vector b
row=0;
for(int i=0;i<numPoints;i++){
 c[row]=u[i]*zc[i];
 row++;
 c[row]=v[i]*zc[i];
 row++;
 c[row]=zc[i];
 row++; 
}

printf("M matrix \n");
matrixPrint(m,rows,cols);

printf("c right hand side vector \n");
vectorPrint(c,rows);
cout << "First Transpose" << endl;

double backM[rows*cols];
//compute m transpose mT
matrixTranspose(m,rows,cols,mTranspose);
// cout << "Second Transpose" << endl;
// matrixTranspose(mTranspose, cols, rows, backM);
// matrixPrint(backM,rows, cols);





// compute matrix a = mT*m
matrixProduct(mTranspose,cols,rows,m,rows,cols,a);
printf("Matrix A \n");
matrixPrint(a,cols,cols);


// compute QR decomposition of matrix A
matrixQR(a,cols,cols,q,r);

printf("Q matrix \n");
matrixPrint(q,cols,cols);


double* qTranspose = new double[cols * cols]();
double* result = new double[cols * cols]();

matrixTranspose(q,cols,cols,qTranspose);
matrixProduct(q,cols,cols,qTranspose,cols,cols,result);
matrixPrint(result,cols,cols);


printf("R matrix \n");
matrixPrint(r,cols,cols);

printf("QR  This must equal matrix A \n");
matrixProduct(q,cols,cols,r,cols,cols,test);
matrixPrint(test,cols,cols);

//compute the transpose of q
matrixTranspose(q,cols,cols,qT);

// check qT*q should equal the identity
printf("q*qT should be a 12x12 identity matrix \n");
matrixProduct(qT,cols,cols,q,cols,cols,test);
matrixPrint(test,cols,cols);

// compute the righthand side vector b=mT*c
matrixTimesVector(mTranspose,cols,rows,c,rows,b);
printf("b=mT*c should have 12 rows \n");
vectorPrint(b,cols);

// compute the righthand side vector d=qT*b
matrixTimesVector(qT,cols,cols,b,cols,d);

// compute the projection matrix with back substitution
matrixBackSubstitution(r,cols,cols,d,p);
printf("projection matrix \n");
matrixPrint(p,3,4);

matrixInternalCameraParameters(p,3,4,k);
printf("calibration matrix \n");
matrixPrint(k,3,3);

delete[] m;
delete[] mTranspose;
delete[] a;
delete[] c;
delete[] b;
delete[] d;
delete[] q;
delete[] qT;
delete[] r;
delete[] p;
delete[] test;
delete[] k;



return 0;

}
