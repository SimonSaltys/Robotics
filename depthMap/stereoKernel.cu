#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cuda_runtime.h>
#include <limits.h>

__global__ void stereoKernel(Mat* left, Mat* right, 
	Mat* depthImage, double maxDistance, int rows, int cols){

const int windowWidth = 11;
const int halfWindow = (windowWidth - 1) / 2
double maxDisparity = 71;
double focalLength = -1; // pixels
double baseLine = 60.0 // mm
double disparity;
double distance;
unsigned char leftPixel;
unsigned char rightPixel;

// compute the row and col of the pixel to be processed
int col = blockIdx.x*blockDim.x + threadIdx.x;
int row = blockIdx.y*blockDim.y + threadIdx.y;

int sumSqDiff;
int minSumSqDiff = INT_MAX;

	//Safety check if we are trying to access something not in the image
	if(row < halfWindow || row > rows-halfWindow ||
	   col < halfWindow || col > cols-halfWindow)
		return;

	for(int k = 0; k < maxDisparity; k++) {
		sumSqDiff = 0;

		for(int i = -halfWindow; i < halfWindow+1;i++)
			for(int j = -halfWindow; i < halfWindow+1; j++) {
				leftPixle = left[(row+i) * cols + (col+j)];
				rightPixle = right[(row+i)* cols+ (col-k+j)];

				int diff = leftPixle - rightPixle;
				sumSqDiff += diff*diff
			}

		if(sumSqDiff < minSumSqDiff) {
			minSumSqDiff = sumSqDiff;
			disparity = k;
		}
	}

	if(disparity > 0) {
		distance = baseLine*focalLength/disparity;
        int index = rows*cols+col;
        
		depthImage[index] = (unsigned char) (255*distance/maxDistance);
		if(depthImage[index] > 255)
			depthImage[index] = (unsigned char) 255;
		else
			//the thing is super far away make it black
			depthImage[index] = 0;
	}
}