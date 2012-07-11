#include "../include/Matrix.h"
#include "../include/Debug.h"

void setMatrixElement(Matrix * const M, const size_t rowIndex, const size_t colIndex, const double value)
{
  M->grid[(M->colSize * rowIndex) + colIndex] = value;
}

double getMatrixElement(const Matrix * const M, const size_t rowIndex, const size_t colIndex)
{
  return M->grid[(M->colSize * rowIndex) + colIndex];
}

void constructMatrix(Matrix * const M, const size_t rowSize, const size_t colSize)
{
  M->rowSize = rowSize;
  M->colSize = colSize;
  M->grid = (double *) calloc(rowSize * colSize, sizeof(double));
}

void destructMatrix(Matrix * M)
{
  free(M->grid);
}

/** multiplyMatrix
 ** takes 3 matrices (dimensions x by y, y by z, and x by z)
 ** answer to matrix multiplication overwrites the third matrix
 */
void multiplyMatrix(const Matrix * const M1, const Matrix * const M2, Matrix * const M3)
{
  if(M1->colSize != M2->rowSize)
  {
    changeColor("white");
    printf("| ");
    changeColor("red");
    printf("\tMatrixOperations.c: You can't multiply matrices of those dimensions you idiot.\n");
    return;
  }

  size_t i, j, k;
  constructMatrix(M3, M1->rowSize, M2->colSize);

  for (i = 0; i < M1->rowSize; i++)
  {
    for (k = 0; k < M2->colSize; k++)
    {
      double product = 0.0;
      for (j = 0; j < M1->colSize; j++)
        product += getMatrixElement(M1, i, j) * getMatrixElement(M2, j, k);
      setMatrixElement(M3, i, k, product);
    }
  }
}

void printMatrix(const Matrix * const M)
{
  size_t rowInd, colInd;
  printf("\n");

  for (rowInd = 0; rowInd < M->rowSize; rowInd++)
  {
    printf("|");
    for (colInd = 0; colInd < M->colSize; colInd++)
      printf(" %6.0lf", getMatrixElement(M, rowInd, colInd));
    printf(" |\n");
  }
}

int almostEqual(const double A, const double B)
{
  double absDiff = fabs(A - B);
  if (absDiff <= DBL_MIN)
    return 1;
  return 0;
}

int matrixCompare(const Matrix * const M1, const Matrix * const M2)
{
  if ((M1->rowSize != M2->rowSize) || (M1->colSize != M2->colSize))
    return 0;

  int i, elementCount;
  elementCount = M1->rowSize * M1->colSize;

  for (i = 0; i < elementCount; i++)
    if (! almostEqual(M1->grid[i], M2->grid[i]))
      return 0;

  return 1;
}
