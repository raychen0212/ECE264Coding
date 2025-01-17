// ***
// *** You must modify this file
// ***

#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include "hw08.h"

#ifdef TEST_MAIN
int main(int argc, char * * argv)
{
  int numElem;
  // argv[1]: name of input file (binary)
  // argv[2]: name of output file (binary)
  if (argc != 3)
  {
    return EXIT_FAILURE;
  }
  numElem = countVector(argv[1]);
  if(numElem <= 0)
  {
    return EXIT_FAILURE;
  }
  Vector *vecArr;
  vecArr = malloc(sizeof(*vecArr)*numElem);
  
  readVector(argv[1],vecArr,numElem);
  bool checking = readVector(argv[1], vecArr, numElem);
  if(checking == false)
  {
    free(vecArr);
    return EXIT_FAILURE;
  }
  
  // check whether there are three arguments.
  // If not, return EXIT_FAILURE. DO NOT print anything

  // use argv[1] as the input to countVector, save the result

  // if the number of vector is 0 or negative, return EXIT_FAILURE

  // otherwise, allocate memory for an array of vectors

  // read the vectors from the file whose name is argv[1]. save the
  // results in the allocated array
  // if reading fails, release memory and return EXIT_FAILURE

#ifdef DEBUG
  printVector(vecArr, numElem);
#endif  
qsort(&vecArr[0],numElem,sizeof(Vector),compareVector);
  
  

#ifdef DEBUG
  printf("\n");
  printVector(vecArr, numElem);
#endif  
bool checking2 = writeVector(argv[2], vecArr, numElem);
if (checking2 == false) // read fail
    {
      free (vecArr);
      return EXIT_FAILURE;
    }
  // write the sorted array to the file whose name is argv[2]
  // if writing fails, release memory and return EXIT_FAILURE
writeVector(argv[2], vecArr, numElem);
  free (vecArr);
  return EXIT_SUCCESS;  

  // releave memory, return EXIT_SUCCESS
}
#endif
