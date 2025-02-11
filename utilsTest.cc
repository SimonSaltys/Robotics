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
#include "utils.h"

using namespace std;

void testVectorPrint() {
    float u[] = {1, 2, 3};
    cout << "Testing vectorPrint: " << endl;
    vectorPrint(u, 3); 
    cout << "Printed the vector u[]: {1, 2, 3}" << endl << endl;
}

void testVectorScale() {
    float u[] = {1, 2, 3};
    float v[3];
    cout << "Testing vectorScale with vector {1, 2, 3} with alpha = 2.0: " << endl;
    vectorScale(u, 3, 2.0, v);
    
    cout << "Scaled vector v[] = {";
    for (int i = 0; i < 3; ++i) {
        cout << v[i] << " ";
    }
    cout << "}" << endl;

    assert(v[0] == 2);
    assert(v[1] == 4);
    assert(v[2] == 6);
    
    cout << "testVectorScale passed!" << endl << endl;
}

void testVectorDotProduct() {
    float u[] = {1, 2, 3};
    float v[] = {4, 5, 6};
    
    cout << "Testing vectorDotProduct: " << endl;
    cout << "u[] = {1, 2, 3}, v[] = {4, 5, 6}" << endl;
    int result = vectorDotProduct(u, v, 3, 3);
    
    int expectedResult = (1 * 4 + 2 * 5 + 3 * 6); // Expected: 32
    cout << "Expected result: " << expectedResult << endl;
    cout << "Actual result: " << result << endl;
    
    assert(result == expectedResult); 
    
    cout << "testVectorDotProduct passed!" << endl << endl;
}

void testVectorSubtract() {
    float u[] = {5, 10, 15};
    float v[] = {3, 6, 9};
    float z[3];

    cout << "Testing vectorSubtract: " << endl;
    cout << "u[] = {5, 10, 15} v[] = {3, 6, 9}" << endl;
    vectorSubtract(u, 3, v, 3, z);
    
    cout << "Resulting vector z[] = {";
    for (int i = 0; i < 3; ++i) {
        cout << z[i] << " ";
    }
    cout << "}" << endl;

    assert(z[0] == 2);
    assert(z[1] == 4);
    assert(z[2] == 6);
    
    cout << "testVectorSubtract passed!" << endl << endl;
}

void testVectorNorm() {
    float u[] = {3, 4, 0};
    float z[3];

    cout << "Testing vectorNorm: " << endl;
    vectorNorm(u, 3, z);
    
    float expectedNorm = sqrt(3 * 3 + 4 * 4 + 0 * 0); // Expected norm: 5
    cout << "Expected norm: " << expectedNorm << endl;
    cout << "Expected normalized values: {";
    cout << (3.0 / expectedNorm) << " ";
    cout << (4.0 / expectedNorm) << " ";
    cout << (0.0 / expectedNorm) << "}" << endl;

    cout << "Actual normalized values: {";
    cout << z[0] << " ";
    cout << z[1] << " ";
    cout << z[2] << "}" << endl;
    
    assert(abs(z[0] - (3.0 / expectedNorm)) < 0.0001);
    assert(abs(z[1] - (4.0 / expectedNorm)) < 0.0001);
    assert(abs(z[2] - (0.0 / expectedNorm)) < 0.0001);
    
    cout << "testVectorNorm passed!" << endl << endl;
}

int main() {
    cout << "Starting tests..." << endl;
    testVectorPrint();    
    testVectorScale();    
    testVectorDotProduct();
    testVectorSubtract();
    testVectorNorm();
    
    cout << "All tests passed!" << endl;
    return 0;
}
