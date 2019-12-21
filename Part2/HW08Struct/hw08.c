// ***
// *** You must modify this file
// ***
#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include "hw08.h"


#ifdef TEST_COUNTVECTOR
int countVector(char * filename)
{
  FILE * file_bin;
  file_bin = fopen(filename,"r");
  int count = 0;
  Vector arr;
  if (file_bin == NULL)
  {
    return -1;
  }
  while(fread(&arr,sizeof(Vector),1,file_bin) == 1)
  {
    count++;
  }
  fclose(file_bin);
  // count the number of vectors in the file and return the number
  // The input is a binary file. You must use fread.
  // You must not use fscanf(, "%d", ) 
  //
  // If fopen fails, return -1
  //
  //
  // For the mode of fopen, you may use "r" without b
  //
  return count;
}
#endif

#ifdef TEST_READVECTOR

bool readVector(char* filename, Vector * vecArr, int size)
{
  //int count = 0;
  FILE * file_vector;
  file_vector = fopen(filename,"r");
  if(file_vector == NULL)
  {
    return false;
  }
//count = fread(vecArr,sizeof(Vector),size,file_vector);
if (fread(vecArr,sizeof(Vector),size,file_vector)!= size)
  {
    return false;
  }
  fclose(file_vector);
  return true;
  // if fopen fails, return false
  // read Vectors from the file.
  // 
  //
  // if the number of integers is different from size (too
  // few or too many) return false
  // 
  // if everything is fine, fclose and return true

}
#endif

#ifdef TEST_COMPAREVECTOR
int compareVector(const void *p1, const void *p2)
{ 
  const Vector * value1 = (const Vector*)p1;
  const Vector * value2 = (const Vector*)p2;
  Vector num1 = *value1;
  Vector num2 = *value2;
  if(num1.x < num2.x)
  {
    return -1;
  }
  if (num1.x > num2.x)
  {
    return 1;
  }
  if(num1.x == num2.x)
  {
    if(num1.y < num2.y)
    {
      return -1;
    }
    if (num1.y > num2.y)
    {
      return 1;
    }
    if (num1.y == num2.y)
    {
      if(num1.z < num2.z)
      {
        return -1;
      }
      if (num1.z > num2.z)
      {
        return 1;
      }
    }
  }
  return 0;
  
  // compare the x attribute first
  // If the first vector's x is less than the second vector's x
  // return -1
  // If the first vector's x is greater than the second vector's x
  // return 1
  // If the two vectors' x is the same, compare the y attribute
  //
  // If the first vector's y is less than the second vector's y
  // return -1
  // If the first vector's y is greater than the second vector's y
  // return 1
  // If the two vectors' y is the same, compare the z attribute
  //
  // If the first vector's z is less than the second vector's z
  // return -1
  // If the first vector's z is greater than the second vector's z
  // return 1
  // If the two vectors' x, y, z are the same (pairwise), return 0
}
#endif

#ifdef TEST_WRITEVECTOR
bool writeVector(char* filename, Vector * vecArr, int size)
{
  FILE * file_vector;
  file_vector = fopen(filename,"w");
  if (file_vector == NULL)
  {
    return false;
  }
 
  //int choose = fwrite(vecArr,sizeof(Vector),size,file_vector);
  if (fwrite(vecArr,sizeof(Vector),size,file_vector) != size)
  {
    fclose(file_vector);
    return false;
  }
  fclose(file_vector);
  return true;
  // if fopen fails, return false
  // write the array to file using fwrite
  // need to check how many have been written
  // if not all are written, fclose and return false
  // 
  // fclose and return true
}
#endif

// This function is provided to you. No need to change
void printVector(Vector * vecArr, int size)
{
  int ind = 0;
  for (ind = 0; ind < size; ind ++)
    {
      printf("%6d %6d %6d\n",
	     vecArr[ind].x, vecArr[ind].y, vecArr[ind].z);
    }
}
