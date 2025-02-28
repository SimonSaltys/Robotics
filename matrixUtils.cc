#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <ctime>
#include <string>
#include <sstream>
#include "utils.h"

using namespace std;

void matrixPrint(double* matrix, int rows, int cols) {
    printf("number of rows and cols,%d %d \n", rows, cols);
    for (int row = 0; row < rows; row++) {

        for (int col = 0; col < cols; col++) {
            printf("%6.5f ",matrix[row*cols + col]);
        }
        printf("\n");

    }
    printf("\n");
}

void matrixExtractCol(double*a, int rows, int cols, int col, double* column){
  int index;
  for(int row=0;row<rows;row++){
    index = col + row*cols;
    column[row] = a[index];
  }
}


void matrixQR(double* a, int rows, int cols, double* q, double* r) { //function needs to be finished (implement orthogonalization & normalization)
  double numeratorTemp[rows];
  double dotProduct;
  double projection[rows];
  double norm;
  double aTemp[rows];
  double qTemp[rows];

 
  for(int j = 0; j < cols; j++) {

    matrixExtractCol(a,rows, cols, j, aTemp);

    for(int row = 0; row < rows; row++) {
      numeratorTemp[row] = aTemp[row];
    }

    //first loop is fine, until we start appending to numeratorTemp
    for(int k = 0; k < j; k++) {
        matrixExtractCol(q,rows,cols,k,qTemp);

        dotProduct = vectorDotProduct(qTemp, aTemp, rows, rows);
      
        vectorScale(qTemp,rows,dotProduct,projection);
        vectorSubtract(numeratorTemp,rows,projection,rows,numeratorTemp);
      }

      norm = vectorNorm(numeratorTemp,rows);

      if (norm > 0) {

        vectorScale(numeratorTemp,rows,1/norm,numeratorTemp);
        
        for(int row=0; row<rows; row++)
          q[j+row*cols] = numeratorTemp[row];

      } else {
        printf("Error");
        exit(0);
      }
      

    }
    // Setting R matrix
    for (int currRow = 0; currRow < rows; currRow++)
      for (int currCol = 0; currCol < cols; currCol++) {
        r[currRow*cols+currCol] = 0.0;
    }

    for(int currCol = 0; currCol < cols; currCol++) {
      matrixExtractCol(a, rows, cols, currCol, aTemp);
      for(int currRow=0; currRow < rows; currRow++)

        if (currRow <= currCol){
          matrixExtractCol(q, rows, cols, currCol, qTemp);
          r[currRow*cols+currCol] = vectorDotProduct(qTemp, aTemp, rows, rows);
      }
    }
      
  }

void matrixProduct(double* a, int rows_a, int cols_a, double* b, int rows_b, int cols_b, double* c){
 int index = 0;
 int rows  = rows_a;
 int cols  = cols_b;

 if(cols_a == rows_b){
 for(int row = 0; row < rows; row++){
   for(int col = 0; col < cols; col++){
       index = row*cols + col;
       c[index] = 0.0; 
       for(int k = 0; k < cols_a; k++){
         c[index]=c[index]+a[row*cols_a + k]*b[col+k*cols_b];
       }
   }

 }

 }else{
	 printf("Can't multiply. Dimensions incorrect \n");
	 exit(0);
 }

}

void matrixTimesVector(double* a, int rows, int cols, double* v, int rows_v, double* w){
if(cols==rows_v){
   for( int row = 0; row < rows; row++){
                w[row]=0.0;
		for( int col = 0;col < cols;col++){
                   w[row]=w[row]+a[row*cols+col]*v[col];
		}
   } 
}else{
	printf(" dimensions don't match \n");
	exit(0);
}

}

void matrixTranspose(double* a, int rows, int cols, double* aTranspose){
 for( int row = 0; row < rows; row++){
		for( int col = 0;col < cols;col++){

		    aTranspose[col*rows+row] = a[row*cols+col];
		}
		 
 }
}




void matrixBackSubstitution(double* R, int rows, int cols, double* d, double* p){
//solve Rp=d for an uppertriangular matrix R
// using back substitution

  for (int j = cols-1; j > -1; j--){
        p[j]=d[j];
	for(int k = j+1; k < cols; k++){
		p[j]= p[j] - R[j*cols + k]*p[k];
	}
	p[j]=p[j]/R[j*cols+j];
  }

}

void matrixUpperTriangularInverse(double* A, int rows, int cols, double* invA){
// This code computes the inverse of a non-singular upper triangular 3x3 matrix.
if(rows !=3 || cols !=3){
	printf(" Only 3x3 full rank upper triangle matricies can be inverted with this code\n");
       	exit(0);
}

 for(int row = 0; row < rows; row++){
  for(int col= 0;col < cols; col++){
    invA[ row*cols + col]  = 0.0;
  }
 }

invA[0*cols+0]=1.0/A[0*cols+0];
invA[1*cols+1]=1.0/A[1*cols+1];
invA[2*cols+2]=1.0/A[2*cols+2];

invA[0*cols+1]=-A[0*cols+1]*invA[1*cols+1]/A[0*cols+0];
invA[1*cols+2]=-A[1*cols+2]*invA[2*cols+2]/A[1*cols+1];
invA[0*cols+2]=-( A[0*cols+1]*invA[1*cols+2] + A[0*cols+2]*invA[2*cols+2] )/A[0*cols+0];
}

void matrixInternalCameraParameters(double* p,int rows,int cols,double* k){

double pSub[9];
double r[9];
double rInv[9];
double q[9];
double qT[9];
double b[9];

// extract a 3x3 sub matrix of p
for (int row=0; row < rows; row++){
	for (int col=0; col<cols-1;col++){
            pSub[row*(cols-1)+col]=p[row*cols+col];
	}
}
printf("3x3 submatrix of p\n");
matrixPrint(pSub,3,3);

// find the inverse of pSub with QR decomposition
// Its inverse is B=RInv*QTranspose
matrixQR(pSub,3,3,q,r);
matrixTranspose(q,3,3,qT);
matrixUpperTriangularInverse(r,3,3,rInv);
matrixProduct(rInv,3,3,qT,3,3,b);

//QR decompose the matrix B
matrixQR(b,3,3,q,r);

int rows_k = rows;
int cols_k = rows_k;

int rows_r = rows;
int cols_r = rows_r;

//diagonals of calibration matirx
k[0*cols_k +0] = 1/r[0*cols_r+0];
k[1*cols_k +1] = 1/r[1*cols_r+1];
k[2*cols_k +2] = 1.0;
// off diagonals of the calibration matrix
k[0*cols_k +2] = -r[0*cols_r +2]/r[0*cols_r+0];
k[1*cols_k +2] = -r[1*cols_r +2]/r[1*cols_r+1];
}