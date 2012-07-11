#include<stdlib.h>
#include<stdio.h>
#include<stddef.h>
#include<math.h>
#include<float.h>

#ifndef _MAIN_H
#define _MAIN_H

struct Matrix_t
{
  size_t rowSize;
  size_t colSize;
  double * grid;
};

typedef struct Matrix_t Matrix;

/* MatrixOperations.c */
void setMatrixElement(Matrix * const M, const size_t rowIndex, const size_t colIndex, const double value);
double getMatrixElement(const Matrix * const M, const size_t rowIndex, const size_t colIndex);
void constructMatrix(Matrix * const M, const size_t rowSize, const size_t colSize);
void destructMatrix(Matrix * M);
void multiplyMatrix(const Matrix * const M1, const Matrix * const M2, Matrix * const M3);
void printMatrix(const Matrix * const M);
int almostEqual(const double A, const double B);
int matrixCompare(const Matrix * const M1, const Matrix * const M2);

/* MatrixGeneration.c */
void generateIdentityMatrix(Matrix * const M);
void generateRandomMatrix(Matrix * const M);
void generateZeroMatrix(Matrix * const M);

/* FileIO.c */
void loadMatrix(const char * const fileName, Matrix * const M);
void writeMatrix(const char * const fileName, const Matrix * const M);

/* test_Matrix.c */
void runTests();

#endif
