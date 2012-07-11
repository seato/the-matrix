/********************************************************************************/
/******************************  Matrix.c  **************************************/
/********************************************************************************/
// NOTES:
//                    Accepted Flags         Description
//                    test                   run unit tests
//
/********************************************************************************/
/********************************************************************************/
/********************************************************************************/

#include <time.h>
#include "../include/Matrix.h"

int main(int argc, char * argv[])
{
  // Random Seed
  unsigned int iseed = (unsigned int)time(NULL);
  srand (iseed);

  if(argc > 1)
  {
    if(strcmp(argv[1], "test") == 0)
      runTests();
    else
      printf("Matrix.c: %s ain't an accepted flag you dunce.", argv[1]);

    return 0;
  }

  FILE * inFile;
  FILE * outFile;
  double * pM1;

  Matrix M = {0, 0, NULL};

  changeColor("white");
  printf("\nIdentity");
  constructMatrix(&M, 3, 3);
  generateIdentityMatrix(&M);
  printMatrix(&M);

  changeColor("black");
  printf("\nZero");
  generateZeroMatrix(&M);
  printMatrix(&M);

  changeColor("magenta");
  printf("\nRandom");
  generateRandomMatrix(&M);
  printMatrix(&M);

  destructMatrix(&M);

  return 0;
}
