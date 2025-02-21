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
#include <matrixUtils.h>
#include "utils.h"

using namespace std;

bool areAlmostEqual(double a, double b, double epsilon = 1e-6) {
    return fabs(a - b) < epsilon;
}

int main() {
    cout << "Starting tests..." << endl;

    float A[16] = {
        3, 6, 9, 12,
        4, 8, 12, 16,
        5, 10, 15, 20,
        1, 2, 3, 4
    };

    float q[16];
    float r[16];

    matrixQR(A,3,3,q,r);

    float correctQ[16] = {
        0.42008402520840293, 0.5601120336112039, 0.7001400420140048, 0.14002800840280097,
        0.40613846605344767, 0.40613846605344767, 0.8122769321068953, 0.10153461651336192,
       -0.7035989954453835, 0.6892398322730285, -0.014359163172355022, 0.17230995806825714,
       -0.40613846605344744, -0.40613846605344783, -0.8122769321068953, -0.10153461651336196
    };

    for (int i = 0; i < 16; i++) {
       if (!areAlmostEqual(q[i],correctQ[i])) {
        cout << "The Q matrix is not equal to the Correct Q Matrix";
        cout << "Indices Compared " << q[i] << " VS " << correctQ[i];
        return 0; 
       }
    }
    

    double correctR[16] = {
        7.14142842854285, 14.282856857085699, 21.42428528562855, 28.565713714171398,
        0, 2.1868857395626282e-15, 2.2094309533725527e-15, 4.373771479125257e-15,
        0, 0, 1.2753498854638288e-15, 2.8737566162911288e-46,
        0, 0, 0, 9.711723601147374e-31
    };

    for (int i = 0; i < 16; i++) {
        if (!areAlmostEqual(r[i],correctR[i])) {
         cout << "The R matrix is not equal to the Correct R Matrix";
         cout << "Indices Compared " << r[i] << " VS " << correctR[i];
         return 0; 
        }
     }

    cout << "All tests passed!" << endl;
    return 0;
}