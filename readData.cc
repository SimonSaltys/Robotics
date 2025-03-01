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
void readData(string fileName, double u[], double v[], double x[], double y[], double z[], double zc[]) {
  ifstream infile(fileName);
  if (!infile.is_open()) {
      cerr << "Error: Could not open file " << fileName << endl;
      return;
  }

  string line;

  // Read the first line to extract image parameters
  getline(infile, line);
  istringstream iss(line);
  int imageWidth, imageHeight, numPoints;
  
  if (!(iss >> imageWidth >> imageHeight >> numPoints)) {
      cerr << "Error: Invalid format in header line." << endl;
      return;
  }

  cout << "Image Width: " << imageWidth << ", Image Height: " << imageHeight << ", Number of Points: " << numPoints << endl;

  for (int i = 0; i < numPoints; i++) {
      if (!getline(infile, line)) {
          cerr << "Error: Unexpected end of file while reading data." << endl;
          return;
      }

      istringstream iss(line);
      double values[6];

      for (int j = 0; j < 6; j++) {
          if (!(iss >> values[j])) {
              cerr << "Error: Invalid data on line " << i + 2 << endl;
              return;
          }
      }

      // Store values in arrays
      u[i] = values[0];
      v[i] = values[1];
      x[i] = values[2] * 25.0;
      y[i] = values[3] * 25.0;
      z[i] = values[4] * 25.0;
      zc[i] = values[5];
  }

  infile.close();
}
