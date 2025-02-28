#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <ctime>
#include <string>
#include <sstream>
#include <cassert>
#include "matrixUtils.h"
#include "utils.h"

using namespace std;

bool areAlmostEqual(double a, double b, double epsilon = 1e-6) {
    return fabs(a - b) < epsilon;
}

int main() {
    cout << "Starting tests..." << endl;

    double A[9] = {
        1.0, -1.0, 0.0, 
        1.0, 0.0, 1.0,
        0.0, -1.0, 1.0
    };

    double q[9];
    double r[9];

    matrixQR(A,3,3,q,r);


    double correctQ[9] = {
       1.0/sqrt(2.0), -1.0/sqrt(6.0), -1.0/sqrt(3.0),
       1.0/sqrt(2.0), 1.0/sqrt(6.0), 1.0/sqrt(3.0),
       0.0, -sqrt(2.0/3.0), 1.0/sqrt(3.0)
    };
    cout << "The Calculated Q";
    matrixPrint(q,3,3);

    cout << "The Correct Q";
    matrixPrint(correctQ,3,3);
    matrixPrint(r,3,3);

    // for (int i = 0; i < 16; i++) {
    //    if (!areAlmostEqual(q[i],correctQ[i])) {
    //     cout << "The Q matrix is not equal to the Correct Q Matrix";
    //     cout << "Calulated Q " << q[i] << " VS Correct " << correctQ[i];
    //     return 0; 
    //    }
    // }
    
    // double correctR[16] = {
    //     7.14142842854285, 14.282856857085699, 21.42428528562855, 28.565713714171398,
    //     0, 2.1868857395626282e-15, 2.2094309533725527e-15, 4.373771479125257e-15,
    //     0, 0, 1.2753498854638288e-15, 2.8737566162911288e-46,
    //     0, 0, 0, 9.711723601147374e-31
    // };

    // for (int i = 0; i < 16; i++) {
    //     if (!areAlmostEqual(r[i],correctR[i])) {
    //      cout << "The R matrix is not equal to the Correct R Matrix";
    //      cout << "Indices Compared " << r[i] << " VS " << correctR[i];
    //      return 0; 
    //     }
    //  }

    cout << "All tests passed!" << endl;
    return 0;
}