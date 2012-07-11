#include "../include/Matrix.h"

void loadMatrix(const char * const fileName, Matrix * const M)
{
  int i, j, rows, cols;
  FILE * inFile;
  double value;

  destructMatrix(M);

	inFile = fopen(fileName, "r");
  if(NULL == inFile)
  {
    changeColor("magenta");
    printf("=[ I can't find %s\n", fileName);
    return;
  }

	fscanf(inFile, "%i %i", &rows, &cols);
  M->rowSize = rows;
  M->colSize = cols;
  M->grid = (double *) calloc(rows * cols, sizeof(double));

  for(i = 0; i < rows; i++)
  {
    for(j = 0; j < cols; j++)
    {
      fscanf(inFile, "%lg", &value);
      setMatrixElement(M, i, j, value);
    }
  }

	fclose(inFile);
}

void writeMatrix(const char * const fileName, const Matrix * const M)
{
  int i, j, rows, cols;
  FILE * outFile;
  double value;

	outFile = fopen(fileName, "w");
  if(NULL == outFile)
  {
    changeColor("magenta");
    printf("=[ I can't find %s\n", fileName);
    return;
  }

	fprintf(outFile, "%i %i\n", M->rowSize, M->colSize);

  for(i = 0; i < M->rowSize; i++)
  {
    for(j = 0; j < M->colSize; j++)
    {
      fprintf(outFile, "%lg", getMatrixElement(M, i, j));
      if(j < M->colSize - 1)
        fprintf(outFile, " ");
    }
    fprintf(outFile, "\n");
  }

	fclose(outFile);
}
