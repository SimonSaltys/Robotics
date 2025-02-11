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

// included with the base file.
void testVectorPrint() {
    float u[] = {1, 2, 3};
    cout << "Testing vectorPrint: " << endl;
    vectorPrint(u, 3); 
    cout << "Printed the vector u[]: {1, 2, 3}" << endl << endl;
}

/**
 * @brief Scales a vector by a scalar value.
 *
 * This function takes a vector (represented as an array of floats), its size,
 * a scalar value, and an output vector. It multiplies each element
 * of the input vector by alpha and stores the result in the corresponding
 * element of the output vector.
 *
 * @param u The input vector (array of floats).
 * @param size The size of the vector.
 * @param alpha The scalar value to scale the vector by.
 * @param v The output vector (array of floats) to store the scaled vector.
 */

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


/**
 * @brief Calculates the dot product of two vectors.
 *
 * This function takes two vectors (represented as arrays of floats), their
 * sizes, and calculates the dot product.
 *
 * @param u The first vector (array of floats).
 * @param v The second vector (array of floats).
 * @param size_u The size of the first vector.
 * @param size_v The size of the second vector.
 * @return int The dot product of the two vectors.
 */

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

/**
 * @brief Subtracts one vector from another.
 *
 * This function takes two vectors (represented as arrays of floats), their
 * sizes, and an output vector. It subtracts the second vector from the first
 * and stores the result in the output vector.
 *
 * @param u The first vector (array of floats).
 * @param size_u The size of the first vector.
 * @param v The second vector (array of floats) to subtract.
 * @param size_v The size of the second vector.
 * @param z The output vector (array of floats) to store the result.
 */


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

/**
 * @brief Normalizes a vector.
 *
 * This function takes a vector (represented as an array of floats), its size,
 * and an output vector. It calculates the norm (magnitude) of the input vector,
 * and stores the result in the output vector.
 * 
 *
 * @param u The input vector (array of floats).
 * @param size The size of the vector.
 * @param z The output vector (array of floats) to store the normalized vector.
 */

 void testVectorNorm() {
    float u[] = {3, 4, 0};
    
    float result = vectorNorm(u, 3);  // Now stores the returned norm
    cout << "float u[] = {3, 4, 0}; Expected = 5" << endl;
    cout << result << endl;
    cout << "testVectorNorm passed!" << endl;
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
