#include "../include/Matrix.h"
#include "../include/Debug.h"

void failOn(int cond, int * testsPassed)
{
  changeColor("white");
  printf("| ");
  if (cond)
  {
    changeColor("green");
    (* testsPassed)++;
    printf("O\n");
  }
  else
  {
    changeColor("red");
    printf("X\n");
  }
}

void runTests()
{
// Initialize Matrices
  Matrix m1 = {0, 0, NULL};
  Matrix m2 = {0, 0, NULL};
  Matrix m3 = {0, 0, NULL};
  Matrix expectedResult = {0, 0, NULL};

  int testsPassed = 0;
  int testCount = 0;
  constructMatrix(&m1, 3, 3);
  constructMatrix(&m2, 3, 3);
  constructMatrix(&expectedResult, 3, 3);

  changeColor("white");
  printf("\n");
  printf("***********************\n");
  printf("|Running unit tests...|\n");
  printf("***********************\n");

// T1: Zero matrix multiplication
  testCount++;

  generateZeroMatrix(&m1);
  generateZeroMatrix(&m2);
  multiplyMatrix(&m1, &m2, &m3);
  generateZeroMatrix(&expectedResult);
  failOn(matrixCompare(&m3, &expectedResult), &testsPassed);

// T2: Identity matrix multiplication
  testCount++;
  generateIdentityMatrix(&m1);
  generateIdentityMatrix(&m2);
  multiplyMatrix(&m1, &m2, &m3);
  generateIdentityMatrix(&expectedResult);
  failOn(matrixCompare(&m3, &expectedResult), &testsPassed);

// T3: Identity x Zero matrix multiplication
  testCount++;
  generateIdentityMatrix(&m1);
  generateZeroMatrix(&m2);
  multiplyMatrix(&m1, &m2, &m3);
  generateZeroMatrix(&expectedResult);
  failOn(matrixCompare(&m3, &expectedResult), &testsPassed);

// T4: Zero x Identity matrix multiplication
  testCount++;
  generateZeroMatrix(&m1);
  generateIdentityMatrix(&m2);
  multiplyMatrix(&m1, &m2, &m3);
  generateZeroMatrix(&expectedResult);
  failOn(matrixCompare(&m3, &expectedResult), &testsPassed);

// T5: Zero x Random matrix multiplication
  testCount++;
  generateZeroMatrix(&m1);
  generateRandomMatrix(&m2);
  multiplyMatrix(&m1, &m2, &m3);
  generateZeroMatrix(&expectedResult);
  failOn(matrixCompare(&m3, &expectedResult), &testsPassed);

// T6: Random x Zero matrix multiplication
  testCount++;
  generateRandomMatrix(&m1);
  generateZeroMatrix(&m2);
  multiplyMatrix(&m1, &m2, &m3);
  generateZeroMatrix(&expectedResult);
  failOn(matrixCompare(&m3, &expectedResult), &testsPassed);

// T7: Identity x Random matrix multiplication
  testCount++;
  generateIdentityMatrix(&m1);
  generateRandomMatrix(&m2);
  multiplyMatrix(&m1, &m2, &m3);
  failOn(matrixCompare(&m3, &m2), &testsPassed);

// T8: Random x Identity matrix multiplication
  testCount++;
  generateRandomMatrix(&m1);
  generateIdentityMatrix(&m2);
  multiplyMatrix(&m1, &m2, &m3);
  failOn(matrixCompare(&m1, &m3), &testsPassed);

// T9: Loaded matrices with a precomputed solution
  testCount++;
  loadMatrix("inputs/m1.txt", &m1);
  loadMatrix("inputs/m2.txt", &m2);
  loadMatrix("inputs/solution.txt", &expectedResult);
  multiplyMatrix(&m1, &m2, &m3);
  failOn(matrixCompare(&m3, &expectedResult), &testsPassed);

// T10: Matrices written to file correctly
  testCount++;
  constructMatrix(&m1, 5, 5);
  generateRandomMatrix(&m1);
  writeMatrix("outputs/m1_random.txt", &m1);
  loadMatrix("outputs/m1_random.txt", &m2);
  failOn(matrixCompare(&m1, &m2), &testsPassed);


// T11: Matrices can't be multiplied with bad dimensions
  testCount++;
  constructMatrix(&m1, 3, 3);
  constructMatrix(&m2, 5, 5);
  constructMatrix(&m3, 4, 4);
  constructMatrix(&expectedResult, 4, 4);
  generateZeroMatrix(&m1);
  generateRandomMatrix(&m2);
  generateIdentityMatrix(&m3);
  generateIdentityMatrix(&expectedResult);
  multiplyMatrix(&m1, &m2, &m3);
  changeColor("white");
  printf("|");
  changeColor("blue");
  printf("\tDon't worry, I was shooting for this error ;]\n");

  failOn(matrixCompare(&m3, &expectedResult), &testsPassed);

// End of test procedures
  changeColor("white");
  printf("*********************\n");
  printf("|Passed %2i/%2i tests.|\n", testsPassed, testCount);
  printf("*********************\n");

  destructMatrix(&m1);
  destructMatrix(&m2);
  destructMatrix(&m3);
  destructMatrix(&expectedResult);
}
