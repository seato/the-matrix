#include "../include/Matrix.h"

void generateIdentityMatrix(Matrix * const M)
{
  size_t rowInd, colInd;
  for (rowInd = 0; rowInd < M->rowSize; rowInd++)
  {
    for (colInd = 0; colInd < M->colSize; colInd++)
    {
      if(rowInd == colInd)
        setMatrixElement(M, rowInd, colInd, 1.0);
      else
        setMatrixElement(M, rowInd, colInd, 0.0);
    }
  }
}

void generateRandomMatrix(Matrix * const M)
{
  size_t rowInd, colInd;
  int lowerBound, upperBound;

  lowerBound = -10;
  upperBound = 10;

  for (rowInd = 0; rowInd < M->rowSize; rowInd++)
  {
    for (colInd = 0; colInd < M->colSize; colInd++)
    {
      double randomValue = lowerBound + (rand() % (upperBound - lowerBound)) + 1;
      setMatrixElement(M, rowInd, colInd, randomValue);
    }
  }
}

void generateZeroMatrix(Matrix * const M)
{
  size_t rowInd, colInd;
  for (rowInd = 0; rowInd < M->rowSize; rowInd++)
    for (colInd = 0; colInd < M->colSize; colInd++)
      setMatrixElement(M, rowInd, colInd, 0.0);
}
